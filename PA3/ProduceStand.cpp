//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#include "ProduceStand.h"
using namespace std;

//Initialization list for the counters and sales data
double ProduceStand::dailySales = 0;
double ProduceStand::dailySalesTax = 0;
int ProduceStand::receiptNum = 0;

//Default constructor
ProduceStand::ProduceStand(){
	//Initialize each member of ProduceStand to 0 if it's a number, and an empty
	//string for string members.
	this->name = "";
	this->weight=0;
	this->pricePerlb=0;
	this->pricePerEach=0;
	this->howMany=0;
	this->eachSale=0;
	this->eachSalesTax=0;
	this->dailySales=0;
	this->dailySalesTax=0;
	this->standName="";
	this->receiptNum=0;
}

//Regular constructor
ProduceStand::ProduceStand(ifstream& in, ofstream& out){
	//Since we pass in the input file, we need to read the name, weight, price
	//per pound, unit price, quantity, and new customer opt in/out character from
	//the file directly into the class declaration.
	in>>name;
	in>>weight;
	in>>pricePerlb;
	in>>pricePerEach;
	in>>howMany;

	string newCustomer;
	in>>newCustomer;

	//If the customer opts into the program, get their personal information.
	if(newCustomer=="y"){
		//Declare the data that will hold their personal information
		string last, first, email, street, city, state;
		int house, zip, month, day, year;
		//Scan in this information from the file.
		in>>last;		//Last name
		in>>first;	//First name
		in>>email;	//email
		in>>house;	//House number
		in>>street;	//street
		in>>city;		//City name
		in>>state;	//State
		in>>zip;		//Zip code
		in>>month;	//Birth month
		in>>day;		//Birth day
		in>>year;		//Birth getYear
		//Call the setter for the Person class to store this data in the class.
		customer.setPerson(last, first, email, house, street, city, state, zip,
											 month, day, year);
		//Print this info to the customer output file.
		customer.printInfo(out);

	}

	//Set the produce stand name, and increment the number of receipts.
	standName="Starfruit Platinum";
	receiptNum++;
}

//getter for the Stand name that returns the name of the stand.
string ProduceStand::getStandName(){
	return standName;
}

//getter for the receipt number that returns receiptNum.
int ProduceStand::getReceiptNum(){
	return receiptNum;
}

//Prints the total sales information to the output sales file
void ProduceStand::printInfo(ofstream& out){
	//Print the daily sales
	out<<"Total sales for the day: $"<<dailySales<<endl;
	//Print the sales tax for the day
	out<<"Total sales tax collected for the day: $"<<dailySalesTax<<endl;
}

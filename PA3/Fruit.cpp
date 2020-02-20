//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#include "Fruit.h"
using namespace std;

//Initiaization list for variables
int Fruit::fruitCount=0;
double Fruit::totalFruitSales=0;
const double Fruit::taxRate=0.08;

//Default constructor that initializes both variables to 0.
Fruit::Fruit(){
	this->totalFruitSales=0.0;
	this->fruitCount=0;
}

//Regular constructor that calls the regular constructor for ProduceStand.
Fruit::Fruit(ifstream& in, ofstream& out):ProduceStand(in, out){
	fruitCount++;
}

//Function that calculates the tax for each sale.
void Fruit::calculateTax(ofstream& out){
	eachSalesTax=eachSale*taxRate;
}

//Function that calculates the value of each sale.
void Fruit::calculateSale(ofstream& out){
	//If the sale was based on weight, calculate the sale based on price per lb.
	if(weight>0){
		eachSale=weight*pricePerlb;
	}
	//otherwise, calculate it based on quantity.
	else{
		eachSale=howMany*pricePerEach;
	}
}

//Print the receipt information.
void Fruit::printReceipt(ofstream& out){
	//Calculate the sale value for this transaction.
	calculateSale(out);
	//Calculate the tax for this individual sale.
	calculateTax(out);

	//Divider
	for (int i=0;i<47;i++){
		out<<"*";
	}
	out<<endl;

	//Print the stand name, location, and receipt number
	out<<ProduceStand::getStandName()<<endl;
	out<<"Chapin, SC"<<endl;
	out<<"Receipt Number:"<<ProduceStand::getReceiptNum()<<endl;

	//Divider
	for(int j=0;j<47;j++){
		out<<"*";
	}
	out<<endl<<endl;

	//Print out the sales information: sale amount, sales tax, and the total
	out<<"Sales:"<<endl;
	out<<name<<setw(47-name.length())<<right;
	out<<setprecision(2)<<eachSale<<endl;
	out<<"\tSales Tax:"<<setw(33)<<fixed<<setprecision(2)<<eachSalesTax;
	out<<endl;
	out<<"\tTotal:"<<setw(37)<<fixed<<setprecision(2);
	out<<(eachSalesTax+eachSale)<<endl<<endl;

	//Divider
	for(int k=0;k<47;k++){
		out<<"*";
	}
	out<<endl<<endl;

	//Increase each total by the most recent transaction amount.
	totalFruitSales += eachSale;
	dailySales += eachSale;
	dailySalesTax += eachSalesTax;
}

//Function that prints out the whole day's information: number of transactions
//and total sales amounts.
void Fruit::printInfo(ofstream& out){
	out<<"Number of fruit sales for the day: "<<fruitCount<<endl;
	out<<"With a total fruit sales of $"<<totalFruitSales<<" for the day.";
	out<<endl;
}

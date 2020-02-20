//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019

#include "Vegetable.h"
using namespace std;

//Initialization list for varaibles
int Vegetable::vegtCount=0;
double Vegetable::totalVegtSales=0;
const double Vegetable::taxRate=0.08;

//Default constructor that initializes both variables to 0.
Vegetable::Vegetable(){
	this->totalVegtSales=0.0;
	this->vegtCount=0;
}

//Regular constructor that calls the regular constructor for ProduceStand.
Vegetable::Vegetable(ifstream& in, ofstream& out):ProduceStand(in, out){
	vegtCount++;
}

//Function that calculates thte tax for each sale.
void Vegetable::calculateTax(ofstream& out){
	eachSalesTax=eachSale*taxRate;
}

//Function that calculates the value of each sale.
void Vegetable::calculateSale(ofstream& out){
	//If the sale was based on weight, calculate the sale based on price per lb.
	if(weight>0){
		eachSale=weight*pricePerlb;
	}
	//Otherwise, calculate it based on quantity.
	else{
		eachSale=howMany*pricePerEach;
	}
}

//print the receipt information.
void Vegetable::printReceipt(ofstream& out){
	//Calculate the sale value for this transaction.
	calculateSale(out);
	//Calculate the tax for this individual sale.
	calculateTax(out);

	//Divider
	for(int i=0;i<47;i++){
		out<<"*";
	}
	out<<endl;

	out<<ProduceStand::getStandName()<<endl;
	out<<"Chapin, SC"<<endl;
	out<<"Receipt Number:"<<ProduceStand::getReceiptNum()<<endl;

	//Divider
	for(int j=0;j<47;j++){
		out<<"*";
	}
	out<<endl<<endl;

	//Print out the sales information: sale amount, sales tax, and the total.
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
	totalVegtSales += eachSale;
	dailySales += eachSale;
	dailySalesTax += eachSalesTax;
}

//Function that prints out the whole day's information: number of transactions
//and total sales amounts.
void Vegetable::printInfo(ofstream& out){
	out<<"Number of vegetable sales for the day: "<<vegtCount<<endl;
	out<<"With a total fruit sales of $"<<totalVegtSales<<" for the day.";
	out<<endl;
}

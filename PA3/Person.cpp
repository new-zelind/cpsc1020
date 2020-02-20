//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#include "Person.h"
using namespace std;

//Default constructor
Person::Person(){
	//Initialize each string to an empty string.
	this->last="";
	this->first="";
	this->email="";
}

//getter that returns an entire instance of Address.
Address Person::getAddress(){
	return address;
}

//Setter for the person class. passes in all the personal information.
void Person::setPerson(string last, string first, string email, int house,
											 string street, string city, string state, int zip,
											 int month, int day, int year){
	//Initialize the full name and email in the person class.
	this->last = last;
	this->first = first;
	this->email = email;
	//Send the house number, street name, city, state, and zip code to the
	//Address setter.
	address.setAddress(house, street, city, state, zip);
	//Send the month, day, and year to the Date setter.
	bday.setDate(month, day, year);
}

//Person getter that returns an entire Date class.
Date Person::getDate(){
	return bday;
}

//Function that prints the personal information to the customer output file.
void Person::printInfo(ofstream& out){
	//Print the last and first name.
	out<<first<<", "<<last<<endl;
	//Calls the printAddress function and passes in the output file.
	address.printAddress(out);
	//Print out the email address.
	out<<email<<endl;
	//Print out the customer's birthday.
	bday.printDate(out);
	out<<endl<<endl;
}

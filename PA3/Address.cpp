#include "Address.h"
using namespace std;

//Default constructor that initializes each member to either 0 or an
//empty string.
Address::Address(){
	this->house=0;
	this->street="";
	this->city="";
	this->state="";
	this->zip=0;
}

//Regular constructor that passes in the house number, street name, city, state,
//and zip code, initializing each member of the Address class to their
//corresponding values that were passed in.
Address::Address(int house, string street, string city, string state,
	int zip){
	this->house = house;
	this->street = street;
	this->city = city;
	this->state = state;
	this->zip = zip;
}

//setter for the address classs that passes in the house number, street name,
//city, state, and zip code, initilizing each member of the Address class to
//their corresponding values that were passed in.
void Address::setAddress(int house, string street, string city, string state,
												 int zip){
	this->house = house;
	this->street = street;
	this->city = city;
	this->state = state;
	this->zip = zip;
}

//Function that prints the address to the file.
void Address::printAddress(ofstream& out){
	//print the house number and street name
	out << house << " " << street << " " << endl;
	//print the city, state, and zip code.
	out << city << ", " << state << " " << zip << endl;
}

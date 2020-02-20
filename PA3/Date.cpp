//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#include "Date.h"
using namespace std;

//Default constructor that initiaizes each value to 0.
Date::Date(){
	this->month=0;
	this->day=0;
	this->year=0;
}

//Regular constructor that passes in a month, day, and year value, and
//initializes each member of the class.
Date::Date(int month, int day, int year){
	this->month = month;
	this->day = day;
	this->year = year;
}

//Setter for the Date class that operates the same as the above Regular
//constructor.
void Date::setDate(int month, int day, int year){
	this->month = month;
	this->day = day;
	this->year = year;
}

//Getter that returns the birth month.
int Date::getMonth(){
	return this->month;
}

//Getter that returns the birth day.
int Date::getDay(){
	return this->day;
}

//getter that returns the birth year.
int Date::getYear(){
	return this->year;
}

//prints out the customer's birthdday in mm/dd/yy format to the customer file.
void Date::printDate(ofstream& out){
	out << month << "/" << day << "/" << year << endl;
}

//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Address
{
  private:
    //Customer's house number
    int house;
    //Customer's street
    string street;
    //Customer's city
    string city;
    //Customer's state
    string state;
    //Customer's zip code
    int zip;

  public:
    //Defaut Address constructor
    Address();
    //Regular Address constructor
    Address(int house, string street, string city, string state, int zip);
    //Address class setter
    void setAddress(int house, string street, string city, string state, int zip);
    //Function that prints the data in the Address class to the customer file.
    void printAddress(ofstream& out);
};

#endif

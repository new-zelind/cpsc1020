/*
Zach Lindler
Programming Assignment 2
Dr. Yvon Feaster
CPSC 1020-002
3/29/2019*/

#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Address{
  private:
    //Declare each of the variables that will be included in the Address class
    string streetNum;
    string street;
    string city;
    string state;
    string zipCode;
    string website;
  public:
    Address(){
      //When a new Address class is declared, initialize each of the strings
      //to be a space.
      string streetNum=" ";
      string street = " ";
      string city = " ";
      string state = " ";
      string zipCode = " ";
      string website = " ";
    }

    //Member function declaration - prints the address.
    /*Parameters: ofstream& outFile - the output text file to be written to
      Return:     VOID
      This function prints the contents of the Address class to the output text
      file.*/
    void printAddress(ofstream& outFile);

    /*Parameters: string streetNum - the author's street address
                  string street - the author's street
                  string city - the author's City
                  string state - the author's state
                  string zipCode - the author's zip zip code
                  string website - the author's website.
      Return:     VOID
      This function sets the information for the author's address.*/
    void setAddress(string streetNum, string street, string city, string state,
      string zipCode, string website);
};

#endif

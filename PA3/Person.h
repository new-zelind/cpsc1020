//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#ifndef PERSON_H
#define PERSON_H

#include "Address.h"
#include "Date.h"

class Person
{
  private:
    //Last name
    string last;
    //first name
    string first;
    //customer's email
    string email;
    //Address class declaration for each person
    Address address;
    //Date class declaration for each person
    Date bday;

  public:
    //defaut person constructor
    Person();
    //regular person constructor
    Person(ifstream& in);
    //Getter for the address class
    Address getAddress();
    //Setter for the address class
    void setPerson(string last, string first, string email, int house,
                   string street, string city, string name, int zip, int month,
                   int day, int year);
    //Getter for the date class
    Date getDate();
    //Function that prints out the data contined in the Person, Address, and
    //Date classes.
    void printInfo(ofstream& out);
};

#endif

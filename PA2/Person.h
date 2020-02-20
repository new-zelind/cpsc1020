/*
Zach Lindler
Programming Assignment 2
Dr. Yvon Feaster
CPSC 1020-002
3/29/2019*/

#ifndef PERSON_H
#define PERSON_H
#include "Address.h"

class Person{
  private:
    Address address;
    string firstName;
    //string lastName;
  public:
    string lastName;
    Person(){
      Address address;
      string firstName = " ";
      string lastName = " ";
    }

    /*Parameters: ofstream& outFile - the output text file
      Returns:    void
      This function prints the name of the author to the output file.*/
    void printPerson(ofstream& outFile);

    /*Parameters: string firstName - the author's first name
                  string lastName - the author's last name
                  string streetNum - the author's street address
                  string street - the author's street
                  string city - the author's City
                  string state - the author's state
                  string zipCode - the author's zip zip code
                  string website - the author's website.
      Returns:    VOID
      This functions is the setter for the entire Person class, and passes in
      varaibles to for the Address class's setter.*/
    void setName(string firstName, string lastName, string streetNum,
      string street, string city, string state, string zipCode, string website);


};


#endif

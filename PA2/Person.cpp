/*
Zach Lindler
Programming Assignment 2
Dr. Yvon Feaster
CPSC 1020-002
3/29/2019*/

#include "Person.h"

void Person::setName(string nameF, string nameL, string strNum, string strName,
  string City, string State, string zip, string Website){

    //Set the Author's first and last name.
    firstName=nameF;
    lastName=nameL;

    //then, call the setter for the Address function and pass in the rest of
    //the variables.
    address.setAddress(strNum, strName, City, State, zip, Website);
    return;
}

void Person::printPerson(ofstream& outFile){
  //Print the header "Author Info" to the file
  outFile<<"Author Info:"<<endl;

  //Then print the last name and first name.
  outFile<<lastName<<", "<<firstName<<endl;

  //The function then calls the printAddress function to print the address.
  address.printAddress(outFile);

  return;
}

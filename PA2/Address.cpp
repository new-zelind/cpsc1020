/*
Zach Lindler
Programming Assignment 2
Dr. Yvon Feaster
CPSC 1020-002
3/29/2019*/

#include "Address.h"

void Address::setAddress(string strNum, string strName, string City, string State,
  string zip, string Website){

    //Assign the information contained in the Address class with the data of
    //the same name.
    streetNum=strNum;
    street=strName;
    city=City;
    state=State;
    zipCode=zip;
    website=Website;

    return;
}

void Address::printAddress(ofstream& outFile){

  //print the Author Info header
  outFile<<"Author Info:"<<endl;

  //print the street number, street, city, state, zipcode, and website
  outFile<<streetNum<<" "<<street<<endl;
  outFile<<city<<", "<<state<<" "<<zipCode<<endl;
  outFile<<website<<endl<<endl;
  return;
}

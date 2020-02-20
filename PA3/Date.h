//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#ifndef DATE_H
#define DATE_H
#include "Address.h"
#include <iomanip>
using namespace std;

class Date
{
  private:
    //Birth month
    int month;
    //Birth day
    int day;
    //Birth year
    int year;


  public:
    //Default date constructor
    Date();
    //Regular date constructor
    Date(int, int, int);
    //Date class setter
    void setDate(int month, int day, int year);
    //Getter for month
    int getMonth();
    //Getter for day
    int getDay();
    //Getter for year
    int getYear();
    //Function that prints the data to the customer file.
    void printDate(ofstream& out);

};

#endif

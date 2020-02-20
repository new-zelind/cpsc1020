//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#ifndef STAND_H
#define STAND_H

#include <string>
#include <iomanip>
#include "Person.h"

using namespace std;

class ProduceStand
{
  protected:
    //Name of the stand
    string name;
    //Weight of the produce
    double weight;
    //Prices of the produce
    double pricePerlb;
    double pricePerEach;
    //Number of items
    int howMany;
    //the amount of each sale used in calculateSales and then in calculateTax
    double eachSale;
    //the amount of tax for each sale used in calculateSales and calculateTax
    double eachSalesTax;

    //keeps track of the dailySales of both Fruit and Vegtable.
    static double dailySales;
    static double dailySalesTax;
    //creates a class customer of type Person.
    Person customer;

  private:
    //Name of the produce stand.
    string standName;
    /*because PS's constructor gets called each time an instance of fruit or
     *vegetable gets cretated then increment receiptNum also.*/
    static int receiptNum;

  public:
    //default constructor
    ProduceStand();
    //regular constructor
    ProduceStand(ifstream& in, ofstream& out);
    //getter for the stand name
    string getStandName();
    //getter for the receipt num
    int getReceiptNum();
    /*This function prints the information on the dailySales and dailySalesTax
     *for the day. */
    static void printInfo(ofstream& out);
};
#endif

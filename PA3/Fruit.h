//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#ifndef FRUIT_H
#define FRUIT_H

#include "ProduceStand.h"
using namespace std;

class Fruit : public ProduceStand
{
  private:

    //double that contains the total fruit sales for the day
    static double totalFruitSales;
    //integer that counts the number of fruit sale for the day
    static int fruitCount;
    //constant variable that holds the tax rate: 8%.
    static const double taxRate;

  public:
    //default constructor
    Fruit();
    //Regular constructor
    Fruit(ifstream& in, ofstream& out);
    //Fuction that calculates the taxes for each sale
    void calculateTax(ofstream& out);
    //Function that calculates the revenue for each sale
    void calculateSale(ofstream& out);
    //Function that prints the sales data to the receipt
    void printReceipt(ofstream& out);
    //Function that prints the customer information to the output file.
    void printInfo(ofstream& out);
};

#endif

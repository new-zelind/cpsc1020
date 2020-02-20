//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#ifndef VEGETABLE_H
#define VEGETABLE_H

#include "ProduceStand.h"
using namespace std;

class Vegetable : public ProduceStand
{
  private:

    //double that contains the total vegetable sales for the day
    static double totalVegtSales;
    //integer that counts the number of vegetable sale for the day
    static int vegtCount;
    //constant variable that holds the tax rate: 8%.
    static const double taxRate;

  public:
    //default constructor
    Vegetable();
    //Regular constructor
    Vegetable(ifstream& in, ofstream& out);
    //Function that calculates the taxes for each sale
    void calculateTax(ofstream& out);
    //Function that calculates the revenue for each sale
    void calculateSale(ofstream& out);
    //Function that prints the sales data to the receipt
    void printReceipt(ofstream& out);
    //Function that prints the customer information to the output file.
    void printInfo(ofstream& out);

};

#endif

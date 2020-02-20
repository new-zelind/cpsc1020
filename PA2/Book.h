/*
Zach Lindler
Programming Assignment 2
Dr. Yvon Feaster
CPSC 1020-002
3/29/2019*/

#ifndef BOOK_H
#define BOOK_H
#include "Person.h"

class Book{
  private:
    Person Author;
    string title;
    string ISBN;
    string category;
  public:
    Book(){
      Person Author;
      string title = " ";
      string ISBN = " ";
      string category = " ";
    }

    /*Parameters: ofstream& outFile
      Return:     VOID
      This function prints the contents of the Book class to the output file,
      then calls the printPerson function.*/
    void printBook(ofstream& outFile);

    /*Parameters: string title - the book's title
                  string category - the genre of the books
                  string ISBN - the book's ISBN number
                  string firstName - the author's first name
                  string lastName - the author's last name
                  string streetNum - the author's street address
                  string street - the author's street
                  string city - the author's City
                  string state - the author's state
                  string zipCode - the author's zip zip code
                  string website - the author's website.
      Returns:    VOID
      This functions is the setter for the entire Book class, and passes in
      varaibles to for the Person's class's setter.*/
    void setBookInfo(string title, string category, string ISBN,
      string firstName, string lastName, string streetNum, string street,
      string city, string state, string zipCode, string website);

    //The getter for the author's last name.
    string getLastName();
};


#endif

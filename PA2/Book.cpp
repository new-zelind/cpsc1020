/*
Zach Lindler
Programming Assignment 2
Dr. Yvon Feaster
CPSC 1020-002
3/29/2019*/

#include "Book.h"

void Book::setBookInfo(string Title, string Category, string isbn, string nameF,
  string nameL, string strNum, string strName, string City, string State,
  string zip, string Website){

    //Assign the passed in variables to the members of the Book class that
    //match the variables - title, ISBN, and category
    title=Title;
    ISBN=isbn;
    category=Category;

    //Call the setter for the Author class.
    Author.setName(nameF, nameL, strNum, strName, City, State, zip, Website);

    return;
}

void Book::printBook(ofstream& outFile){
  //Print the book title header, then the title of the book.
  outFile<<"Book Title:"<<endl;
  outFile<<title<<endl<<endl;

  //Call the printPerson function in the author class.
  Author.printPerson(outFile);

  //Print the ISBN number.
  outFile<<"Books ISBN:"<<endl;
  outFile<<ISBN<<endl<<endl;

  return;
}

//getter for the author's last name to be used in the comparison function.
string Book::getLastName(){
  return Author.lastName;
}

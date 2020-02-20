/*
Zach Lindler
Programming Assignment 2
Dr. Yvon Feaster
CPSC 1020-002
3/29/2019*/

#include "BookStore.h"

void BookStore::readInventory(string inventory){

  //Declare all the strings each book is broken down into
  string title, category, ISBN;
  string firstName, lastName;
  string streetNum, street, city, state, zipCode, website;

  //Turns the input file (inventory) into a massive string to be read from.
  ifstream books(inventory.c_str());

  //While the end of file character is not next,
  while(!books.eof()){

    //Read in each line of the selected book, and store it in the appropriate
    //member.
    getline(books, title);
    getline(books, firstName);
    getline(books, lastName);
    getline(books, streetNum);
    getline(books, street);
    getline(books, city);
    getline(books, state);
    getline(books, zipCode);
    getline(books, website);
    getline(books, category);
    getline(books, ISBN);
    //Pass in the \n newline character to ignore it, then repeat again for the
    //next book.
    books.get();

    if(category=="Fiction"){
      //If the category of the book is Nonfiction, we need to resize the vector
      //to it's size + 1.
      Fiction.resize(Fiction.size()+1);

      //Then, we need to use the setter to put the information into the class
      //at the appropriate location: the size of the vector - 1.
      Fiction.at(Fiction.size()-1).setBookInfo(title, category, ISBN,
        firstName, lastName, streetNum, street, city, state, zipCode, website);
    }
    else if(category=="NonFiction"){
      //Repeat the aforementioned process for Fiction books,
      NonFiction.resize(NonFiction.size()+1);
      NonFiction.at(NonFiction.size()-1).setBookInfo(title, category, ISBN,
        firstName, lastName, streetNum, street, city, state, zipCode, website);
    }
    else if(category=="Children"){
      //and the children's books.
      Children.resize(Children.size()+1);
      Children.at(Children.size()-1).setBookInfo(title, category, ISBN,
        firstName, lastName, streetNum, street, city, state, zipCode, website);
    }
  }
}

void BookStore::printInventory(ofstream& outFile){
  unsigned int j = 1;
  unsigned int k = 1;
  unsigned int l = 1;

  //Sort the Fiction elements.
  sort(this->Fiction.begin(),this->Fiction.end(),this->compareParts);
  //Sort the Nonfiction elements in the same way as the Fiction.
  sort(this->NonFiction.begin(),this->NonFiction.end(),this->compareParts);
  //Sort the Children's books.
  sort(this->Children.begin(),this->Children.end(),this->compareParts);

  //Print the star divider
  for(int i=0;i<80;i++){
    outFile<<"*";
  }

  //Print out the Fiction books.
  outFile<<endl<<"Category: Fiction"<<endl;
  //Iterate through each book in the Fiction vector
  for( j=1;j<=Fiction.size();j++){
    outFile<<j<<"."<<endl;
    //For each book in the vector (at location j-1), print the book to the file.
    Fiction.at(j-1).printBook(outFile);
  }
  //Print the star divider
  for(int i=0;i<80;i++){
    outFile<<"*";
  }
  //Add whitespace between dividers
  outFile<<endl<<endl<<endl;
  //Print the star divider
  for(int i=0;i<80;i++){
    outFile<<"*";
  }

  //Print out the nonfiction books
  outFile<<endl<<"Category: NonFiction"<<endl;
  //Iterate through each book in the NonFiction vector
  for(k=1;k<=NonFiction.size();k++){
    outFile<<k<<"."<<endl;
    //For each book in the vector, print the book to the file.
    NonFiction.at(k-1).printBook(outFile);
  }
  //Print the star divider
  for(int i=0;i<80;i++){
    outFile<<"*";
  }
  //Add whitespace between dividers
  outFile<<endl<<endl<<endl;
  //Print the star divider
  for(int i=0;i<80;i++){
    outFile<<"*";
  }

  //Print out the Children's books.
  outFile<<endl<<"Category: Children's"<<endl;
  //Iterate through each book in the Children's book vector.
  for(l=1;l<=Children.size();l++){
    outFile<<l<<"."<<endl;
    //For each book, print the book to the file.
    Children.at(l-1).printBook(outFile);
  }
  //Print the star divider
  for(int i=0;i<80;i++){
    outFile<<"*";
  }

  //End of function
  return;
}

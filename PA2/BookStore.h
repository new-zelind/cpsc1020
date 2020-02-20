/*
Zach Lindler
Programming Assignment 2
Dr. Yvon Feaster
CPSC 1020-002
3/29/2019*/

#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include "Book.h"

class BookStore{
  private:
    Book newBook;
    vector <Book> Fiction;
    vector <Book> NonFiction;
    vector <Book> Children;
  public:
    //Constructor
    BookStore(){
      Book();
    }

    /*Parameters: string inventory - represents argv[1], or the input file passed in
     *              as a massive string.
     *Return:     VOID
     *This function reads the information for each book in from the input file
     *  specified. For each book, it separates them into (Non)Fiction and Children's
     *  books, which are vectors.
     */
    void readInventory(string inventory);

    /*Parameters: ofstream& outFile - the output text file
      Returns:    VOID
      This function prints the entire inventory of the bookstore to the
      specified file.*/
    void printInventory(ofstream& outFile);

    /*Parameters: Book one - the first book to be compared
                  Book two - the second book to be compared
      Return:     A boolean "true" or "false"
      This function compares the last names of the authors of two given books.
      If the last name of the first book's author comes before the second book's
      author's, then the functions returns "true". Otherwise, it returns false.*/
    static bool compareParts(Book one, Book two){
      if(one.getLastName()<two.getLastName()){
        return true;
      }
      else{
        return false;
      }
    }

};


#endif

#ifndef MYSTRING_H
#define MYSTRING_H value

#include "stdlib.h"
#include "string.h"
#include <iostream>

using namespace std;

class MyString {
private:
  char* data;
  int size;

public:
  /*****************
    Use init lists!
  ******************/

  // Default constructor
  MyString ();
  // Copy from cstring
  MyString (const char*);
  // Copy form MyString
  MyString (const MyString&);

  // Destructor will actuall need code...
  ~MyString ();

  // Simple getter
  int len () const;

  // Asignment, member functions
  // Notice the return type!!!
  MyString& operator= (const MyString&);
  MyString& operator= (const char*);
  MyString& operator+= (const MyString&);

  // Friendly little guys, they ARE NOT member functions.
  // Why? Look at the return type...
  // HINT: Last 2 + operator can be done in a single line!
  friend MyString operator+ (const MyString&, const MyString&);
  friend MyString operator+ (const MyString&, const char*);
  friend MyString operator+ (const char*, const MyString&);


  //relational operator
  /*Returns true if the arrays are the same.  Otherwise it returns false.*/
  bool operator==(const MyString&) const;

  /*Returns true if the arrays are not equal, false otherwise.*/
  bool operator!=(const MyString& right)const;

//  friend bool operator< (const MyString& , const MyString&);
//  friend bool operator> (const MyString& , const MyString&);
//  friend bool operator<= (const MyString& , const MyString&);
//  friend bool operator>= (const MyString& , const MyString&);
  // Member function, array indexing
  // Check your bounds, and make it const!
//  char operator[] (int ndx) const;

  // Output to a stream, another friendly kinda guy
  // Notice the parameters...
//  friend ostream& operator<<(ostream&, const MyString&);
//
};

#endif

/***************************
Ashton Sobeck
lab 11
CPSC 1021 Section 005
Alex Myers, Hollis Liu
****************************/

#include "MyString.h"

//default constructor
MyString::MyString()
{
  size = 0;
  data = nullptr;
}

//using initialization lists in the constructor to
//initialize the members of the classes
MyString::MyString(const char* str) :
          data(new char[strlen(str) + 1]),
          size(strlen(str) + 1)
{
  for(int i = 0; i < size - 1; i++)
  {
    data[i] = str[i];
  }
  data[size - 1] = '\0';
}

//copy constructor
MyString::MyString(const MyString& sample)
{
  //deallocating the memory of the object that is being
  //overwritten
  if(size > 0)
  {
    delete [] data;
  }

  size = sample.size;
  data = new char[size];

  //copying the array into the object on the left side of the equation
  for(int i = 0; i < size; i++)
  {
    data[i] = sample.data[i];
  }

  //adding the null character to the end of the array
  data[size - 1] = '\0';
}

//this is the destructor to deallocate the memory
//allocated in the constructors
MyString::~MyString()
{
  delete [] data;
}

//this function returns the length of the array or string
int MyString::len() const
{
  //returning size - 1 to consider the null character
  return (size - 1);
}

//this overloads the = operator when an object is on the right side
//of the equation. The array will be resized for the object
//that
MyString& MyString::operator=(const MyString& right)
{
  if(this != &right)
  {
    if(size > 0)
    {
      delete [] data;
    }

    //considering the null character
    size = right.size + 1;
    data = new char[size];

    //copying over the array
    for(int i = 0; i < size - 1; i++)
    {
      data[i] = right.data[i];
    }

    data[size - 1] = '\0';
  }

  return *this;
}

MyString& MyString::operator=(const char* str)
{
  if(size > 0)
  {
    delete [] data;
  }

  //using strlen to get the length of the character array
  //and then adding 1 to consider the null character
  size = strlen(str) + 1;
  data = new char[size];

  //copying over the character array to data
  for(int i = 0; i < size - 1; i++)
  {
    data[i] = str[i];
  }
  //adding null character
  data[size - 1] = '\0';
  return *this;
}

MyString& MyString::operator+=(const MyString& right)
{
  //making a temporary character to store the this object
  char* temp = new char[size];

  //storing data into temp
  for(int i = 0; i < size; i++)
  {
    temp[i] = data[i];
  }

  if(size > 0)
  {
    delete [] data;
  }

  //adding the size of the object being added
  size += right.size;

  data = new char[size];

  //putting temp into the new longer data array
  for(unsigned int i = 0; i < strlen(temp); i++)
  {
    data[i] = temp[i];
  }

  //adding right.data to the end of data
  strcat(data, right.data);

  //deleting the temp array
  delete [] temp;

  //returning the modified object
  return *this;
}

MyString operator+(const MyString& left, const MyString& right)
{
  //making a temporary object to not mess with the constant objects
  //passed in
  MyString temp;

  //making temp the size of both left and right with a null character
  temp.size = strlen(left.data) + strlen(right.data) + 1;
  temp.data = new char[temp.size];

  //putting left into temp
  for(unsigned int i = 0; i < strlen(left.data); i++)
  {
    temp.data[i] = left.data[i];
  }

  //adding right to the end of temp
  strcat(temp.data, right.data);

  //putting in a null character
  temp.data[temp.size - 1] = '\0';

  //returning the temp object
  //because the const objects cannot be modified
  return temp;
}

//this function just calls the previously made overloaded operator+
MyString operator+(const MyString& left, const char* right)
{
  //constructing an object with the character array passed in
  return (left + MyString(right));
}

//this function just calls the previously made overloaded operator+
MyString operator+(const char* left, const MyString& right)
{
  //constructing an object with the character array passed in
  return (MyString(left) + right);
}

//using strcmp to see if the character arrays are equal
//returns true if equal, false if not
bool MyString::operator==(const MyString& right) const
{
  if(strcmp(data, right.data) == 0)
    return true;
  else
    return false;
}

//using strcmp to see if the character arrays are not equal
//returns true if not equal, false if equal
bool MyString::operator!=(const MyString& right) const
{
  if(strcmp(data, right.data) != 0)
    return true;
  else
    return false;
}

//using strcmp to see if the left character array is less than the right
//character array
//returns true if strcmp returns a value less than 0
bool operator<(const MyString& left, const MyString& right)
{
  if(strcmp(left.data, right.data) < 0)
    return true;
  else
    return false;
}

//using strcmp to see if the left character array is greater than the right
//character array
//returns true if strcmp returns a value greater than 0
bool operator>(const MyString& left, const MyString& right)
{
  if(strcmp(left.data, right.data) > 0)
    return true;
  else
    return false;
}

//using strcmp to see if the left character array is less than or equal to
//the right character array
//returns true if strcmp returns a value of 0 or less than 0
bool operator<=(const MyString& left, const MyString& right)
{
  if(strcmp(left.data, right.data) <= 0)
    return true;
  else
    return false;
}

//using strcmp to see if the left character array is greater than or equal to
//the right character array
//returns true if strcmp returns a value of 0 or greater
bool operator>=(const MyString& left, const MyString& right)
{
  if(strcmp(left.data, right.data) >= 0)
    return true;
  else
    return false;
}

//overloading the [] to check the bounds of the array.
//if the index number passed in is out of bounds an error message is displayed
//and the program exits
char MyString::operator[](int ndx) const
{
  if(ndx < size)
    return data[ndx];
  else
  {
    cout << "You tried to access a character out of the bounds of the array"
         << endl << "Please change the index number and run the program again."
         << endl;
    exit(0);
  }
}

//overloading the << operator to be able to display objects data arrays
//returns the ostream that is passed in
ostream& operator<<(ostream& out, const MyString& str)
{
  out << str.data;
  return out;
}

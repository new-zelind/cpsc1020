// This program demonstrates the use of copy constructors.
#include <iostream>
#include <iomanip>
#include "NumberArray2.h"

using namespace std;

int main()
{  
  NumberArray first(3, 10.5);
  
  //Make second a copy of first object
  NumberArray second = first;

  // Display the values of the two objects
  cout << setprecision(2) << fixed << showpoint;
  cout << "Value stored in first object is ";
  first.print();
  cout << "\nValue stored in second object is ";
  second.print();
  cout <<  "\nOnly the value in second object will "
       <<  "be changed.\n";
  
  //Now change value stored in second object
  second.setValue(20.5);
  
  // Display the values stored in the two objects
  cout << "Value stored in first object is ";
  first.print();
  cout << endl << "Value stored in second object is ";
  second.print();
  return 0;
}

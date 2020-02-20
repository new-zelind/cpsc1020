#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#include "SimpleTranscript.h"

int main()
{
  SimpleTranscript student("John Smith");

  cout << "The transcript for John Smith should be loaded"
    << " by the constructor." << endl;
  cout << endl;

  student.ListCourses();
  cout << endl;

  cout << "His GPA is " << student.CalculateGPA() << endl;
  
  return 0;
}

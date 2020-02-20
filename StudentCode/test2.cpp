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

  student.AddCourse("CPSC 1010", 4);
  student.AddCourse("ENGL 1030", 3);
  student.AddCourse("MATH 1060", 3);
  student.AddCourse("POSC 1010", 2);

  student.SaveCourses();

  cout << "A transcript for John Smith has been created and saved." << endl;

  return 0;
}

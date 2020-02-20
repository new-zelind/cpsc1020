#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#include "SimpleTranscript.h"

int main()
{
  SimpleTranscript student("Jane Doe");

  cout << "Jane Doe is a new student and should have no courses:" << endl;
  cout << endl;
  student.ListCourses();
  cout << endl;
  cout << "Her GPA should be 0: " << student.CalculateGPA() << endl;
  cout << endl;

  cout << "Let's add three courses and print her transcript." << endl;
  cout << endl;
  student.AddCourse("CPSC 1010", 3);
  student.AddCourse("CPSC 1020", 4);
  student.AddCourse("MATH 1060", 1);
  student.ListCourses();
  cout << "Her GPA is " << student.CalculateGPA() << endl;
  cout << endl;

  cout << "Let's forgive her math course and see the change." << endl;
  cout << endl;
  student.ForgiveCourse("MATH 1060");
  student.ListCourses();
  cout << "Her GPA is " << student.CalculateGPA() << endl;
  cout << endl;

  cout << "Let's forgive an incorrect course and see the change." << endl;
  bool success = student.ForgiveCourse("CPSC 5000");
  if (success)
  {
    cout << "There is an error in your forgiveness code!" << endl;
  }
  else
  {
    cout << "Your code correctly detected that there was no match!" << endl;
  }
  cout << endl;

  cout << "Let Jane retake the math course." << endl;
  cout << endl;
  student.AddCourse("MATH 1060", 4);
  student.ListCourses();
  cout << "Her GPA is " << student.CalculateGPA() << endl;

  return 0;
}

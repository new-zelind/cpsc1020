/******************* 
  Zach Lindler 
  zelindl               
  Lab 8                             
  Lab Section: 002
  Hunter Ross               
*******************/ 


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

#include "SimpleTranscript.h"


SimpleTranscript::SimpleTranscript(string name)
 : student_name(name)
	{
  	if (student_name == "")
  	{
		student_name = "Test Student";
	}
	course_count = LoadCourses();
}


bool SimpleTranscript::AddCourse(string course, int grade)
{
	if ((course_count == COURSE_LIMIT) || (course == "") || (grade < 0) || (grade > 4))
	{
		return false;
	}
	
	//If the course name is legitimate,
	else{
		//Add the name of the course to the roster in the proper location.
		course_name[course_count]=course;
		//Add the number of points earned to the roster in the proper location.
		grade_point[course_count]=grade;
		//Assign the target location in the forgiven course array to be 'false'
		forgiven_course[course_count]=false;
		//Increase the course count.
		course_count++;
	}
  return true;
}


bool SimpleTranscript::ForgiveCourse(string name)
{
	//Iterate through the number of courses.
	for(int i=0;i<course_count;i++){
		//If the name of the course in the roster matches the target course
		if(name==course_name[i]){
			//Forgive the course by changing the boolean value in the proper location to 'true' and have the function return true.
			forgiven_course[i]=true;
			return true;
		}
	}
	//Otherwise, return false.
	return false;
}


void SimpleTranscript::SaveCourses()
{
  	ofstream output_file;
  	string file_name;

  	file_name = ConvertToFileName(student_name);

  	output_file.open(file_name.c_str());

  	output_file << course_count << endl;

  	for (int i = 0; i < course_count; i++)
  	{
    		output_file << course_name[i] << endl;
    		output_file << forgiven_course[i] << endl;
  		output_file << grade_point[i] << endl;
  	}

  	output_file.close();
}


void SimpleTranscript::ListCourses()
{
  	char letter_grade[5] = {'F', 'D', 'C', 'B', 'A'};
	//For loop that iterates through each course
	for(int i=0;i<course_count;i++){
		//If the target course was not forgiven, print the course name, number, and grade.
		if(forgiven_course[i]==false){
			cout<<course_name[i]<<" "<<letter_grade[grade_point[i]]<<endl;
		}
		//Otherwise, the course was forgiven. Print the course name, number, and change the grade to say "FGD".
		else{
			cout<<course_name[i]<<" FGD"<<endl;
		}	
	}
	
}


double SimpleTranscript::CalculateGPA()
{
	//Declare and initialize the variables that will hold the total number of removed courses, as well as the double holding the gpa.
	int removed=0;
	double gpa=0;

	//For loop that iterates through each course.
	for(int i=0;i<course_count;i++){
		//If the target course was not forgiven, add the points earned in that course to the total number of points earned (gpa).
		if(forgiven_course[i]==false){
			gpa += grade_point[i];
		}
		//Otherwise, the course was forgiven, and its points do NOT count towards the gpa. Increase the number of forgiven courses.
		else{
			removed++;
		}
	}
	//After calculations are finished, divide the total number of points earned by the total number of courses minus the number of removed courses.
	gpa /= (course_count-removed);
	if(course_count==0){
		gpa=0;
	}
	//Return the GPA.
	return gpa;
}


string SimpleTranscript::ConvertToFileName(string name)
{
  	using std::replace;

  	string file_name = name;
  	replace(file_name.begin(), file_name.end(), ' ', '_');
  	file_name = file_name + ".txt";
  	return file_name;
}


int SimpleTranscript::LoadCourses()
{
  	ifstream input_file;
  	string file_name;
  	int count_of_courses_in_file;

  	file_name = ConvertToFileName(student_name);

  	input_file.open(file_name.c_str());

  	if (input_file)
  	{
    		input_file >> count_of_courses_in_file;
    		input_file.ignore();

    		for (int i = 0; i < count_of_courses_in_file; i++)
    		{
      			getline(input_file, course_name[i]);

      			input_file >> forgiven_course[i];
      			input_file.ignore();

      			input_file >> grade_point[i];
      			input_file.ignore();
    		}

    		input_file.close();

   		return count_of_courses_in_file;
  	}
	else
  	{
    		return 0;
  	}
}

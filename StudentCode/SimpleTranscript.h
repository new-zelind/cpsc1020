#ifndef SIMPLETRANSCRIPT_H
#define SIMPLETRANSCRIPT_H

// UML
//
//   +---------------------------------+
//   | SimpleTranscript                |
//   +---------------------------------+
//   | - student_name                  |
//   | - course_count                  |
//   | - course_name[COURSE_LIMIT]     |
//   | - forgiven_course[COURSE_LIMIT] |
//   | - grade_point[COURSE_LIMIT]     |
//   +---------------------------------+
//   | + SimpleTranscript()            |
//   | + AddCourse()                   |
//   | + ForgiveCourse()               |
//   | + SaveCourses()                 |
//   | + ListCourses()                 |
//   | + CalculateGPA()                |
//   | - ConvertToFileName()           |
//   | - LoadCourses()                 |
//   +---------------------------------+
//
// This class models a simple transcript for a student with up to
// COURSE_LIMIT courses.
//
// The class has a student name and count of courses. There are
// three parallel arrays to hold the course information. A given
// course has the same index for each of the arrays.
//
// Each student object is associated with a file. The student's
// name is held in a single string, and the corresponding file
// is named using the student's name, with underscores replacing
// any spaces in the student's name, followed by ".txt".
//
// The constructor will open the corresponding file and load the
// courses that are stored. If a file cannot be opened, the
// constructor starts with zero courses.
//
// There are two private methods that serve as helper functions:
//
//   ConvertToFileName() - The filename is constructed from the
//     student's name by replacing spaces with underscores and
//     then adding ".txt". The replace() algorithm from the STL
//     is used.
//
//   LoadCourses() - The list of courses for a student is loaded
//     from the text file that corresponds to the student's name.
//
// There are five public methods:
//
//   AddCourse() - A course is added by passing a string that
//     identifies the course and passing a grade point, which is
//     an integer value in the range 0-4 (corresponding to grades
//     of F through A). Adding a repeated course is allowed.
//
//   ForgiveCourse() - A course is forgiven by passing a string
//     that identifies the course. A forgiven course remains on
//     the transcript but is not included in the GPA calculation.
//     When printing the transcript, an "FG" code appears before
//     the grade.
//
//   SaveCourses() - The list of courses is saved into a text
//     file that corresponds to the student name. The information
//     for each course is written to three separate lines in the
//     file: name, forgiven status, and grade point.
//
//   ListCourses() - A transcript of the courses is printed to
//     standard output.
//
//   CalculateGPA() - The GPA is calculated and returned.
//
// Limitations of this simple class:
//
//   A more refined class would use a unique student id number for
//   each student since some students might have the same name.
//
//   A more refined class might limit the number of repeats and/or
//   adjust the GPA based on a repeat policy.
//
//   A more refined class would likely use a vector of structs or
//   tuples rather than three fixed-size arrays.
//
// Class invariants:
//
//   student_name != ""
//   0 <= course_count <= COURSE_LIMIT


int const COURSE_LIMIT = 20;


class SimpleTranscript
{
 private:

   string student_name;
   int course_count;
   string course_name[COURSE_LIMIT];
   bool forgiven_course[COURSE_LIMIT];
   int grade_point[COURSE_LIMIT];

   string ConvertToFileName(string name);
   int LoadCourses();

 public:

   SimpleTranscript(string name = "Test Student");

   bool AddCourse(string course, int grade);
   bool ForgiveCourse(string name);
   void SaveCourses();
   void ListCourses();
   double CalculateGPA();
};
#endif

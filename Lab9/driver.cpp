/*
Zach Lindler
zelindl
Lab 9
Section 2
Hollis Liu & Emily Merritt*/

#include "Functions.h"

int main(int argc, const char* argv[])
{
  /*Check to make sure the appropriate number of command line arguments are
   *entered on the terminal (3 - the executable, input file, and output file*/
   if(argc!=3){
     cout<<"Incorrect number of arguments given."<<endl;
     return -1;
   }

  /*Open two files, one for input and one for output, which are defined
   *on the command line. Then, make sure the files are opened correctly.*/
  ifstream inFile;
  inFile.open(argv[1]);

  if(!inFile.is_open()){
    cout<<"Input file not opened properly."<<endl;
    return -1;
  }

  ofstream outFile;
  outFile.open(argv[2]);

  if(!outFile.is_open()){
    cout<<"Output file not created properly."<<endl;
    return -1;
  }

  /*You are going to need some variables to hold the information pertaining to
   *the circle and the size of the image you are creating.
   *Also, create a 2D vector to hold the pixels of the PPM image*/
  int radius=0, X=0, Y=0, height=0, width=0;
  vector<vector<Pixel>> vec2D;

  /*Read in the information needed for the circle and the width and height of
   *the PPM image*/
  inFile>>radius;
  inFile>>Y;
  inFile>>X;
  inFile>>height;
  inFile>>width;

  /*Now that you have the information needed for the Circle you will need to
   *create an instance of Point and an instance of Circle. Remember Circle "has
   *an" (composition) instance of Point and the constructor for Circle is
   *expecting a Point and an integer (the radius).*/
  Point p(X, Y);
  Circle circ(p, radius);

  /*Using the method discussed in the lab documentation, resize the vector to
   *accomodate the 2D vector*/
  vec2D.resize(height, vector<Pixel>(width));

  /*Call fillVec to fill the vector with the appropriate pixels*/
  fillVec(vec2D, circ);

  /*Call printVec to print the output image.  I have provided this function for
   *you. You just need to call it.*/
  printVec(outFile, vec2D, height, width);

  inFile.close();
  outFile.close();

  return 0;
}

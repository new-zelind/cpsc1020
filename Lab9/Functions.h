/*
Zach Lindler
zelindl
Lab 9
Section 2
Hollis Liu & Emily Merritt*/

/*These functions are not part of the class but helper functions or fuctions
 *that use the circle class*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Circle.h"
/*Include the appropriate include statements*/

struct Pixel{
  unsigned char r, g, b;
};

/*Parameters:	vector<vector<Pixel>>& vec2D: a 2d vector that holds the pixel data.
		Circle& cir: A class of type Circle that holds the data for a circle.
  Return:	VOID
  This function fills the specified 2d vector with the information needed to create
  the .ppm image.*/
void fillVec(vector< vector<Pixel> >& vec2D, Circle& cir);

/*Parameters:	ofstream& output: The output file
		vector<vector<Pixel>>& vec2D: the 2d vector that holds the pixel data.
		int, int - the X and Y coordinates of the center of the circle
  Return:	VOID
  This functions prints the data from the 2d vector of pixels to the output .ppm file.*/
void printVec(ofstream& output, vector< vector<Pixel> >&, int, int);

#endif

/*
Zach Lindler
zelindl
Lab 9
Section 2
Hollis Liu & Emily Merritt*/

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"


class Circle
{
    private:
      Point center;
      int radius;

    public:
      //Constructors
      Circle();
      Circle(Point&, int);
      /*Parameters: Point& - a class of type "point"
	Return:     An integer value that equals either 1 or 0.
	This function determines whether the input point is within
	a certain distance of the center point specified in the
	input file. If it is, return 1. Otherwise, return 0.*/
      int hit(Point&);

};
 
#endif

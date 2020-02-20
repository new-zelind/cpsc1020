/*
Zach Lindler
zelindl
Lab 9
Section 2
Hollis Liu & Emily Merritt*/

#include "Circle.h"
using namespace std;

/*implement the default construct*/
Circle::Circle()
{
  radius = 0;
  center.setX(0);
  center.setY(0);
}
 
/*inplement the convert (regular) constructor*/
Circle::Circle(Point& p, int radius){
  center.setX(p.getX());
  center.setY(p.getY());
  this->radius = radius;
}

/*******************************************************************************
 *hit
 *paramethers:
 *int x - represents the x value of the plane. Remember this represents the
 *columns
 *int y - represents the y value of the plane. Remember this represents the
 *rows of the plane.
 *This function determines if the point on the plane is within the a circle. If
 *it is in the circle a 1 is returned otherwise a 0 is returned.
 *See the lab documentations for an explanation.
 ******************************************************************************/

int Circle::hit(Point& p){
  //Calculate the x coordinate of the point relative to the center point.
  int xCoord=pow((p.getX()-center.getX()), 2);
  //Repeat for the y coordinate.
  int yCoord=pow((p.getY()-center.getY()), 2);

  //If the square root of the sum of the coordinates is less than the radius
  if(sqrt((xCoord+yCoord))<radius){
    //Return 1
    return 1;
  }
  else{
    return 0;
  }

}

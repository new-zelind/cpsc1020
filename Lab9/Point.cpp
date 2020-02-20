/*
Zach Lindler
zelindl
Lab 9
Section 2
Hollis Liu & Emily Meritt*/

#include "Point.h"



/*Implement these functions*/
Point::Point(int x, int y){
  this->x=x;
  this->y=y;
}

//Setters and Getters for the x and y coordinates specified in each Point class
void Point::setX(int x)
{
  this->x=x;
}
void Point::setY(int y)
{
  this->y=y;
}

int Point::getX() const
{
  return x;
}
int Point::getY() const
{
  return y;
}
 

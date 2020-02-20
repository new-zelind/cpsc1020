/*
Zach Lindler
zelindl
Lab9 - 002
Hollis Liu & Emily Merritt*/


#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

class Point
{
    private:

        int x, y;

    public:
        /*Point Constructor*/
        Point(int x = 0, int y = 0);
        /*setters and getters used by the circle class to assess the x and y
         *variables*/
        void setX(int x);
        void setY(int y);

        int getX() const;
        int getY() const;


};

#endif
 

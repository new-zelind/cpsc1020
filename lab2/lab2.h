/*********************
  Zach Lindler
  zelindl
  lab2.h
  Lab Section: 002
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Circle Type, use this to represent the
// data from the input file

typedef struct circle_t {
  double x,y,r;
} circle;

/*
  This function takes in a File pointer and an int pointer
  The function should:
  1. Read the first line of the input file to determine how many circles there are
    1a. Store the number of circles in the passed int pointer
  2. Use malloc to allocate memory for an array of circles
  3. Read and store all circles in the file
  4. Return the malloc'd array of circles
*/

circle* read_data(FILE* input, int* num);

/*
  This function takes an output File pointer, an array of circles
  and the number of circles in the array. It should:
  1. Calculate the centroid/center of mass for all the circles
    1a. Find area for each circle, keep running total
    1b. Calculate X sum: x location * area
    1c. Calculate Y sum: y location * area
    1d. Divide each sum by total area
  2. Write centroid out to file
*/

void calc_centroid(FILE* output, circle* circles, int num);

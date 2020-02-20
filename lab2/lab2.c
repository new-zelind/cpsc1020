/*********************
  Zach Lindler
  zelindl
  lab2.c
  Lab Section: 002
**********************/

#include "lab2.h"

/*Paramaters:
  FILE* input: The designated input file (circles.dat) from which the data will
    be read.
  int* num: The integer pointer passed into the function from the driver.
    Contains the memory address of how many circles there are in the circles.dat
    file.*/
/*Returns: A struct of type circle* containing the x-coordinates, y-coordinates,
  and radii of all of the circles in the circles.dat file.*/

circle* read_data(FILE* input, int* num)
{
  //The first line of the input file consists of two characters: #X, where X is
  //the number of circles. This will scan in the number of circles and save it
  //to the integer pointer.
  fscanf(input,"#%d",num);

  //Initialize the struct of circle data for use in this function
  circle* circleDataFunc=malloc((*num) * sizeof(circle));

  //Read the data from the input file, and store it into the circle struct.
  //The first number of each line is the x-coordinate, the second number is the
  //y-coordinate, and the thrid number is the radius.
  int line=0;
  while(line<(*num)){
    fscanf(input,"%lf",&circleDataFunc[line].x);
    fscanf(input,"%lf",&circleDataFunc[line].y);
    fscanf(input,"%lf",&circleDataFunc[line].r);
    line++;
  }

  //Return struct circleDataFunc of type circle.
  return circleDataFunc;

}

/*Paramaters:
  FILE* output: The file where the centroid of the circles will be written.
  circle* circles: The struct containing the circle data.
  int num: The number integer passes from the input document. Also the number
    of circles in the file.*/
/*Return: Function doesn't explicity return anything, but it does write the
  centroid of the circle to the output file mentioned above.*/
/*Purpose: This function calculates the centroid of a given number of circles
  in the circles.dat file, then prints the calculated centroid to a user-named
  and specified output file. */

void calc_centroid(FILE* output, circle* circles, int num)
{
  //Initialize variables needed
  double area=0, xData=0, yData=0;
  double sumX=0, sumY=0;
  double totalArea=0, finalX=0, finalY=0;
  int count=0;

  //Code to determine the centroid
  while(count<num){

    //Calculate the area of one of the circles, then add this area to the total
    //area. A=pi*r^2
    area=M_PI*pow(circles[count].r, 2);
    totalArea=totalArea+area;

    //Calculate the data for the x-coordinate and add it to the x total.
    xData=area*(circles[count].x);
    sumX=sumX+xData;

    //Repeat this process for y.
    yData=area*(circles[count].y);
    sumY=sumY+yData;

    //Increment
    count++;
  }
  //Calculate the final centroid location
  finalX=sumX/totalArea;
  finalY=sumY/totalArea;

  //Print the result to the output file.
  fprintf(output, "%lf ",finalX);
  fprintf(output, "%lf\n",finalY);
}

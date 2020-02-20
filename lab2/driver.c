/*********************
  Zach Lindler
  zelindl
  driver.c
  Lab Section: 002
**********************/

#include "lab2.h"

int main(int argc, char const *argv[])
{
  //Command line argument verification
  if (argc<3){
    fprintf(stdout,"\nIncorrect number of arguments.");
    exit(0);
  }

  //Open the input file as read-only and checks for errors
  FILE *inFile=fopen(argv[1], "r");
  if(inFile==NULL){
    fprintf(stdout,"\nError opening input file.\n");
    return 0;
  }

  //Create the output file for writing and checks for errors
  FILE *outFile=fopen(argv[2], "w");
  if(outFile==NULL){
    fprintf(stdout,"\nError creating output file.\n");
    return 0;
  }

  //Initialize the struct for cirle data
  circle * circleData;

  //Int variable to be passed in
  int inVar;

  //Function calls
  circleData=read_data(inFile, &inVar);
  calc_centroid(outFile, circleData, inVar);

  //Close the input and output files
  fclose(inFile);
  fclose(outFile);

  //Free the allocated memory at end of driver functions
  free(circleData);

  return 0;
}

/*
Zach Lindler
zelindl
Lab 9
Section 2
Hollis Liu & Emily Merritt*/

#include "Functions.h"

/*These functions are not part of the class but helper functions or fuctions
 *that use the circle class*/

/*Based on the outcome of the hit function you wil need to set the rgb values
 *for each pixel of the image.*/

void fillVec(vector< vector<Pixel> >& vec2D, Circle& cir)
{
  unsigned int i;
  unsigned int j;
  /*nested for loops to loop through vec2D */
  for(i=0;i<=vec2D.size()-1;i++){
    for(j=0;j<=vec2D.at(i).size()-1;j++){

      /*At each iteration create an instance of point to pass to the circles
       *hit function. Hint the hit function will be called in this function!!*/
      Point point(i, j);

       /*If there is a hit then set the RGB values for the pixel at this location
        *equal of one color (you choose, mine was Clemson orange 246, 103 and 41)
        *otherwise set the RGB values to another color (again you choose, mine
        *was Clemson purple 82, 45, 128)*/
      if(cir.hit(point)==1){
        vec2D.at(i).at(j).r=246;
        vec2D.at(i).at(j).g=103;
        vec2D.at(i).at(j).b=41;
      }
      else{
        vec2D.at(i).at(j).r=82;
        vec2D.at(i).at(j).g=45;
        vec2D.at(i).at(j).b=128;
      }
    }
  }
}

/*By the time you call this function you should have looped throught the entire
 *size of the image determining if each point was within the parameters of
 *the circle.  You should have basically set the color for each pixel in the 2D
 *image to one of two colors.
 YOU DO NOT NEED TO CHANGE THIS FUNCTION!!!
 */
void printVec(ofstream& output, vector< vector<Pixel> >& test,
              int row, int col)
{ unsigned int i = 0,j = 0;
  output << "P6\n";
  output << col << " " << row << " " << 255 << endl;
  for(i = 0; i < test.size(); i++)
  {
    for(j = 0; j < test.at(i).size(); j++)
    {
      output << test.at(i).at(j).r
             << test.at(i).at(j).g
             << test.at(i).at(j).b;
    }
  }
}

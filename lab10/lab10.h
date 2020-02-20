/*Zach Lindler
  zelindl
  Lab 10
  Section 2
  Hollis Liu & Emily Merritt*/

#ifndef LAB10_H
#define LAB10_H
#include <iostream>
#include <fstream>
using namespace std;

/*******************************************************************************
 * This function determines how many numbers are in the input file so that the
 * appropriate amount of memory can be dynamically allocated. This function also
 * returns the input file reference to the beginning of the file allowing the
 * user, in another function read and store the data.
 * Parameter: iostream reference variable that represents the input file that 
 * has been opened and validate.
 * Return: return the number of numbers in the file.
 ******************************************************************************/
int howMany(ifstream& input);


/*******************************************************************************
 * This function dynamically allocates the memory for the array that will hold
 * the values that will be sorted.
 * Parameter: int - this represents the number of integers that will be in the 
 * array.
 * Return:  Return the address of the allocated memory.
 ******************************************************************************/
int* allocateMemory(int num);


/*******************************************************************************
 * This function will read the integers from the input file and store them in 
 * the array passed to the function.
 * Parameter: iostream reference variable that represents the input file  and 
 * an array to store the data. Since you know the number of integers in the file
 * you can pass the length variable to the function then use a for loop
 * to read in the data and store it in the array.
 * Return: void - no return value.
 ******************************************************************************/
void readData(ifstream& in, int* arr, int len);


/*******************************************************************************
 * This function sorts the integers stored in an array.
 * Parameter: an array to is storing the data and the size of the array.
 * Return: void no return value.
 ******************************************************************************/
void bubbleSort(int* arr, int length);

/*******************************************************************************
 * This function swaps the arr i and arr i+1
 * Parameter: The array that holds the data to be swapped.  int that represents 
 * the ith  ith + 1 positions that need to be swapped.
 * Return: void - no return value.
*******************************************************************************/
void swap(int* first, int* second );

/*******************************************************************************
 * This function prints the values stored in arr 
 * Parameter: output file, the array being printed and the size of the array.
 * Return: void - no return
*******************************************************************************/

void printData(ofstream& out, int* const arr, int len);

#endif

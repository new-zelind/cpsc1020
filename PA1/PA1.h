/*Zach Lindler
	PA1
	CPSC 1020, Section 2, Spring 2019
	zelindl@g.clemson.edu*/

#ifndef PA1_H
#define PA1_H value

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Parameter: 	FILE* fp: the input file
 *		int** array: the array of pointers to be read into
 *		int rows: the number of rows in the array
 *		int cols: the number of columns in the array
 *    int choice: this number is representative of which array will be read into
                  the file. Part of the function changes based on which file is
                  being read.
 *Return:	VOID
 *Purpose:	This function reads in the data from one of the input files into the given array.
 */
void readData(FILE* fp, int** array, int rows, int cols, int choice);

/*Parameters:	int rows: the number of rows in the array
 *		int cols: the number of columns in the array
 *Return:	A double pointer pointing to the 2d array
 *Purpose:	This function dynamically allocates the memory for a 2d array that holds the data from a file.
 */
int** makeArray(int rows, int cols);

/*Parameters:	int** array: the array of memory to be freed.
 *		int rows: the number of rows in the aforementioned array.
 *Return:	VOID
 *Purpose:	This function frees the memory allocated to the 2D array of memory created by the makeArray function.
 */
void destroyArray(int** array, int rows);

/*Parameters:	int** array: The array holding the data from the file.
 *		int* rArray: The array holding the row parities.
 *		int* cArray: The array holding the column parities.
 *		int rows: the number of rows in the data array.
 *		int cols: the number of columns in the data array.
 *Return: 	VOID
 *Purpose:	This function calculates the parities of the given array and stores it in the row and column parity arrays.
 */
void calcParity(int** array, int* rArray, int* cArray, int rows, int cols);

/*Parameters:	int argc: The number of command-line arguments.
 *Return: 	VOID
 *Purpose:	This function serves as a command-line argument verification. In case the user doesn't input the correct number of arguments, the program will terminate.
 */
void inputCheck(int argc);

/*Parameters:	FILE* fp: The pointer to the file in question.
 *Return:	VOID
 *Purpose:	This function checks to see if the file in question was opened correctly. If not, terminate the program.
 */
void fileCheck(FILE* fp);

/*Parameters: 	FILE* fp: The file that the data will be printed to.
 *		int** array: The pointer to the array holding the data to be printed.
 *		int* rPArr: The pointer to the array holding the row parity data.
 *		int* cPArr: The Pointer to the array holding the column parity data.
 *		int rows: The number of rows in the data array.
 *		int cols: The number of columns in the data array.
 *		int choice: Which array of data will be printed to the file.
 *Return: 	VOID
 *Purpose:	This function prints the array of data and the parity of the data to the designated output file.
*/
void printArr(FILE* fp, int** array, int* rPArr, int* cPArr, int rows, int cols, int choice);

/*Parameters:	FILE* fp: The file that the data will be printed to.
 *		int** array1: The first array to be compared.
 *		int** array2: The second array to be compared.
 *		int rows: The number of rows in the arrays.
 *		int cols: The number of columns in the arrays.
 *Return:	VOID
 *Purpose:	This function determines if there was an error during transmission between the two files. If there was, print the row and column at which the error occurred.
 */
void printError(FILE* fp, int** array1, int** array2, int rows, int cols);
#endif

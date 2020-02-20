/*Zach Lindler
	PA1
	CPSC 1020, Section 2, Spring 2019
	zelindl@g.clemson.edu*/

#include "PA1.h"

int main(int argc, char* argv[]){

	//Verify command line inputs
	inputCheck(argc);

	//Open the two input files
  	FILE* inFile1 = fopen(argv[1], "r");
  	FILE* inFile2 = fopen(argv[2], "r");

	//Verify that the input files were opened correctly.
  	fileCheck(inFile1);
  	fileCheck(inFile2);

	//Get the dimensions of the matrix from the first file.
	//Dimensions are the same for both files.
	int rows;
	int cols;
	fscanf(inFile1, "%d %d", &rows, &cols);

	//Malloc the data for both 2d arrays.
	int** numArray1=makeArray(rows, cols);
	int** numArray2=makeArray(rows, cols);

	//Read and malloc the two arrays containing the bits.
	readData(inFile1, numArray1, rows, cols, 1);
	readData(inFile2, numArray2, rows, cols, 2);

	//close the input files; they are no longer needed.
	fclose(inFile1);
	fclose(inFile2);

	//Create arrays to hold parities, and assign pointers to those arrays.
	int* rPArr1=(int*)malloc(rows*sizeof(int));
	int* rPArr2=(int*)malloc(rows*sizeof(int));
	int* cPArr1=(int*)malloc(cols*sizeof(int));
	int* cPArr2=(int*)malloc(cols*sizeof(int));

	//Calculate the parity for the following:
	//Array 1
	calcParity(numArray1, rPArr1, cPArr1, rows, cols);
	calcParity(numArray2, rPArr2, cPArr2, rows, cols);

	//Create the output file
	FILE* outFile=fopen(argv[3], "w");

	//Print the arrays and their parities to the output file.
	//First Array:
	printArr(outFile, numArray1, rPArr1, cPArr1, rows, cols, 1);
	//Second Array:
	printArr(outFile, numArray2, rPArr1, cPArr2, rows, cols, 2);
	//Print the error (if applicable) to the file.

	printError(outFile, numArray1, numArray2, rows, cols);

	//Close the output file.
	fclose(outFile);
	//Free the malloc'd data containing the file information.
	destroyArray(numArray1, rows);
	destroyArray(numArray2, rows);
	free(rPArr1);
	free(rPArr2);
	free(cPArr1);
	free(cPArr2);

	//Finished!
	return 0;
}

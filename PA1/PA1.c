/*Zach Lindler
	PA1
	CPSC 1020, Section 2, Spring 2019
	zelindl@g.clemson.edu*/

#include "PA1.h"

//Read the data from the file.
void readData(FILE* fp, int** array, int rows, int cols, int choice){
	//If we are reading in data from the second file, we don't need the two
	//numbers at the top. Therefore, we need to store them in garbage variables
	//to stow them away.
	if(choice==2){
		int foo1;
		int foo2;
		fscanf(fp, "%d %d", &foo1, &foo2);
	}
	//fprintf(stderr, " 2 %d %d\n",rows, cols);
	//Iterates through the rows
	for(int i=0;i<rows;i++){
		//Iterates through the columns
		for(int j=0;j<cols/*+1*/;j++){
			//fprintf(stderr, "%i, %i | ", i, j);
			//Scan the data contained in that location into the array.
			fscanf(fp, "%d",&array[i][j]);
			//fprintf(stderr, "%d\n", array[i][j]);
		}
	}
}

//Dynamically allocate the memory for the data.
int** makeArray(int rows, int cols){
	//Malloc the memory for the first row.
	int** array=(int**)malloc(rows*sizeof(int*));
	//Iterate through each element in the first row, and allocate memory to be
	//pointed to by the first row.
	for(int i=0;i<rows;i++){
		array[i]=(int*)malloc(cols*sizeof(int));
		//fprintf(stderr, "%p\n", array[i]);
	}
	//Return the array created.
	return array;
}

//Free the memory created by the makeArray function.
void destroyArray(int** array, int rows){
	//Iterate through each element in the first row of the array. Free the memory
	//contained there.
	for(int i=0;i<rows;i++){
		free(array[i]);
	}
	//Then free the rest of the data.
	free(array);
}

//Calculate the parity for a given array of data.
void calcParity(int** array, int* rArray, int* cArray, int rows, int cols){
	//Declare a variable that will hold the sum of a given column.
	int sum=0;
	//Iterate through the rows
	for(int i=0;i<rows;i++){
		//Reset the sum after each row.
		sum=0;
		//Then, for each column, add that location's data to the sum of that row.
		for(int j=0;j<cols;j++){
			sum+=array[i][j];
		}
		//If the sum is odd, then the parity of that row will be 1; if the sum is
		//even, then the parity of that row will be 0.
		rArray[i]=sum%2;
	}
	//Repeat the above process for the columns:
	sum=0;
	for(int k=0;k<cols;k++){
		sum=0;
		for(int l=0;l<rows;l++){
			sum+=array[l][k];
		}
		cArray[k]=sum%2;
	}
}

//Verify command line inputs.
void inputCheck(int argc){
	//If the number of command line inputs is not 4, tell the user and terminate
	//the program.
	if(argc!=4){
		fprintf(stdout,"Error: incorrect number of inputs.\n");
		exit(0);
	}
}

//Verify that a file was opened correctly.
void fileCheck(FILE* fp){
	//If a pointer to a file is null, tell the user and terminate the program.
	if(fp==NULL){
		fprintf(stdout, "Error: File failed to open correctly.\n");
		exit(0);
	}
}

//Print the data in an array.
void printArr(FILE* fp, int** array, int* rPArr, int* cPArr, int rows, int cols,
							int choice){
	//If choice equals 1, then the function will print the initial data.
	//Print the header accordingly:
	if(choice==1){
		fprintf(fp, "ORIGINAL MESSAGE:\n");
	}
	//And if choice equals 2, the function will print the data after transmission.
	if(choice==2){
		fprintf(fp, "MESSAGE AFTER TRANSMISSION:\n");
	}
	//Iterate through the rows
	for(int i=0;i<rows;i++){
		//Iterate through the columns
		for(int j=0;j<cols;j++){
			//And print the data for each element in the given row.
			fprintf(fp, "%i ", array[i][j]);
		}
		//Add the | character before printing the row parity,
		fprintf(fp, " | %i\n", rPArr[i]);
	}
	//Line break before printing column parities.
	fprintf(fp,"---\n");
	//Iterate through the columns.
	for(int k=0;k<cols;k++){
		//Print the column parities.
		fprintf(fp, "%i ", cPArr[k]);
	}
	//End on a newline.
	fprintf(fp, " | 0\n\n");
}

//Print the location of the error, if applicable.
void printError(FILE* fp, int** array1, int** array2, int rows, int cols){
	//As a starter, assume that there is no error within the files.
	int noError=0;
	//Iterate through the rows
	for(int i=0;i<rows;i++){
		//Iterate through the columns
		for(int j=0;j<cols;j++){
			//If the data in a given location in the first array does not equal the
			//data in the same location in the second aray,
			if(array1[i][j]!=array2[i][j]){
				//Print the location of the data to the file passed into the function.
				fprintf(fp, "An error was found in the file, the error is in");
				fprintf(fp, " Row %i Column %i.\n", (i+1), (j+1));
				//Now that noError != 0, this means we have found an error.
				noError=1;
			}
		}
	}
	//If we didn't find an error
	if(noError==0){
		//Inform the user via printing this message to the file.
		fprintf(fp, "Transmission was a success, no errors were found.\n");
	}
}

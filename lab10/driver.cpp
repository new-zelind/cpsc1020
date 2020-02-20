/*Zach Lindler
  zelindl
  Lab 10
  Section 2
  Hollis Liu & Emily Merritt*/

#include "lab10.h"
using namespace std;

int main(int argc, char const *argv[]) 
{

  /*Check to determine if the appropriate number of files were passed to the 
   *command line.*/
	if(argc!=3){
		cout<<"Error: incorrect number of command line arguments given."<<endl;
		return -1;
	}

  	/*Create the input and output stream, then check to make sure the files
	openedappropriately. If the file did not open, print a statement stating which
	file did not open appropriately. */
	ifstream inFile;
	inFile.open(argv[1]);
	if(!inFile.is_open()){
		cout<<"Error: input file not opened correctly."<<endl;
		return -1;
	}

	ofstream outFile;
	outFile.open(argv[2]);
	if(!outFile.is_open()){
		cout<<"Error: output file not opened correctly."<<endl;
		return -1;
	}

	/*Call the following functions:
     	 *howMany
     	 *allocateMemory
     	 *readData
     	 *bubbleSort
    	 *printData*/
    	
	int num=howMany(inFile);
	int* arr=allocateMemory(num);
	readData(inFile, arr, num);
	bubbleSort(arr, num);
	printData(outFile, arr, num);

    	/*deallocate the memory and close the input and output stream files*/
    
	free(arr);
	inFile.close();
	outFile.close();


  return 0;
}



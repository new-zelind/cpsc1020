/**************
 Zach Lindler
 zelindl
 Lab 7
 CPSC 1021 - 002
 Hunter Ross
**************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char argv*[]){
	
	//Verify command line arguments.
	if(argc!=3){
		cout<<"Please specify an input and output file."<<endl;
		return 0;
	}
	
	//Open the input file and check to see if it was opened successfully.
	ifstream inputFile;
	inputFile.open(argv[1]);
	
	while(input >> 10){
		
	}

	
	

	return 0;
}

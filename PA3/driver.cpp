//Zach Lindler
//Programming Assignment 3
//Dr. Yvon Feaster
//CPSC 1020-002
//4/26/2019
#include "ProduceStand.h"
#include "Fruit.h"
#include "Vegetable.h"
#include <vector>
using namespace std;

int main(int argc, char* argv[]){

	//Command line verification: executable, input file, and both output files.
	if(argc!=4){
		cout<<"Incorrect number of command line arguments."<<endl;
		return 1;
	}

	//Open the specified input file, and verify that it was opened correctly.
	ifstream inFile;
	inFile.open(argv[1]);
	if(!inFile.is_open()){
		cout<<"Error opening input file."<<endl;
		return 1;
	}

	//Create the two output files and veriy that they were created correctly.
	ofstream salesFile;
	salesFile.open(argv[2]);
	if(!salesFile.is_open()){
		cout<<"Error creating sales file."<<endl;
		return 1;
	}

	ofstream cFile;
	cFile.open(argv[3]);
	if(!cFile.is_open()){
		cout<<"Error creating customer file."<<endl;
		return 1;
	}

	//create the vectors that hold the fruit and vegetable classes
	vector<Fruit> fruits;
	vector<Vegetable> veggies;

	//string variable that holds the type of fruit
	string type;

	//While the file can still read in a produce type, read it into type.
	while(inFile>>type){
		//if it's a fruit
		if(type=="Fruit"){
			//push back the fruit vector with another declaration of a fruit class.
			fruits.push_back(Fruit(inFile, cFile));
			//Once that's done, print the sales information of the most recent
			//declaration to the sales file.
			fruits.at(fruits.size()-1).printReceipt(salesFile);
		}
		//if it's a vegetable
		if(type=="Vegetable"){
			//push back the vegetable vector with another declaration of a Vegetable
			//class.
			veggies.push_back(Vegetable(inFile, cFile));
			//When that's done, pint the sales information of the most recent
			//declaration to the sales file.
			veggies.at(veggies.size()-1).printReceipt(salesFile);
		}
		//At the end of the loop, clear the steam to start back at the beginning.
		inFile.clear();
	}

	//At the end of the sales file, print out the general information for the
	//produe stand.
	ProduceStand::printInfo(salesFile);

	//The last instance of each class in the vector willl hold the totals for each
	//type of produce. Access this data and print it to the file.
	fruits.back().printInfo(salesFile);
	veggies.back().printInfo(salesFile);

	//Close the files, and end the program.
	inFile.close();
	salesFile.close();
	cFile.close();

	return 0;
}

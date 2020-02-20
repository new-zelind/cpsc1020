#include "BookStore.h"

int main(int argc, const char* argv[]){

  //Command line argument verification
  if(argc!=3){
    cout<<"Error: incorrect number of command line arguments given."<<endl;
    return -1;
  }

  //Open the input file, and verify that it was opened correctly.
  ifstream inFile;
  inFile.open(argv[1]);
  if(!inFile.is_open()){
    cout<<"Error: Input file not opened properly."<<endl;
    return -1;
  }

  //Open the output file, and verify that it was created correctly.
  ofstream outFile;
  outFile.open(argv[2]);
  if(!outFile.is_open()){
    cout<<"Error: Output file not created properly."<<endl;
    return -1;
  }

  //Declare the Book Store class
  BookStore bookStore;

  //Read in the inventory from the input file.
  bookStore.readInventory(argv[1]);
  bookStore.printInventory(outFile);

  //Close the input file
  inFile.close();

  return 0;
}

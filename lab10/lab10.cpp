/*Zach Lindler
  zelindl
  Lab 10
  Section 2
  Hollis Liu & Emily Merritt*/

#include "lab10.h"


/*******************************************************************************
 * This function determines how many numbers are in the input file so that the
 * appropriate amount of memory can be dynamically allocated. This function also
 * returns the input file reference to the beginning of the file allowing the
 * user, in another function read and store the data.
 * Parameter: iostream reference variable that represents the input file that 
 * has been opened and validate.
 * Return: return the number of numbers in the file.
 ******************************************************************************/
int howMany(ifstream& input)
{
	int howMany, check;
	//While data can still be read from the file,
	while(input>>check){
		//Increment the number of integers by 1 eac time;
		howMany++;
	}
	
	//Then return this number.
	return howMany;
}

/*******************************************************************************
 * This function dynamically allocates the memory for the array that will hold
 * the values that will be sorted.
 * Parameter: int - this represents the number of integers that will be in the 
 * array.
 * Return:  Return the address of the allocated memory.
 ******************************************************************************/
int* allocateMemory(int num)
{
	//All you need to do is return the allocated memory.
	return new int [num];
}

/*******************************************************************************
 * This function will read the integers from the input file and store them in 
 * the array passed to the function.
 * Parameter: iostream reference variable that represents the input file  and 
 * an array to store the data. Since you know the number of integers in the file
 * you can pass the length variable to the function then use a for loop
 * to read in the data and store it in the array.
 * Return: void no return value.
 ******************************************************************************/
void readData(ifstream& in, int* arr, int len)
{
	//reset the file stream back to the beginning
	in.clear();
	in.seekg(0, ios::beg);
	//read through the file and put the data into the array
	for(int i=0;i<len;i++){
		in>>arr[i];
	}
}

/*******************************************************************************
 * This function sorts the integers stored in an array.
 * Parameter: an array to is storing the data and the size of the array.
 * Return: void no return value.
 ******************************************************************************/
void bubbleSort(int* arr, int length)
{
	int numSwaps=1;
	//While a swap was created in the loop,
	while(numSwaps!=0){
		//Reset the counter to 0.
		numSwaps=0;
		//Then, iterate through the array of numbers.
		for(int i=0;i<length-1;i++){
			//If the leftmost value is greater than the rightmost
			//value,
			if(arr[i]>arr[i+1]){
				//Swap the values and increment the number of
				//swaps by one.
				swap(arr[i], arr[i+1]);
				numSwaps++;				
			}
		}
	}
}

/*******************************************************************************
 * This function swaps the arr i and arr i+1
 * Parameter: The array that holds the data to be swapped.  int that represents 
 * the ith  ith + 1 positions that need to be swapped.
 * Return: void - no return
*******************************************************************************/
void swap(int* first, int* second )
{
	//Declare a pointer to the first value.
	int* temp=first;
	//Assign the first value to the second value's place
	first=second;
	//Then dereference the pointer to assign the second value to the first
	//value's place.
	second=temp;
}

/*******************************************************************************
 * This function prints the values stored in arr 
 * Parameter: output file, the array being printed and the size of the array.
 * Return: void - no return
*******************************************************************************/

void printData(ofstream& out, int* const arr, int len)
{
	for(int i=0;i<len;i++){
		out<<*(arr+i)<<endl;
	}
}

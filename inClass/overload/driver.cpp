#include <iostream>
#include "overload2.h"
using namespace std;

NumberArray makeArray();

int main(){
	cout<<"1\n";
	NumberArray first;
	cout<<"2\n";
	first = makeArray();
	cout<<"3\n";
	NumberArray second = makeArray();
	cout<<"4\n";

	cout<<endl<<"The object's data is: ";
	first.print();
	cout<<"5"<<endl;

	return 0;
}

NumberArray makeArray(){
	NumberArray nArr(5, 10.5);
	return nArr;
}

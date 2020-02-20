#include "MyString.h"

MyString::MyString(){
	this->data = nullptr;
	this->size = 0;
}

MyString::MyString(const char* str){
	this->data = new char[strlen(str)+1];
	this->size = strlen(str);
	strcpy(this->data, str);
}

MyString::MyString(const MyString& copy){
	this->size = copy.size;
	this->data = new char[size+1];
	strcpy(this->data, copy.data);
}

MyString::~MyString(){
	delete [] this->data;
}

int MyString::len() const{
	return this->size;
}

MyString& MyString::operator= (const MyString& right){
	if(this->data!=right.data){
		if(this->size>0){ delete [] this->data; }
		this->size = right.size;
		this->data = new char[size+1];
		strcpy(this->data, right.data);
	}
	return *this;
}

MyString& MyString::operator= (const char* str){
	if(this->data!=str){
		if(this->size>0){delete [] this->data; }
		strcpy(this->data, str);
		this->size=strlen(str);
	return *this;
	}
}

MyString& MyString::operator+= (const MyString& str){
	char* temp = new char[this->size];
	strcat(temp, this->data);
	delete [] this->data;
	this->size+=strlen(str);
	this->data = new char [(this->size)+1];
	strcat(this->data, temp);
	strcat(this->data, str);
	return *this;
}

MyString operator+ (const MyString& left, const MyString& right){
	
}

MyString operator+ (const MyString& left, const char* str){
	return (left + (MyString NewString(str));
}

MyString operator+ (const char* str, const MyString& right){
	return (MyString NewString(str) + right);
}
/*
bool MyString::operator==(const MyString& ) const {
	
}

bool MyStrin::operator!=(const Mystring& ) const {

}

bool operator<  (const MyString& left, const MyString& right){

}

bool operator>  (const MyString& left, const MyString& right){

}

bool operator<= (const MyString& left, const MyString& right){

}

bool operator>= (const MyString& left, const MyString& right){

}
*/


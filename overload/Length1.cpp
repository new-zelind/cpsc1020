#include "Length1.h" 

//**********************************************
// Overloaded stream extraction operator >>    *
//**********************************************
istream &operator>>(istream &in, Length &a)
{
    // Prompt for and read the object data
    int feet,  inches;
    cout << "Enter feet: ";
    in >> feet;
    cout << "Enter inches: ";
    in >> inches;

    // Modify the object a with the data and return
    a.setLength(feet, inches);
    return in;
}

//*********************************************
// Overloaded stream insertion operator <<    *
//*********************************************
ostream &operator<<(ostream& out, Length a)
{
    out << a.getFeet() << " feet, " << a.getInches() << " inches";
    return out;
}

//***********************************
// Overloaded prefix ++i operator    *
//***********************************
Length Length::operator++()
{
    len_inches ++;
    return *this;
}

//***********************************
// Overloaded postfix i++ operator   *
//***********************************
Length Length::operator++(int)
{
    Length temp = *this;
    len_inches ++;
    return temp;
}

//*************************************
// Overloaded operator -              *
//*************************************
Length operator+(Length a, Length b)
{
    return Length(a.len_inches + b.len_inches); 
}

//*************************************
// Overloaded  operator -             *
//*************************************
Length operator-(Length a, Length b)
{
    return Length(a.len_inches - b.len_inches);
}

//************************************
// Overloaded operator ==            *
//************************************
bool operator==(Length a, Length b)
{
    return a.len_inches == b.len_inches;
}

//************************************
// Overloaded operator <             *
//************************************
bool operator<(Length a, Length b)
{
    return a.len_inches < b.len_inches;
}

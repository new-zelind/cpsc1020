#include <iostream>
using namespace std;

class NumberArray
{
private:
  double *aPtr;
  int arraySize;
public:
  // Copy assignment and copy constructor
  NumberArray& operator=(const NumberArray &right);    
  NumberArray(const NumberArray &);
  
  // Default constructor and regular constructor
  NumberArray();
  NumberArray(int size, double value);
  
  // Destructor
  ~NumberArray(); 
  
  void print() const;
  void setValue(double value);
};

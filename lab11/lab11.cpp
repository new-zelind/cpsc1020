#include <iostream>
#include "MyString.h"

using namespace std;

int main(int argc, char const *argv[]) {
  MyString detective("Hello");
  MyString hello = (detective + ",");

  detective = "Sherlock";
  detective = "Mr. " + detective;
  //detective = detective + " Holmes";
  detective += " Holmes";
  //cout << hello << " " << detective << endl;
  //cout << "String length is: "
  //     << (hello + " " + detective).len()
  //     << endl;
  //cout << "Is Sherlock same as Poirot ?" << endl;
  //MyString sherlock("Sherlock");
  //MyString poirot("Poirot");
  //bool isEqual = sherlock == poirot;
  //cout << boolalpha;
  //cout << isEqual << endl;
  //cout << "Then Sherlock is different than Poirot ?" << endl;
  //cout << boolalpha;
  //bool notEqual = sherlock != poirot;
  //cout << notEqual << endl;

  //cout << "The result of comparing string " << sherlock << "and " << poirot << ": " << endl;
  //cout << "\n Sherlock < Poirot yields  "<< boolalpha << (sherlock < poirot) << endl;
  //cout << "\n Sherlock > Poirot yields  "<< boolalpha << (sherlock > poirot) << endl;
  //cout << "\n Sherlock <= Poirot yields  "<< boolalpha << (sherlock <= poirot) << endl;
  //cout << "\n Sherlock >= Poirot yields  "<< boolalpha << (sherlock >= poirot) << endl;
  return 0;
}

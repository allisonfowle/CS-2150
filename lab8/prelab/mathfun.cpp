/*
Allison Fowle
CS 2150
11/1/2021
mathfun.cpp
*/

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

// routines from mathlib.s
extern "C" int product (int, int);
extern "C" int power (int, int);

// Purpose: This main program produces the product and power 
// two positive integers. power is calculated through x times
// y and power is x^y

int main () {
  // declare the local variables
  int x;
  int y;
  int pro;
  int pow;

  // enter user input
  cout << "Enter integer 1: " << endl;
  cin >> x;
  cout << "Enter integer 2: " << endl;
  cin >> y;

  // calculate product and power and print out results
  pro = product(x, y);
  pow = power(x, y);
  cout << "Product: " << pro << endl;
  cout << "Power: " << pow << endl;
  return 0;
}
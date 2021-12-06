/*
Allison Fowle
acf6nb
9/17/2021
testprelab4.cpp
*/

#include <iostream>
#include "prelab4.h"
#include <string>
using namespace std;

int main() {
	prelab4 test;
	string token;
	cout << "Input" << endl;
	cin >> token;
	int x = atoi(token.c_str());

	test.sizeOfTest();
	test.overflow();
	test.outputBinary(x);

	return 0;
}
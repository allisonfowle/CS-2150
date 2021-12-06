/*
Allison Fowle
acf6nb
9/17/2021
prelab4.cpp
*/

#include <iostream>
#include <climits> //this is for overflow() UINT_MAXS

#include <cmath>
#include <string>
using namespace std;

void sizeOfTest();
void overflow();
void outputBinary(unsigned int x);

int main() {
	string token;
	cin >> token;
	int x = atoi(token.c_str());

	sizeOfTest();
	overflow();
	outputBinary(x);
	cout << endl;
	return 0;
}


//returns the size, in bytes, of a given variable or data type
void sizeOfTest() {
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of bool: " << sizeof(bool) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of char*: " << sizeof(char*) << endl;
	cout << "Size of double*: " << sizeof(double*) << endl;
}

//
void overflow() {
	unsigned int x = UINT_MAX + 1;
	cout << "4294967295 + 1 = " << x << endl;
}

//
void outputBinary(unsigned int x) {
	int binary[32];
	for (int j = 0; j < 32; j++) {
		binary[j] = 0;
	}
	int i = 0;
	string s = "";
	while (x > 0) {
		binary[i] = x % 2;
		x = x / 2;
		i++;
	}


	for (int a = 31; a >= 0; a--) {
		if(a % 4 == 0 && a != 0) {
			//s.insert(" ");
			cout << binary[a] << " ";
		}
		else {
			cout << binary[a];
		}
	}
}
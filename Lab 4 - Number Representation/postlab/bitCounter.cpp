/*
Allison Fowle
acf6nb
9/23/2021
bitCounter.cpp
*/

#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
using namespace std;

//prototypes
int bitCounter(int n);
string baseConverter(string num, int startBase, int endBase);


int main(int argc, char *argv[]) {
	if (argc != 5) {//error if command prompt is more or less than 5 arguments
		cout << "Error!" << endl;
		exit(1);
	}
	//string s;

	//convert command line parameters to parameters of functions below
	int n = atoi(argv[1]);
	string num = argv[2];
	int startBase = atoi(argv[3]);
	int endBase = atoi(argv[4]);
	cout << n << " has " << bitCounter(n) << " bit(s)" << endl;
	cout << num << " (base " << startBase << ") = " << baseConverter(num, startBase, endBase) << " (base " << endBase << ")" << endl;
	
	return 0;
};


//returns the size, in bytes, of a given variable or data type
int bitCounter(int n) {
	if (n % 2 == 0) //if n is even
		return n / 2;
	else //if n is odd. automatic floor in c++
		return bitCounter(n / 2) + 1;
}

string baseConverter(string num, int startBase, int endBase) {
	//declaration of variables
	int converted = 0; 
	int exponent = 0; //used in power function
	int remainder;
	string s;

	//convert to base 10
	for (int i = num.length() - 1; i >= 0; i--) {
		if(isdigit(num[i])) {//if the input IS a digit
			int multiplier = num[i] - 48;
			int y = multiplier * pow(startBase, exponent);
			exponent++;
			converted+=y;
		}
		else if (!isdigit(num[i])) {//if the input is NOT a digit. use ascii table
			int multiplier = num[i] - 'A' + 10;
			int z = multiplier * pow(startBase, exponent);
			exponent++;
			converted+=z;
		}
	}//end for loop



	//convert to another radix
	if (endBase != 10) {
		while (converted > 0) {
			remainder = converted % endBase;
			s = to_string(remainder) + s;
			converted = converted / endBase;
		}//end while
		return s;
	}//end if
	return to_string(converted);
}
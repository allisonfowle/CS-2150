/*
Allison Fowle
acf6nb
9/12/2021
testPostfixCalc.cpp
*/

#include <iostream>
#include <vector>
#include <stack>
#include "postfixCalculator.h"
#include <string>
#include <cctype>
using namespace std;

int main() {
	string token;
	int operand;
	//stack<int> theStack;
	postfixCalculator calc;
	while (cin >> token) {
		if (token == "+")
			calc.add();
		if (token == "-")
			calc.subtract();
		else if (token != "+" && token != "-") {
			operand = stoi(token);
			calc.pushNumber(operand);
		}
	}//end while
	cout << calc.top();
	return 0;	
};

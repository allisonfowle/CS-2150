/*
Allison Fowle
acf6nb
9/12/2021
testPostfixCalc.cpp
*/

#include <iostream>
#include "postfixCalculator.h"
#include <string>
using namespace std;

int main() {
	string token;
	int operand;
	postfixCalculator calc;
	while (cin >> token) {
		if (token == "+") {
			calc.add();
		} else if (token == "-") {
			calc.subtract();
		} else if (token == "*") {
			calc.multiplication();
		} else if (token == "/") {
			calc.division();
		} else if (token == "~") {
			calc.negation();
		} else if (token != "+" && token != "-" && token != "*" && token != "/" && token != "~") {
			operand = stoi(token);
			calc.pushNumber(operand);
		}
	}//end while
	cout << calc.topValue();
	return 0;
};

/*
Allison Fowle
acf6nb
9/12/2021
postfixCalculator.h
*/


#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "Stack.h"
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
using namespace std;


class postfixCalculator {
public: 
	//default constructor
	postfixCalculator();

	//destructor
	~postfixCalculator();

	//does addition of top 2 values in the stack
	void add();

	// does subtraction of top 2 values in the stack
	void subtract();

	void multiplication();

	void division();

	void negation();

	int topValue();

	//helper method
	void pushNumber(int operand);


private:
	int count;
	Stack theStack;
};



#endif
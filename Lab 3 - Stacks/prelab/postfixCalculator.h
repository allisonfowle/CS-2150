/*
Allison Fowle
acf6nb
9/12/2021
postfixCalculator.h
*/


#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class postfixCalculator {
public: 
	//default constructor
	postfixCalculator();

	//copy constructor


	//destructor
	~postfixCalculator();

	// does subtraction of top 2 values in the stack
	void subtract();

	//does addition of top 2 values in the stack
	void add();

	//helper method
	void pushNumber(int operand);

	//checks if stack is empty. if elements are in stack return false, if not return true
	bool empty() const;

	//returns size of stack
	int size();

	//returns the top element of the stack. if stack is empty, prints error message and exits program
	int top() const;

	//inserts element at the top of the stack
	void push(int x);

	//removes the top element of the stack. if stack is empty, prints error message and exits program.
	void pop();

	// does the operators of the postfix calculator
	void operators();

private:
	stack<int> theStack;
	int count;

};



#endif
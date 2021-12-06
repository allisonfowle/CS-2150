/*
Allison Fowle
acf6nb
9/12/2021
postfixCalculator.cpp
*/


#include <iostream>
#include "postfixCalculator.h"
#include "Stack.h"
using namespace std;

//default constructor
postfixCalculator::postfixCalculator() {
	count = 0;
}

//destructor
postfixCalculator::~postfixCalculator() {

}

//helper method for operand when called in main method
void postfixCalculator::pushNumber(int operand) {
	theStack.push(operand);
	count++;
}

int postfixCalculator::topValue() {
	return theStack.top();
}


void postfixCalculator::add() {
	int a = theStack.top();
	theStack.pop();
	int b = theStack.top();
	theStack.pop();
	int c = b + a;
	theStack.push(c);
}

void postfixCalculator::subtract() {
	int x = theStack.top();
	theStack.pop();
	int y = theStack.top();
	theStack.pop();
	int z = y - x;
	theStack.push(z);
}

void postfixCalculator::multiplication() {
	int g = theStack.top();
	theStack.pop();
	int h = theStack.top();
	theStack.pop();
	int i = h * g;
	theStack.push(i);
}

void postfixCalculator::division() {
	int j = theStack.top();
	theStack.pop();
	int k = theStack.top();
	theStack.pop();
	int l = k / j;
	theStack.push(l);
}

void postfixCalculator::negation() {
	int m = theStack.top();
	int n = m * - 1;
	theStack.push(n);
}



/*
Allison Fowle
acf6nb
9/12/2021
postfixCalculator.cpp
*/


#include <iostream>
#include <vector>
#include "postfixCalculator.h"
#include <stack>
#include <string>
using namespace std;

//default constructor
postfixCalculator::postfixCalculator() {
	count = 0;
}

//destructor
postfixCalculator::~postfixCalculator() {

}

//returns the top element of the stack
int postfixCalculator::top() const {
	return theStack.top();
}

//helper method for operand when called in main method
void postfixCalculator::pushNumber(int operand) {
	theStack.push(operand);
	count++;
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
	int d = theStack.top();
	theStack.pop();
	int e = theStack.top();
	theStack.pop();
	int f = e - d;
	theStack.push(f);
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

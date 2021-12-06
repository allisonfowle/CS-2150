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


//returns the top element of the stack. if stack is empty, prints error message and exits program
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
	int x = theStack.top();
	theStack.pop();
	int y = theStack.top();
	theStack.pop();
	int z = y - x;
	theStack.push(z);
}



// POST LAB



// //checks if stack is empty. if elements are in stack return false, if not return true
// bool postfixCalculator::empty() const {
// 	if (theVector.size() == 0) 
// 		return true;
// 	else
// 		return false;
// }

// //returns size of stack
// int postfixCalculator::size() {
// 	return count;
// }

//returns the top element of the stack. if stack is empty, prints error message and exits program
// void postfixCalculator::top() const {
// 	if (theStack.size() == 0) 
// 		cout << "Error: stack is empty, cannot return a top value of stack." << endl;
// 	else
// 		theStack.top();
// }

// //inserts element at the top of the stack
// void postfixCalculator::push(int x) {
// 	count++;
// 	theVector.push_back(x);
// }

// //removes the top element of the stack. if stack is empty, prints error message and exits program.
// void postfixCalculator::pop() {
// 	//theVector--;
// 	if (theVector.size() == 0)
// 		cout << "Error: stack is empty; cannot remove the top element of the stack." << endl;
// 	else 
// 		theVector.pop_back();
// 		count--;
// }










//postfix calculator methods with operators + and -
// int postfixCalculator::operators() {
// 	while (token) {
// 	//for (int i = 0; i < theVector.size(); i++) {
// 		// if (token == ) 
// 		// 	int.push();
// 		if (token == "+")
// 			int x = theStack.top();
// 			int y = theStack.top() - 1;
// 			int z = (y + x);
// 			z.push();
// 		if (token == "-")
// 			int a = theStack.top();
// 			int b = theStack.top() - 1;
// 			int c = (b - a);
// 			c.push();
// 		else 
// 			token.push();
// 	} //end while
// 	return theStack.pop();
// 	//cout << token << endl;
// }
/*
Allison Fowle
acf6nb
9/14/2021
Stack.cpp
*/

#include <iostream>
#include "Stack.h"
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include "postfixCalculator.h"
using namespace std;

//default constructor
Stack::Stack() {
	count = 0;
}

//destructor
Stack::~Stack() {}

//checks if stack is empty. if elements are in stack return false, if not return true
bool Stack::empty() const {
	if (count == 0) 
		return true;
	else
		return false;
}

//returns size of stack
int Stack::size() {
	return count;
}

//returns the top element of the stack. if stack is empty, prints error message and exits program
int Stack::top() {
	return theStack.last().retrieve();
}

//inserts element at the top of the stack
void Stack::push(int x) {
	theStack.insertAtTail(x);
	count++;
}

//removes the top element of the stack. 
void Stack::pop() {
	int x = top();
	theStack.remove(x);
	count--;
}









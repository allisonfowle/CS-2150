/*
Allison Fowle
acf6nb
9/14/2021
stack.h
*/


#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;


class Stack {
public: 
	//default constructor
	Stack();

	//destructor
	~Stack();

	//checks if stack is empty. if elements are in stack, return false.
	bool empty() const;

	//returns size of stack
	int size();

	//returns the top element of the stack. if stack is empty, prints error message
	int top();

	//inserts element at the top of the stack
	void push(int x);

	//removes the top element of the stack. if the stack is empty, prints error message
	void pop();

private:
	int count;
	List theStack;
	friend class List;
	friend class ListNode;
};

#endif
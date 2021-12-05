/*
Allison Fowle
acf6nb
9/5/2021
ListItr.cpp
*/

#include <iostream>
#include "ListItr.h"
#include "List.h"
#include "ListNode.h"

using namespace std;


//default constructor
ListItr::ListItr() {
	current = NULL;
}

//constructor
ListItr::ListItr(ListNode* theNode) {
	current = theNode;
}


bool ListItr::isPastEnd() const {
	if (current->next == NULL)
		return true;
	else
		return false;
}

bool ListItr::isPastBeginning() const {
	if (current->previous == NULL)
		return true;
	else
		return false;
}

int ListItr::retrieve() const {
	return current->value; //return value at current position in list
}


void ListItr::moveForward() {
	if (!isPastEnd())
		current = current->next;
}

void ListItr::moveBackward() {
	if (!isPastBeginning())
		current = current->previous;
}

/*
Allison Fowle
acf6nb
9/5/2021
List.cpp
*/

#include <iostream>
#include "List.h"
using namespace std;


//List node constructor
List::List() {
	tail = new ListNode();
	head = new ListNode();
	tail->next = NULL;
	head->previous = NULL;
	tail->previous = head;
	head->next = tail;
	count = 0;
}

// deconstructor
List::~List() {}

//List function insert a node at the tail of the list
void List::insertAtTail(int x) {
	ListNode* newListNode = new ListNode();
	count++;
	newListNode->value = x;
	newListNode->next = tail;
	newListNode->previous = tail->previous;
	tail->previous->next = newListNode;
	tail->previous = newListNode;
}


ListItr List::first() {
	ListItr newListItr(head->next);
	return newListItr;
}

ListItr List::last() {
	ListItr newListItr2(tail->previous);
	return newListItr2;
}

ListItr List::find(int x) {
	return ListItr();
}

//Return the private variable count in h file from List
int List::size() const {
	return count;
}

//If the list is empty, return true
bool List::isEmpty() const {
	if (size() == 0)
		return true;
	else
		return false;
} 

void List::insertAfter(int x, ListItr position) {
	ListNode* newListNode2 = new ListNode(); //newListNode2 pointer to the a list node
	newListNode2->value = x; //the newListNode2 points to the value from ListNode function
	newListNode2->next = position.current->next; 
	newListNode2->previous = position.current;
	position.current->next->previous = newListNode2;
	position.current->next = newListNode2;
}

void List::insertBefore(int x, ListItr position) {
	ListNode* newListNode3 = new ListNode();
	newListNode3->value = y;
	newListNode3->previous = position.current->previous;
	newListNode3->next = position.current;
	position.current->previous->next = newListNode3;
	position.current->previous = newListNode3;
}

void List::makeEmpty() {

}
void List::remove(int x) {

}


void printList(List& source, bool forward) {
	if (forward == true) {
		ListItr iterate = ListItr(source.first());
		while (! (iterate.isPastEnd())) {
			cout << iterate.retrieve() << " ";
			iterate.moveForward();
		}
	cout << endl;
	}
	else {
		ListItr iterate = ListItr(source.last());
		while (! (iterate.isPastBeginning())) {
			cout << iterate.retrieve() << " ";
			iterate.moveBackward();
		}
	}

	cout << endl;
}



// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}
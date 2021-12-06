/*
Allison Fowle
acf6nb
9/1/2021
LifeCycle.cpp
*/

#include <iostream>
#include <string>
#include "LifeCycle.h"
using namespace std;

// Define the member functions we declared above
// Remember: member functions are defined as Class::method()

// Constructors and destructors - no return types
MyObject::MyObject() {
    // Important: notice how we don't define 'name' or 'id' here
    // Instead, we're setting the variables that we declared in MyObject
    name = "--default--";
    id = ++numObjs;
    cout << "MyObject Default constructor:   " << *this << endl;
}

MyObject::MyObject(string n) {
    name = n;
    id = ++numObjs;
    cout << "MyObject Parameter constructor: " << *this << endl;
}

MyObject::MyObject(const MyObject& rhs) {
    name = rhs.name;
    id = ++numObjs;
    cout << "MyObject Copy constructor:      " << *this << endl;
}

MyObject::~MyObject() {
    cout << "MyObject Destructor:            " << *this << endl;
}

// Regular methods, with return types
string MyObject::getName() const {
    return name;
}

void MyObject::setName(const string& newName) {
    name = newName;
}

// Let cout know how to print MyObjects
ostream& operator<<(ostream& output, const MyObject& obj) {
    // output in format: ("object name", id)
    return output << "(\"" << obj.name << "\", " << obj.id << ")";
}

// Static variables
int MyObject::numObjs = 0;  // static member for all objects in class
static MyObject staticObj("I'm static, outside of main");

// Define the functions we declared earlier
int cmpMyObj(const MyObject o1, const MyObject o2) {
    string name1 = o1.getName(), name2 = o2.getName();
    if (name1 == name2) {
        return 0;
    } else if (name1 < name2) {
        return -1;
    } else {
        return 1;
    }
}

MyObject getMaxMyObj(const MyObject o1, const MyObject o2) {
    string name1 = o1.getName(), name2 = o2.getName();
    if (name1 >= name2) {
        return o1;
    } else {
        return o2;
    }
}

void swapMyObj(MyObject& o1, MyObject& o2) {
    MyObject tmp(o1);
    o1.setName(o2.getName());
    o2.setName(tmp.getName());
}
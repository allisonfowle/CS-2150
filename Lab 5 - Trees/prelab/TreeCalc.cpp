/*
Allison Fowle
acf6nb
TreeCalc.cpp
10/2/2021
*/

// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if(tree->left != NULL) 
        cleanTree(tree->left);
    if (tree->right != NULL)
        cleanTree(tree->right);
    delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    TreeNode *tree = new TreeNode(val);
    //if value is an operator
    if (val == "+" || val == "-" || val == "*" || val == "/") {
        TreeNode *right = expressionStack.top();
        expressionStack.pop();
        TreeNode *left = expressionStack.top();
        expressionStack.pop();
        tree->right = right;
        tree->left = left;
        expressionStack.push(tree);
    }
    //if value is an operand
    else
        expressionStack.push(tree);
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    if (tree == NULL)
        return;
    if (tree != NULL) {
        cout << tree->value + " ";
        if (tree->left != NULL) 
            printPrefix(tree->left);
        if (tree->right != NULL) 
            printPrefix(tree->right);
    }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    if (tree == NULL)
        return;
    if (tree->left != NULL) {
        cout << "(";
        printInfix(tree->left);
    }
    cout << " " << tree->value << " ";
    if (tree->right != NULL) {
        printInfix(tree->right);
        cout << ")";
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    if (tree == NULL)
        return;
    //if left child of tree is not null, print left child
    if (tree->left != NULL) 
        printPostfix(tree->left);
    //if right child of tree is not null, print right chilld
    if (tree->right != NULL)
        printPostfix(tree->right);
    //add value of tree to a string and add a space in between each printed value
    cout << tree->value << " ";
}   

// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
//use code from lab 3
int TreeCalc::calculate(TreeNode* tree) const {
    //if node value is +, do addition operation on last two nodes
    if (tree->value == "+") {
        int x = calculate(tree->left);
        int y = calculate(tree->right);
        return (x + y);
    }
    //if node value is -, do subtraction on last two nodes
    else if (tree->value == "-") {
        int x = calculate(tree->left);
        int y = calculate(tree->right);
        return (x - y);
    }
    //if node value is *, multiply last two nodes
    else if (tree->value == "*") {
        int x = calculate(tree->left);
        int y = calculate(tree->right);
        return (x * y);
    }
    //if node value is /, divide last two nodes
    else if (tree->value == "/") {
        int x = calculate(tree->left);
        int y = calculate(tree->right);
        return (x / y);
    }
    else 
        return stoi(tree->value.c_str()); 

    //after calculation, return final value of root node :)
    return theTree.top();
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int x = 0;
    x = calculate(expressionStack.top());
    cleanTree(expressionStack.top());
    expressionStack.pop();
    return x;
}





        
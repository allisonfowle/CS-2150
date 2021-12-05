/*
Allison Fowle
acf6nb
10/4/2021
BinaryNode.cpp
*/

#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::BinaryNode(const string &x, BinaryNode* node1, BinaryNode* node2) {
    value = x;
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
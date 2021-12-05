/*
Allison Fowle
acf6nb
AVLNode.cpp
10/5/2021
*/

#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::AVLNode(const string &x, AVLNode* node1, AVLNode* node2) {
    value = x;
    left = NULL;
    right = NULL;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
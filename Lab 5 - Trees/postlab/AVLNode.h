/*
Allison Fowle
acf6nb
AVLNode.h
10/5/2021
*/

#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
    AVLNode();
    AVLNode(const string &x, AVLNode* node1, AVLNode* node2);
    ~AVLNode();

    string value;
    AVLNode* left;
    AVLNode* right;
    int height;

    friend class AVLTree;
};

#endif
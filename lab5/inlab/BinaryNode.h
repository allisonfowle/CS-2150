/*
Allison Fowle
acf6nb
10/4/2021
BinaryNode.h
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
public:
    BinaryNode();
    BinaryNode(const string &x, BinaryNode* node1, BinaryNode* node2);
    ~BinaryNode();

private:
    string value;
    BinaryNode* left;
    BinaryNode* right;

    friend class BinarySearchTree;
};

#endif
/*
Allison Fowle
acf6nb
10/4/2021
BinarySearchTree.h
*/

#ifndef BST_H
#define BST_H

#include <string>
#include "BinaryNode.h"

using namespace std;

// You do not need to know how Trunk works.
struct Trunk {
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    // insert finds a position for x in the tree and places it there.
    void insert(const string& x);
    // remove finds x's position in the tree and removes it.
    void remove(const string& x);
    // printTree pretty-prints the tree to aid debugging.
    void printTree();

    // pathTo finds x in the tree and returns a string representing the path it
    // took to get there.
    string pathTo(const string& x) const;
    // find determines whether or not x exists in the tree.
    bool find(const string& x) const;
    // numNodes returns the total number of nodes in the tree.
    int numNodes() const;

private:
    // Declare a root node
    BinaryNode* root;

    // private helper for remove to allow recursion over different nodes. returns
    // a BinaryNode* that is assigned to the original node.
    BinaryNode* remove(BinaryNode*& n, const string& x);
    // min finds the string with the smallest value in a subtree.
    string min(BinaryNode* node) const;

    // private helper for printTree to allow recursion over different nodes.
    void printTree(BinaryNode* root, Trunk* prev, bool isRight);

    // Any other methods you need...
    void myInsert(const string& x, BinaryNode *& curNode);
    bool myFind(const string& x, BinaryNode * curNode) const;
    string myPathTo(const string& x, BinaryNode * curNode) const;
    int myNumNodes(BinaryNode * curNode) const;
};

#endif
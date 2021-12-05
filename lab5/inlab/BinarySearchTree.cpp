/*
Allison Fowle
acf6nb
10/4/2021
BinarySearchTree.cpp
*/

#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}








//PRIVATE HELPER METHODS
void BinarySearchTree::myInsert(const string& x, BinaryNode *& curNode) {
    if (curNode == NULL) {
        curNode = new BinaryNode(x,NULL,NULL);
    }//end if
    else if (x < curNode->value) {
        if (curNode->left == NULL) {
            BinaryNode * tempNode = new BinaryNode(x, NULL, NULL);
            //tempNode->value = x;
            curNode->left = tempNode;
        }//end if
        else 
            myInsert(x, curNode->left);
    }//end elseif
    else if (x > curNode->value) {
        if (curNode->right == NULL) {
            BinaryNode * tempNode = new BinaryNode(x, NULL, NULL);
            curNode->right = tempNode;
        }//end if
        else
            myInsert(x, curNode->right);
    }//end else if

    else
        ; 
    }


string BinarySearchTree::myPathTo(const string& x, BinaryNode * curNode) const {
    // base case empty string
    if (curNode == NULL)  
        return "";
    if (x == curNode->value)
        return x;
    if (find(x) == true) {
        //left subtree path
        if (x < curNode->value) 
            return curNode->value + " " + myPathTo(x, curNode->left); 
        //right subtree path
        else
            return curNode->value + " " + myPathTo(x, curNode->right); 
    }
    else
        return "";
}

bool BinarySearchTree::myFind(const string& x, BinaryNode * curNode) const {
    // if there is nothing in the curNode, we have reached the bottom of the tree and did not find x
    if (curNode == NULL)  
        return false;
     // search left to find x
    else if (x < curNode->value)
        return myFind(x, curNode->left); 
    //search right to find x
    else if (x > curNode->value)
        return myFind(x, curNode->right); 
    // matched
    else if (x == curNode->value)
        return true;
    // not found
    else
        return false;  
}

int BinarySearchTree::myNumNodes(BinaryNode * curNode) const {
    //base case if current node is 0
    if (curNode == NULL)
        return 0;
    //else, recursively look at left and right of root and add 1 to account for the root node
    return myNumNodes(curNode->left) + myNumNodes(curNode->right) + 1;
}


// END PRIVATE HELPER METHODS







// remove finds x's position in the tree and removes it.
// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    if (find(x) == false)
        myInsert(x, root);
    else
        ;
}

void BinarySearchTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
    return myPathTo(x, root);
}


// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
    return myFind(x, root);
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
    return myNumNodes(root);
}









// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}



// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}
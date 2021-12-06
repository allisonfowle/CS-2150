/*
Allison Fowle
acf6nb
AVLTree.cpp
10/5/2021
*/

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}




// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::myInsert(const string& x, AVLNode *& curNode) {
    if (curNode == NULL) {
        curNode = new AVLNode(x,NULL,NULL);
    }//end if
    else if (x < curNode->value) {
        if (curNode->left == NULL) {
            AVLNode * tempNode = new AVLNode(x, NULL, NULL);
            //tempNode->value = x;
            curNode->left = tempNode;
        }//end if
        else 
            myInsert(x, curNode->left);
    }//end elseif
    else if (x > curNode->value) {
        if (curNode->right == NULL) {
            AVLNode * tempNode = new AVLNode(x, NULL, NULL);
            curNode->right = tempNode;
        }//end if
        else
            myInsert(x, curNode->right);
    }//end else if

    else
        ; 
    }

void AVLTree::insert(const string& x) {
    if (find(x) == false)
        myInsert(x, root);
    else
        ;
}






// PATHTO HELPER METHOD
string AVLTree::myPathTo(const string& x, AVLNode * curNode) const {
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

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    return myPathTo(x, root);
}



// FIND HELPER METHOD
bool AVLTree::myFind(const string& x, AVLNode * curNode) const {
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
// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    return myFind(x, root);
}




//NUMNODES HELPER METHOD
int AVLTree::myNumNodes(AVLNode * curNode) const {
    //base case if current node is 0
    if (curNode == NULL)
        return 0;
    //else, recursively look at left and right of root and add 1 to account for the root node
    return myNumNodes(curNode->left) + myNumNodes(curNode->right) + 1;
}
// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    return myNumNodes(root);
}






// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    //if balance factor node is 2, rotate left
    if (height(n->right) - height(n->left) == 2) {
        //if balance of right is negative
        if ((height(n->right->right) - height(n->left->left)) < 0)
            rotateRight(n->right);
        rotateLeft(n);
    }
    //if balance factor node is -2, rotate right
    else if (height(n->right) - height(n->left) == -2) {
        //if balance of left is positive
        if ((height(n->left->right) - height(n->left->left)) > 0)
            rotateLeft(n->left);
        rotateRight(n);
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    AVLNode * temp = n->right;
    n->right = temp->left;
    temp->left = n;
    n->height = max(height(n->left), height(n->right)) + 1;
    temp->height = max(height(temp->right), n->height) + 1;
    n = temp;
    return temp;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    AVLNode * temp = n->left;
    n->left = temp->right;
    n->height = max(height(n->left), height(n->right)) + 1;
    temp->height = max(height(temp->left), n->height) + 1;
    n = temp;
    return temp;
}






// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}




// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}





// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}





// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}




// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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

void AVLTree::printTree() {
    printTree(root, NULL, false);
}

/*
Allison Fowle
acf6nb
AVLPathTest.cpp
10/5/2021
*/


// DO NOT MODIFY
#include "AVLTree.h"

#include <iostream>
using namespace std;

int main() {
    AVLTree avl;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            avl.insert(word);
        } else if (instr == "R") {
            avl.remove(word);
        } else if (instr == "L") {
            cout << "AVL path: " << avl.pathTo(word) << endl;
        }
    }
    cout << "AVL numNodes: " << avl.numNodes() << endl;
}
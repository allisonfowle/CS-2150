/*
Allison Fowle
CS 2150 - acf6nb
11/21/2021
huffTree.h
*/


#ifndef HUFFTREE_H
#define HUFFTREE_H

#include <iostream>
#include "heap.h"
#include "huffNode.h"
using namespace std;


class huffTree {
public:
	huffTree(); //constructor
	~huffTree(); //destructor
	binary_heap makeTree(binary_heap newHeap); // creates huffman tree
	huffNode *node;
};

#endif
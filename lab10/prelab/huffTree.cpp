/*
Allison Fowle
CS 2150 - acf6nb
11/21/2021
huffTree.cpp
*/

#include <iostream>
#include "huffTree.h"
#include "huffNode.h"
#include "heap.h"

using namespace std;

//constructor
huffTree::huffTree() {
	node = NULL;
}

//destructor
huffTree::~huffTree() {
	delete node;
}


//binary_heap newHeap;
binary_heap huffTree::makeTree(binary_heap newHeap) {
	//while the heap even exists of some tree with nodes
	while(newHeap.size() > 1) {
		//create a temp node where you find the min, store it
		huffNode* temp1 = newHeap.findMin();
		//delete that so you can find the next min
		newHeap.deleteMin();
		//create another temp node to find the min, store it
		huffNode* temp2 = newHeap.findMin();
		//delete that min as well
		newHeap.deleteMin();
		//use method above to create a new hufftree with left and right and a root node
		int totalFreq = temp1->freq + temp2->freq;
		huffNode* root = new huffNode('1', totalFreq);
		root->left = temp1;
		root->right = temp2;
		// huffNode* root = addTree(left, right);
		//insert this new tree onto the heap
		newHeap.insert(root);
	}
	return newHeap;
}

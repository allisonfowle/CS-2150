/*
Allison Fowle
acf6nb
huffNode.cpp
11/17/2021
*/


#include <iostream>
#include "huffNode.h"

using namespace std;

//default constructor
huffNode::huffNode() {
	chars = ' ';
	freq = 0;
	left = NULL;
	right = NULL;
	prefix = "";
}

//constructor
huffNode::huffNode(char characters, int frequency) {
	chars = characters;
	freq = frequency;
	left = NULL;
	right = NULL;
}

//deconstructor
huffNode::~huffNode() {
	delete left;
	delete right;
}

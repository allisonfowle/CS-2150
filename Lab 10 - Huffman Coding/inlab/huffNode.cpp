/*
Allison Fowle
CS 2150 - acf6nb
heapNode.cpp
11/22/2021
*/


//taken from prelab 10

#include <iostream>
#include "huffNode.h"

using namespace std;

//default constructor
huffNode::huffNode() {
	chars = ' ';
	freqs = 0;
	left = NULL;
	right = NULL;
}

//constructor
huffNode::huffNode(char characters, int frequency) {
	chars = characters;
	freqs = frequency;
	left = NULL;
	right = NULL;
}

//deconstructor
huffNode::~huffNode() {
	delete left;
	delete right;
}

//getter for chars
char huffNode::getChar() {
	return chars;
}

//getter for frequency
int huffNode::getFreq() {
	return freqs;
}
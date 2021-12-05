/*
Allison Fowle
CS 2150 - acf6nb
heapNode.h
11/22/2021
*/

//taken from prelab10

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>
using namespace std;

class huffNode {
public:
	huffNode(); //default constructor
	huffNode(char passedchars, int passedfreq); //constructor
	~huffNode(); //deconstructor
	char getChar(); //getter
	int getFreq(); //getter
	int freqs;
	char chars;
	huffNode *left;
	huffNode *right;


private:
	

};

#endif
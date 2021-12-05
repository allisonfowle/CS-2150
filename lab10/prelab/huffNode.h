/*
Allison Fowle
acf6nb
huffNode.h
11/17/2021
*/

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>
#include <string>
using namespace std;

class huffNode {
public:
	huffNode(); //default constructor
	huffNode(char passedchars, int passedfreq); //constructor
	~huffNode(); //deconstructor
	int freq;
	char chars;
	string prefix;
	huffNode *left;
	huffNode *right;


private:
	

};

#endif
/*
Allison Fowle
acf6nb
hashTable.h
10/14/2021
*/


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include <list>
#include <iostream>


using namespace std;

class hashTable {
public:
    hashTable(int size);
    ~hashTable();
    int hashFunction(string s);
    void insert(string s);
    bool find(string s);

private:
    vector<list <string>> hashTab; //create a vector of linked lists of strings as the hash table
    int tableSize;

};

#endif
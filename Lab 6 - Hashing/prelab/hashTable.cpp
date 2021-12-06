/*
Allison Fowle
acf6nb
HashTable.cpp
10/14/2021
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "hashTable.h"
using namespace std;


// forward declarations

//checkprime and getNextPrime method from primenumber.cpp
bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}




// start hashTable.cpp methods
//constructor
hashTable::hashTable(int size) {
	if (checkprime(size)) 
		tableSize = 3*size;
  	else 
    	tableSize = getNextPrime(3*size);
  	for(int i = 0; i < tableSize; i++) {
    	list<string> bucket; //collision of linked list of strings of buckets
    	hashTab.push_back(bucket);
    }
}

//destructor
hashTable::~hashTable() {}


int hashTable::hashFunction(string s) {
    int x = 0;
    int length = s.length();
    for (int i = 0; i < s.length(); i++) {
        x += 2 + s[i];
    }
    return x % tableSize;
 }

void hashTable::insert(string s){
    int index = hashFunction(s);
    hashTab[index].push_back(s);
 }


bool hashTable::find(string s) {
    int index = hashFunction(s);
    if (hashTab[index].front() == s)
        return true;
    else {
        list<string>::iterator iter = hashTab[index].begin();
        for (iter; iter != hashTab[index].end(); iter++) {
            if (s == *iter)
                return true;
        }
        return false;
    }
}




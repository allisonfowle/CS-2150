/*
Allison Fowle
acf6nb
inlab4.cpp
9/21/2021
*/


#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
void tableDump(string (*arr)[5], string (*arr1)[4]);

int main(){

	int i = 0;
	// Replace the empty strings below with
	// the values you found while experimenting.

	string nonPointers[6][5] = {
		{"int", "4" /*size*/, "2,147,483,647" /*max value*/, "0x00000000" /*zero as stored in hex*/,"0x00000001" /*one as stored in hex*/},
		{"unsigned int", "4" /*size*/, "4,294,967,295" /*max value*/, "0x00000000" /*zero as stored in hex*/, "0x00000001" /*one as stored in hex*/},
		{"float", "4" /*size*/, "2^128" /*max value*/, "0x00000000" /*zero as stored in hex*/, "0x3f800000" /*one as stored in hex*/},
		{"double", "8" /*size*/, "2^1024" /*max value*/, "0x0000000000000000" /*zero as stored in hex*/, "0x3ff0000000000000" /*one as stored in hex*/},
		{"char", "1" /*size*/, "127" /*max value*/, "0x00" /*zero as stored in hex*/, "0x01" /*one as stored in hex*/},
		{"bool", "1" /*size*/, "1" /*max value*/, "0x00" /*zero as stored in hex*/, "0x01" /*one as stored in hex*/},
	};

	string pointers[3][4] = {
		{"int*", "8" /*size*/, "0xffffffffffffffff" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
		{"char*", "8" /*size*/, "0xffffffffffffffff" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
		{"double*", "8" /*size*/, "0xffffffffffffffff" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
	};

	tableDump(nonPointers, pointers);
	return 0;
}

void tableDump(string (*arr)[5], string (*arr1)[4]){
	for(int i = 0; i < 6; i++){
		printf("Size of %s: %s\n", arr[i][0].c_str(), arr[i][1].c_str());
		printf("Max value of %s: %s\n", arr[i][0].c_str(), arr[i][2].c_str());
		printf("Zero of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][3].c_str());
		printf("One of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][4].c_str());
	}

	printf("-----------------------------------------------------------------------------\n");

	for(int i = 0; i < 3; i++){
		printf("Size of %s: %s\n", arr1[i][0].c_str(), arr1[i][1].c_str());
		printf("Max value of %s: %s\n", arr1[i][0].c_str(), arr1[i][2].c_str());
		printf("NULL of type %s is stored as: %s\n", arr1[i][0].c_str(), arr1[i][3].c_str());
	}
}
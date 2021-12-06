/*
Allison Fowle
CS 2150 - acf6nb
huffmandec.cpp
11/22/2021
*/


// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
// #include "huffNode.h"
using namespace std;



unordered_map <string, string> hMap;



// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

 

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        
        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code

        hMap.insert(make_pair(prefix, character));


    }

   // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
   
        // add it to the stringstream
        sstm << bits;

    }


   string allbits = sstm.str();


    // at this point, all the bits are in the 'allbits' string

    // close the file before exiting
    file.close();
    string cat = "";
    string ret = "";
    for(int i = 0; i <= allbits.size(); i++) {
        unordered_map<string, string>::iterator iter = hMap.find(cat);
        if(iter != hMap.end()) {
            ret += hMap[cat];
            cat = "";
            //cout << cat;
        }
        cat += allbits[i];
    }
    cout << ret;
    cout << endl;
    return 0;
}
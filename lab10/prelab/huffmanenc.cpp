/*
Allison Fowle
acf6nb
heap.cpp
11/17/2021
*/


//DISCLAIMER: THIS CODE IS A SKELETON CODE FROM
//FILEIO.CPP USED IN CS-2150 GIVEN TO US FOR 
//PRELAB USE OF READING A FILE

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //set precision for ratio and cost
#include <unordered_map>
#include "heap.h"
#include "huffNode.h"
#include "huffTree.h"

using namespace std;

unordered_map<char, string> hMap;
void recursePrefix(huffNode* node, string s) {
    //if both pointers of node are null, you've recursed through the tree.
    //set character of node to prefix from above
    //base case, if you've recursed through the tree, find character and string built below
    if(node->left == NULL && node->right == NULL) {
        hMap.insert(make_pair(node->chars, s));
        cout << node->chars << " " << s << endl;
    }
    //hard code if character is a space
    if (node->chars == ' ') 
        cout << "space " << s << endl;
    //going left is "0", so if you go one node to left, s is 0;
    if (node->left) 
        recursePrefix(node->left, s + "0");
    //going right is a "1"
    if (node->right)
        recursePrefix(node->right, s + "1");
}



//command line parameters
int main(int argc, char **argv) {


	// verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

       

    //SECTION 1!!!!!!!!!!
	//ascii character
    char g; 

    // initialize what variables we're printing
    int symbols = 0;
    int distsymb = 0;
	
	//create array from with max 0x7e, which is possible ASCII characters
	//figure out how many times an ASCII appears
	//creates an array of characters WITH frequencies
	int asc[128];
    for (int i = 0; i < 128; i++) {
    	asc[i] = 0;
    }

    //read in characters from a file
    //if ASCII is between 0x7e and 0x20, it's a letter. increase symbols and total letters
    while (file.get(g)) {
    	if (((int) g < 128) && ((int) g > 31)) {//if g is an ASCII readable char
    		asc[(int)g]++; //increase how many/what letters are in file
    		//symbols++; //increase total # of symbols in file, which is used in section 3
    	}
    }

    binary_heap heap;
    //create a bunch of nodes associated with asc[]. for each index, it corresponds
    //to an ASCII letter. that's a character. for frequency, put node in of
    //how many times it has looped thru array
    for (int i = 0; i < 128; i++) {
    	if (asc[i] > 0) {//we don't want a character with 0 frequency inserted into heap
       		huffNode* huffmanNode = new huffNode((char) i, asc[i]);
    		heap.insert(huffmanNode);
    		distsymb++;
    	}
	}

	huffTree* tree = new huffTree();
    binary_heap treeHeap = tree->makeTree(heap);
    recursePrefix(treeHeap.findMin(), "");
	
	//create the tree changing the heap in function above
	
    file.close();


    //END SECTION 1


    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    //SECTION 2!!!!!!!!!!!
    //reopen file to look again
    ifstream file1(argv[1]);

    //initialize variables used in section 3
    int ogbits = 0;
    int compbits = 0;

    while(file1.get(g)) {
        if((g <= 0x7e) && (g >= 0x20) && (g != '\n')) {
            symbols++;
            unordered_map<char, string>::iterator iter = hMap.find(g);
            if(iter != hMap.end()) {//it's there, found 
                cout << iter->second << " ";
                compbits += iter->second.length();
            }
        }
    }    
    cout << endl;


    // section 3
	cout << "----------------------------------------" << endl;


    ogbits = symbols * 8;
    double ratio = (double)ogbits/compbits;
    
    double cost = (double)compbits/symbols;

	cout << "There are a total of " << symbols << " symbols that are encoded." << endl;
	cout << "There are " << distsymb << " distinct symbols used." << endl;
	cout << "There were " << ogbits << " bits in the original file." << endl;
	cout << "There were " << compbits << " bits in the compressed file." << endl;
	cout << "This gives a compression ratio of " << ratio << "." << endl;
	cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;
	// close the file
    file1.close();

	return 0;
}
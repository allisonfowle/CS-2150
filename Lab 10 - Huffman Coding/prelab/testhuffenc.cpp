/*
Allison Fowle
acf6nb
heap.cpp
11/17/2021
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip> //set precision for ratio and cost
#include "heap.h"
#include "huffNode.h"
#include "huffTree.h"

using namespace std;

//prototypes from huffTree.cpp
huffNode* addTree(huffNode* heap1, huffNode* heap2);
void recursePrefix(huffNode* node, string s);

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

    // section 1
    

    // read in characters one by one, until reading fails (we hit the end of the file)
    
	//ascii character
    char g; 

    // initialize what variables we're printing
    int symbols = 0;
    int distsymb = 0;; 
	
	//create array from 0 - 126, which is possible ASCII characters
	//figure out how many times an ASCII appears
	//creates an array of characters WITH frequencies
	int asc[0x7e];
    for (int i = 0; i < 0x7e; i++) {
    	asc[i] = 0;
    }

    //if ASCII is between 0x7e and 0x20, it's a letter. increase symbols and total letters
    while (file.get(g)) {
    	if ((g <= 0x7e) && (g >= 0x20)) {//if g is an ASCII readable char
    		asc[g]++; //increase how many/what letters are in file
    		symbols++; //increase total # of sumbols in file
    	}
    }

    binary_heap heap;
    //create a bunch of nodes associated with asc[]. for each index, it corresponds
    //to an ASCII letter. that's a character. for frequency, put node in of
    //how many times it has looped thru array
    for (int i = 0; i < 0x7e; i++) {
    	if (asc[i]) {//we don't want a character with 0 frequency inserted into heap
       		huffNode *huffmanNode = new huffNode((char) i, asc[i]);
    		heap.insert(huffmanNode);
    		distsymb++;
    	}
	}

	huffTree* tree = new huffTree();
    binary_heap theheap = tree->makeTree(heap);
    tree->recursePrefix(theheap.findMin(), "");
	
	//create the tree changing the heap in function above
	



    // a nice pretty separator

    int ogbits = 0;
    int compbits = 0;
    cout << "----------------------------------------" << endl;

    vector<huffNode*> encoded = heap.showHeap();

    while (file.get(g)) {
     	for (int i = 1; i < heap.size() + 1; i++) {
     		if (encoded[i]->getChar() == g) {
     			compbits += encoded[i]->getPref().size();
     			cout << encoded[i]->getPref() << " ";
     		}
     	}
    }

    cout << endl;


    // section 3
	cout << "----------------------------------------" << endl;


    ogbits = symbols * 8;
    double ratio = ogbits/compbits;
    double cost = compbits/ogbits;

	cout << "There are a total of " << symbols << " symbols that are encoded." << endl;
	cout << "There are " << distsymb << " distinct symbols used." << endl;
	cout << "There were " << ogbits << " bits in the original file." << endl;
	cout << "There were " << compbits << " bits in the compressed file." << endl;
	cout << "This gives a compression ratio of " << setprecision(5) << ratio << endl;
	cout << "The cost of the Huffman tree is " << setprecision(5) << cost << " bits per character." << endl;
	// close the file
    file.close();

	return 0;
}
/*
Allison Fowle
acf6nb
heap.cpp
11/17/2021
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include "heap.h"
#include "huffNode.h"

using namespace std;




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

    // initialize what variables we're printing


    // section 1
    

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    //unordered_map<char> ascii;
    //unordered_map<int> freqs;
    unordered_map<char, int> table;
    // vector<char> ascii;
    // vecotr<int> freqs;
    int symbols = 0;
    while (file.get(g)) {
        if ((g <= 0x7e) && (g >= 0x20)) {//if g is an ASCII readable char
            if(table.find(g) == table.end()) {//you've parsed thru file, didn't find char
                table.insert(g, 1); //insert char into hashTable
                symbols++;
            }
            else {
                //freqs.(1);
            }
        }
    }


 //    for (int i = 0; i < 0x7e; i++) {
 //     huffNode *huffmanNode = new huffNode(g, freq);
 //     newHeap.insert(huffmanNode);
 //     distsymb++;
    // }



    





    


    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);




    // how many 1s and 0s in compressed= the bits

   // double ogbits = chars * 8;
    //double ratio = ogbits/compbits;



    // close the file
    file.close();


    // section 3
    // cout << "----------------------------------------" << endl;
    // cout << "There are a total of " << symbols << " symbols that are encoded." << endl;
    // cout << "There are " << distsymb << " distinct symbols used." << endl;
    // cout << "There were " << ogbits << " bits in the original file." << endl;
    // cout << "There were " << compbits << " bits in the compressed file." endl;
    // cout << "This gives a compression ratio of " << ratio << endl;
    // cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;


    return 0;
}
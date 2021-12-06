/*
Allison Fowle
acf6nb
10/14/2021
wordPuzzle.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "hashTable.h"
#include "timer.h"

using namespace std;


//read in a word search grid no larger than 500x500 
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// prototypes from getWordInGrid.cpp and primenumber.cpp
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int direction, int len,
                     int numRows, int numCols);

int main(int argc, char *argv[]) {
    //ifstream read "dictionary", count gives us # of words for myTable
    int count = 0;
    //dictionary is the command line parameter words textfile
    string dictionary = argv[1];
    string s;
    ifstream words(dictionary);
    while (getline(words, s)) {
      count++;
    }
    words.close();
    
    //create hashtable called myTable with count variable loaded in from dictionary
    hashTable myTable(count);

    //Read in dictionary and save words to previously created table
    ifstream dict(dictionary);
    while(getline(dict, s)) {
    	//if the length of the words is greater than 2 (meaning 3 or bigger) put them into hashtable
    	if(s.length() > 2) {
    	   myTable.insert(s);
      }//end if
    }//end while
    dict.close();

    //second command line parameter is the grid of words
    string wordGrid = argv[2];
    ifstream wSearch(wordGrid);
    int rows, columns;
    if(readInGrid(wordGrid, rows, columns) == false) {
      cout << "Error" << endl;
    }
    wSearch.close();

    vector<string> buffer; //data structure to buffer output and lower time. faster to iterate through a vector than a list
    int pos = 0;
    string direct;
    string word;
    string fin;
    timer timer;
    int x, y, d, l;
    timer.start();
    for(x = 0; x < rows; x++) {
        for(y = 0; y < columns; y++) {
            for(d = 0; d < 8; d++) {
                for(l = 3; l < 22; l++) {
                    word = getWordInGrid(x, y, d, l, rows, columns);
                    if (l != word.length())
                        break;
                    if (myTable.find(word)) {
                        pos++;
                        if(d == 0)
                            direct = "N";
                        else if(d == 1) 
                            direct = "NE";
                        else if(d == 2) 
                            direct = "E";
                        else if(d == 3)
                            direct = "SE";
                        else if(d == 4) 
                            direct = "S";
                        else if(d == 5) 
                            direct = "SW";
                        else if(d == 6) 
                            direct = "W";
                        else if(d == 7) 
                            direct = "NW";
                        //cout << direct << " (" << x << ", " << y << "): " << word << endl;
                        string newX  = to_string(x);
                        string newY = to_string(y);
                        string print = direct + " (" + newX + "," + newY + "):      " + word;
                        buffer.push_back(print);
                    }
                }
            }
        }
    }
    timer.stop();
    double theTime = timer.getTime();
    //cout << pos << " words found in " << theTime << endl;
    
    //print out the data structure AFTER timer
    for(int i = 0; i < buffer.size(); i++) {
        cout << buffer[i]<< endl;
    }

   cout << pos << " words found"  /*<< theTime */ << endl;
    

    return 0;
}


//readInGrid method from getWordInGrid.cpp
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}


//getWordInGrid method from getWordInGrid.cpp
string getWordInGrid (int startRow, int startCol, int direction, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the directionection specified by the parameter
        switch (direction) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

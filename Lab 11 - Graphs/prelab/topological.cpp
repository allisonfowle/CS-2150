/*
Allison Fowle
CS 2150 - acf6nb
topological.cpp
11/29/2021
*/


// from fileio2.cpp
// This program shows how C++-based file I/O works.
// It will open a file, read in the first two strings, and print them to the screen.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;



unordered_map<string, list<string>> prereqs;
unordered_map<string, int> indegrees;

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in two strings
    string s1, s2;

    //while the file is still open
    while(file >> s1 >> s2) {//while the file is reading in both s1 and s2
        //if s1 is NOT present, insert s2 to create a link between s1 and s2
        if (prereqs.find(s1) == prereqs.end()) {//.end and .find return iterators, compare them
            list<string> list;
            prereqs[s1] = list;
            prereqs[s1].push_back(s2); //add s2 onto prereq at index s1. this creates a link between s1-->s2
            if (indegrees.find(s1) == indegrees.end()) {
                indegrees[s1] = 0;
            }
            indegrees[s2]++; //increase indegree value
        }
        else { //if s1 was found, then create a temp list to insert into "value" of list<string> in prereq
            prereqs[s1].push_back(s2); //set prereq s1 = list of s2
            indegrees[s2]++; //increase indegree value
        }
    }


    //topological sort
    queue <string> q;
    q.empty();
    for (auto x: indegrees) {//loop through unordered_map indegrees
        if (x.second == 0) {//if value (int) of indegrees is 0
            q.push(x.first); //push key (string) onto the queue
        }
    }
    while (!q.empty()) { //while there is something in the queue
        cout << q.front() << " " ; //print first thing in queue
        string v = q.front(); //save the top of queue before delete
        q.pop(); //delete first off of queue
        for (auto y: prereqs[v]) { //goes thru list{// insert eligible verts
            --indegrees[y];
            if (indegrees[y] == 0) {
                q.push(y);
            }
        } //end for
        indegrees.erase(v);
    }//end while
    cout << endl;
    // close the file before exiting
    file.close();

    return 0;
}
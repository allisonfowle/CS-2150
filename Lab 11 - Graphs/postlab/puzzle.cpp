/*!
* @author Allison Fowle
* @detail CS 2150 - acf6nb
* @detail puzzle.cpp
* @date 12/1/2021
*/


#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <list>
using namespace std;



list<string> configs;
/**
 * @brief Creates possible configurations depending on where the 'hole' of the puzzle is
 * 
 * Given a starting string(called node, a 3x3 grid), create dummy variables that will be
 * replaced as the combinations of 0s and its neighbors. 0 can have neighbors to the
 * left, right, top, and bottom
 * 
 * @return list<string> of strings of possible configurations of the puzzle
 * @param node of starting 3x3 grid
 */
list<string> genNeighbors(string node) {
	string poss1 = node;
	string poss2 = node;
	string poss3 = node;
	string poss4 = node;
	if (node[0] == '0') {
		//0 1 2
		//3 4 5
		//6 7 8
		//switch 1 and 0
		swap(poss1[0], poss1[1]);
		configs.push_back(poss1);
		//switch 3 and 0
		swap(poss2[0], poss2[3]);
		configs.push_back(poss2);
		//return configs;
	}
	if (node[1] == '0') {
		//1 0 2
		//3 4 5
		//6 7 8
		//switch 0 and 1
		swap(poss1[1], poss1[0]);
		configs.push_back(poss1);
		//switch 0 and 2
		swap(poss2[1], poss2[2]);
		configs.push_back(poss2);
		//switch 0 and 4
		swap(poss3[1], poss3[4]);
		configs.push_back(poss3);
		//return configs;
	}
	if (node[2] == '0') {
		//1 2 0
		//3 4 5
		//6 7 8
		//switch 0 and 2
		swap(poss1[2], poss1[1]);
		configs.push_back(poss1);
		//switch 0 and 5
		swap(poss2[2], poss2[5]);
		configs.push_back(poss2);
		//return configs;
	}
	if (node[3] == '0') {
		//1 2 3
		//0 4 5
		//6 7 8
		//switch 0 and 1
		swap(poss1[3], poss1[0]);
		configs.push_back(poss1);
		//switch 0 and 4
		swap(poss2[3], poss2[4]);
		configs.push_back(poss2);
		//switch 0 and 6
		swap(poss3[3], poss3[6]);
		configs.push_back(poss3);
		//return configs;
	}
	if (node[4] == '0') {
		//1 2 3
		//4 0 5
		//6 7 8
		//switch 0 and 2
		swap(poss1[4], poss1[1]);
		configs.push_back(poss1);
		//switch 0 and 4
		swap(poss2[4], poss2[3]);
		configs.push_back(poss2);
		//switch 0 and 7
		swap(poss3[4], poss3[7]);
		configs.push_back(poss3);
		//switch 0 and 5
		swap(poss4[4], poss4[5]);
		configs.push_back(poss4);
		//return configs;
	}
	if (node[5] == '0') {
		//1 2 3
		//4 5 0
		//6 7 8
		//switch 0 and 3
		swap(poss1[5], poss1[2]);
		configs.push_back(poss1);
		//switch 0 and 5
		swap(poss2[5], poss2[4]);
		configs.push_back(poss2);
		//switch 0 and 8
		swap(poss3[5], poss3[8]);
		configs.push_back(poss3);
		//return configs;
	}
	if (node[6] == '0') {
		//1 2 3
		//4 5 6
		//0 7 8
		//switch 0 and 4
		swap(poss1[6], poss1[3]);
		configs.push_back(poss1);
		//switch 0 and 7
		swap(poss2[6], poss2[7]);
		configs.push_back(poss2);
		//return configs;
	}
	if (node[7] == '0') {
		//1 2 3
		//4 5 6
		//7 0 8
		//switch 0 and 5
		swap(poss1[7], poss1[4]);
		configs.push_back(poss1);
		//switch 0 and 7
		swap(poss2[7], poss2[6]);
		configs.push_back(poss2);
		//switch 0 and 8
		swap(poss3[7], poss3[8]);
		configs.push_back(poss3);
		//return configs;
	}
	if(node[8] == '0') {
		//1 2 3
		//4 5 6
		//7 8 0
		//switch 0 and 6
		swap(poss1[8], poss1[5]);
		configs.push_back(poss1);
		//switch 0 and 8
		swap(poss2[8], poss2[7]);
		configs.push_back(poss2);
		//return configs;
	}
	// int index = 0;
	// for (int i = 0; i < 9 ;i++) {
	// 	if (node[i] == '0') {
	// 		index = i;
	// 	}
	// }
	// if (index % 3 != 0) {
	// 	index = index - 1;
	// }
	// if (index % 3 != 2) {
	// 	index = index + 1;
	// }
	// if (index < 3) {
	//	
	// }
	// if (index > 5) {

	// }
	return configs;
}

void search(string node) {

}

int main() {

	string a, b, c;
	string grid;
	cout << "Enter puzzle" << endl;
	//get the first board
	string input;
	for (int i = 0; i < 9; i++) {
		string grid;
		cin >> grid;
		input.append(grid);
	}
	cout << "Solving puzzle" << endl;
	unordered_map <string, int> hMap;
	queue <string> q;
	q.push(input);
	hMap[input] = 0;
	while (!q.empty()) {
		string v = q.front(); //set v = first combination board
		q.pop(); //delete it so you can keep parsing through
		//cout << q.size() << endl;
		if (v == "123456780") { //you've completed the search
			cout << hMap["123456780"] << endl;
			return 0;
		}
		for(auto x: genNeighbors(v)) {
			if(!hMap.contains(x)) {//if iter reaches end, means node not there
    			hMap[x] = 1 + hMap[v];
    			q.push(x);
    		}//end if
		}//end for

	}//end while
	cout << "IMPOSSIBLE" << endl;

	return 0;
}
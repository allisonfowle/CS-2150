/*
Allison Fowle
acf6nb
9/1/2021
xToN.cpp
*/
#include <iostream>
using namespace std;

int xton(int a, int b) {
    if (b == 0) { //base case
        return 1;
    }
    return  a * xton(a, b-1); // recursive case
    
}

int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    int c = xton(a, b);
    cout << c << endl;
    return 0;
}
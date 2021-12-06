#include <iostream>
#include "timer.h"
#include <cstring>
using namespace std;

extern "C" int threexplusone(int);

int main(){

	int x; //positive integer to pass into the subroutine
	int n; //number of time to call subroutine
    timer timer;
    cout << "Enter a number: ";
	cin >> x;
    cout << "Enter iterations of subroutine: ";
    cin >> n;

    int steps = threexplusone(x); //number of iterations for x to converge to 1

    // timer.start();
    // // run through for loop and recurse through assembly file
    // for (int i = 0; i < n; i++) {
    //     steps;
    // }
    // timer.stop();

    cout << "Steps: " << steps << endl;

    return 0;

}
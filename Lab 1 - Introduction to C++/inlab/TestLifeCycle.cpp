/*
Allison Fowle
acf6nb
9/1/2021
TestLifeCycle.cpp
*/
#include <iostream>
#include "LifeCycle.h"
#include <string>

using namespace std;


int main () {
    cout << "--PART 1: Start of main--" << endl;
    cout << "--Defining o1, o2(\"Bob\")--" << endl;
    MyObject o1, o2("Bob");

    cout << "--Defining o3(o2)--" << endl;
    MyObject o3(o2);

    cout << "--Defining array of 3 objects--" << endl;
    MyObject array[3];

    cout << endl;

    cout << "--PART 2: call function using call-by-value, return int--" << endl;
    cmpMyObj(o1, o3);

    cout << "--call function using call-by-value, return MyObject--" << endl;
    getMaxMyObj(o1, o3);

    cout << endl;

    cout << "--PART 3:  o1: " << o1 << endl;
    {
        cout << "  --entering new block, define new o1(Sally)--" << endl;
        MyObject o1("Sally");
        o1.setName("Sally");
        cout << "  o1: " << o1 << "\to2: " << o2 << endl;

        cout << "  --call swap function using call-by-reference--" << endl;
        swapMyObj(o1, o2);

        cout << "  --were their values swapped?--" << endl;
        cout << "  o1: " << o1 << "\to2: " << o2 << endl;
        cout << "  --leaving new block--" << endl;
    }
    cout << "o1: " << o1 << endl;

    cout << endl;

    cout << "--PART 4: Define reference var: { MyObject& oref=o1; } --" << endl;
    {
        MyObject& oref=o1;
    }
    cout << "-- was anything constructed/destructed?--" << endl;

    cout << endl;

    cout << "--PART 5: new and delete--" << endl;
    cout << "--use new to create one object, then array of 2 objects--" << endl;
    MyObject *op1 = new MyObject, *op2 = new MyObject[2];

    cout << "--use delete to remove that one object--" << endl;
    delete op1;

    cout << "--use delete [] to remove that array of 2 objects --" << endl;
    delete[] op2;

    cout << endl;

    cout << "--LAST PART:  End of main--" << endl;
    return 0;
}
/*
Allison Fowle
acf6nb
9/1/2021
bankAccount.h
*/

#include <iostream>
using namespace std;


class bankAccount{
public:
	bankAccount(); // default constructor
	bankAccount(double amount); // constructor that is called 
	~bankAccount(); // deconstructor
	double withdraw(double amount);
	double deposit(double amount);
	double getBalance();

private: 
	double balance;
};
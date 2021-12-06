/*
Allison Fowle
acf6nb
9/1/2021
bankAccount.cpp
*/


#include <iostream>
#include "bankAccount.h"
using namespace std;

// default constructor
bankAccount::bankAccount() {
	balance = 0.00;  // bank balance set to 0
}

// constructor
bankAccount::bankAccount(double amount) {
	balance = amount;
}

// destructor
bankAccount::~bankAccount() {}

//methods
double bankAccount::withdraw(double amount) {
	if (amount > balance) {
		return balance;
	}
	balance -= amount;
	return balance;
}

double bankAccount::deposit(double amount) {
	balance += amount;
	return balance;
}

double bankAccount::getBalance() {
	return balance;
}
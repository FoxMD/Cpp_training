#include "Checking.h"
#include <iostream>

// In C++ 3 things are not inherited, Constructor, destructor and assignment operator
Checking::Checking(const std::string &name, float balance, float minbalance):
m_MinimumBalance(minbalance), Account(name, balance){
}
// in C++ we can use inheriting constructors so we dont need to implement constructors for child classes
// to use it you need to implement using keyword: using Account::Account; 

Checking::~Checking() {
}

void Checking::Withdraw(float amount) {
	if ((m_Balance - amount) > m_MinimumBalance) {
		Account::Withdraw(amount);	// Scope is important !!! Else it is a recursion
	}
	else {
		std::cout << "Invalid amount" << std::endl; 
	}
}

float Checking::GetMinimumBalance() const {
	return m_MinimumBalance;
}

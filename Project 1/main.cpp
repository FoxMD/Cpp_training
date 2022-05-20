#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>

int main()
{
	Checking ch("Bob", 100, 50);
	Transact(&ch);

	const std::type_info &ti = typeid(Checking);
	std::cout << ti.name() << std::endl; 
    if(ti == typeid(Savings)){} // runs in runtime
	
	return 0;
}
 

#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>

int main()
{
	Checking ch("Bob", 100, 50);
	Transact(&ch);
    Account* Acc = new Account(ch);

	const std::type_info &ti = typeid(Checking);
	std::cout << ti.name() << std::endl; 
    // old way
    if(typeid(Acc) == typeid(Savings))
    {
        Checking *pChecking = static_cast<Checking*>(Acc);
    }
    // new way, does work with references
    Checking *pChecking = dynamic_cast<Checking*>(Acc);
    if(pChecking != nullptr)
    {

    }
    // in case of reference error it throws exception
    
	
	return 0;
}
 

#include "Integer.h"
#include <memory>

void Display(Integer *p)
{
    if(!p) return;
    std::cout << p->GetValue() << std::endl;
}

Integer * GetPointer(int value)
{
    Integer *p = new Integer{value};
    return p;
}

void Store(std::unique_ptr<Integer> p)
{
    std::cout << "Storing data" << std::endl;
}

void Operate(int value)
{
    // Integer *p = GetPointer(value);
    std::unique_ptr<Integer> p{GetPointer(value)};
    if(p == nullptr)
    {
        p.reset(new Integer{value});
    }
    p->SetValue(500);   // we can use it due to overload of -> 
    Display(p.get());
    p = nullptr; // it is valid
    p.reset(new Integer{}); 
    *p = __LINE__;  	// due to overload works it
    Display(p.get());
    // Store(p); wont work due a deleted object
    Store(std::move(p)); // we can move the ownership of the object but then we cannot use it anymore
    // but if we pass the value by reference we can use it later and without move
    // so mod void Store(std::unique_ptr<Integer> p) -> void Store(std::unique_ptr<Integer> &p)
}

int main()
{
    Operate(5);
    return 0;
}
#include "Integer.h"
#include <memory>

void Display(Integer *p)
{
    if(!p) return;
    std::cout << p->GetValue() << std::endl;
}
// keep it
Integer * GetPointer(int value)
{
    Integer *p = new Integer{value};
    return p;
}

void Operate(int value)
{
    // Integer *p = GetPointer(value);
    std::unique_ptr<Integer> p{GetPointer(value)};
    if(p == nullptr)
    {
        // p = new Integer{value};
        p.reset(new Integer{value});
    }
    p->SetValue(500);   // we can use it due to overload of ->
    // Display(p); 
    Display(p.get());
    // delete p; it is not a pointer it is a Object
    p = nullptr; // it is valid
    // p = new Integer{};
    p.reset(new Integer{}); 
    *p = __LINE__;  	// due to overload works it
    // Display(p);
    Display(p.get());
    // delete p;
}

int main()
{
    Operate(5);
    return 0;
}
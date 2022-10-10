#include "Integer.h"

// The old way
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

void Operate(int value)
{
    Integer *p = GetPointer(value);
    if(p == nullptr)
    {
        p = new Integer{value};
    }
    p->SetValue(500);
    Display(p);
    delete p;
    p = nullptr;
    p = new Integer{};
    *p = __LINE__;
    Display(p);
    delete p;
}

int main()
{
    Operate(5);
    return 0;
}
#include "iostream"
#include "Integer.h"

class IntPtr 
{
    Integer *m_p;
    public:
        IntPtr(Integer *p) : m_p(p) {}
        ~IntPtr() {delete m_p;}
        Integer *operator->() {return m_p;}
        Integer & operator *() {return *m_p;}
};

void CreateInteger() 
{
/*
    Integer *p = new Integer;   // Create an integer on HEAP
    p->SetValue(3);
    std::cout << p->GetValue() << std::endl;
    delete p; // else it will be not deleted -> we can use RAII
*/
    IntPtr p = new Integer; // behavior like a pointer but it is a local object - type of Smart pointer
    p->SetValue(3);     // with overload -> 
    (*p).SetValue(3);   // with overload *
}

int main()
{  
    CreateInteger();
    return 0;
}
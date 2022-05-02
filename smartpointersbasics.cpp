#include "iostream"
#include "Integer.h"
#include <memory>   // smart pointers

class IntPtr 
{
    Integer *m_p;
    public:
        IntPtr(Integer *p) : m_p(p) {}
        ~IntPtr() {delete m_p;}
        Integer *operator->() {return m_p;}
        Integer & operator *() {return *m_p;}
};

void Process(std::unique_ptr<Integer> ptr)
{
    std::cout << ptr->GetValue() << std::endl;
}

void ProcessShared(std::shared_ptr<Integer> ptr)
{
    std::cout << ptr->GetValue() << std::endl;
}

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

    std::unique_ptr<Integer> q(new Integer); // the same as  IntPtr q = new Integer;, will be deleted after... we cant make a copy of unique pointer
    // auto q2(q); is not possible it is a deleted pointer, so it has only move semantics
    // Process(p); is also not possible due to copy
    Process(std::move(q));  // transfers ownership to ptr after the scope it will be released

    std::shared_ptr<Integer> t(new Integer);    // if we want to share the resource in code, its incremented per share and decremented per scope release
    t->SetValue(5);
    ProcessShared(t);
    std::cout << t->GetValue() << std::endl;
}

int main()
{  
    CreateInteger();
    return 0;
}
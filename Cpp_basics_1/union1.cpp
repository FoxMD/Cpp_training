#include <iostream>
// are placed behind each other in memory
union Test
{
    int x;
    char c;
    Test(): x{1}{ std::cout << __FUNCSIG__ <<std::endl;}
    ~Test() {}
};

// A and B wont be created explicitly needs to be done manually
/*
union UDT
{
    A a;
    B b;
    UDR(){}
    ~UDT(){}
};
*/
int main()
{
    Test t;
    t.x = 100;
/*
    UDT udt;
    new(&udt.a) A{}; // initialize it, memory is already reserved
    udt.a.~A();
*/
    return 0;
}
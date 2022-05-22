#include <iostream>

class TestA
{
    public:
        TestA() { std::cout << "Constructor TestA" << std::endl; }
        ~TestA() { std::cout << "Destructor TestA" << std::endl; }
};

class TestB
{
    public:
        TestB() { std::cout << "Constructor TestB" << std::endl; }
        ~TestB() { std::cout << "Destructor TestB" << std::endl; }
};

class Test
{
    TestA *pA{};
    TestB b{};
    public:
        Test() 
        { 
            std::cout << "Constructor Test" << std::endl;
            pA = new TestA;
            throw std::runtime_error("Error");  
        }
        ~Test() 
        { 
            std::cout << "Destructor Test" << std::endl; 
            delete pA;     
        }
};

int main()
{
    try
    {
        Test t;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
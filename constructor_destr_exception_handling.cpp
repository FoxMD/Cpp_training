#include <iostream>
#include <memory>

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
    // TestA *pA{}; // because of throw will prohibit call to destructor
    std::unique_ptr<TestA> pA{};
    TestB b{};
    public:
        Test() 
        { 
            std::cout << "Constructor Test" << std::endl;
            // pA = new TestA;  dont need for RIAA
            pA.reset(new TestA);
            throw std::runtime_error("Error");  
        }
        ~Test() 
        { 
            std::cout << "Destructor Test" << std::endl; 
            // delete pA;  smart pointer doesnt need it
            // dont throw exceptions in destructors !!!
        }
};

int Sum(int x, int y) noexcept(true)  // this function wont throw an exception, if you write false it can throw exception
{   // if we know some fcn called can thro we can write noexcept(noexcept(fcn(x))) move operators schould have noexcept
    return y + x;
}

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
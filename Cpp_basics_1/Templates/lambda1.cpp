#include <iostream>

template<typename T>
struct Unnamed  // one of implementation from compiler
{
    T operator()(T x, T y)const {
        return x + y;
    }
};

int main()
{
    []()
    {
        std::cout << "lambda" << std::endl;
    }();

    auto fn = []() {        // function instance
        std::cout << "named lambda" << std::endl;
    };
    fn();
    std::cout << typeid(fn).name() << std::endl;

    // can be also without -> double
    auto sum = [](int x, int y) -> double   
    {
        return x + y;
    }; 
    std::cout << sum(5, 2) << std::endl;

    Unnamed<int> n;
    std::cout << n(3, 5) << std::endl;

    // generic lambda
    auto fce = [](auto x, auto y)noexcept(false)    
    {
        return x + y; 
    };

    return 0; 
}
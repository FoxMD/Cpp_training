#include <iostream>
/*
template<typename T>
void Print(std::initializer_list<T> args)
{
    for(const auto &x : args)
    {
        std::cout << x << "\n";
    }
}
*/

void Print()
{

}

template<typename T, typename...Params> // variadic template, template parameter pack
void Print(T a, Params... args)
{
    // you need to use recursion, to grab your parameters
    // base case function
    Print(args...);
}

int main()
{
    //Print({1,2,3.2,4,5}); // wont work on first because of 2 types (int + float under auto)
    Print(1, 2, 3.2, 4, 5);
    return 0;
}
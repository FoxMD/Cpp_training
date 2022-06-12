#include <iostream>
/*
template<typename T>
T Max(T &a, T &b)
{
    return (a > b)? a : b;
}
*/
template<typename T, typename Func>
T Fcn(T &a, T &b, Func fcn)
{
    return fcn(a, b);
}

int main()
{
    int a{5};
    int b{10};

    std::cout << Fcn(a, b, [](int x, int y) {return (x > y)? x : y;});

    return 0;
}
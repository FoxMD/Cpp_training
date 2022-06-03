#include <iostream>

template<typename T>
T Add(T a, T b)
{
    return a + b;
}

int main()
{
    Add(static_cast<double>(3), 3.5);
    Add<double>(3, 3.5);
}
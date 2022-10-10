#include <iostream>

void Print(int &x)
{
    std::cout << "Reference" << std::endl;
}

void Print(const int &x)
{
    std::cout << "constant reference" << std::endl;
}

void Print(int &&x)
{
    std::cout << "R-value bind" << std::endl;
}


int main()
{
    const int x = 5;
    int y = 10;
    Print(y);   // Reference
    Print(x);   // Constant reference
    Print(3);   // Constant values bind to R-Value

    // Used for move semantics -> obj 1 -> obj 2 shallow copy -> obj 1 set to null 
    return 0;
}
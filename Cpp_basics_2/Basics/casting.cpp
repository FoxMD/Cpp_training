#include <iostream>

int main()
{
    // standard C casting
    int i = 15;
    float k = 16.3f / (float)i;
    std::cout << k << std::endl; 
    // c++ casting
    int j = 15;
    float l = 16.3f;
    l /= static_cast<float>(j);
    std::cout << l << std::endl; 

    return 0;
}
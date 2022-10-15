#include <iostream>

unsigned int faculty(unsigned int n)
{
    if(n > 1) 
        return n*faculty(n-1);
    else if (n == 1)
        return 1;
    else
        return 0;
}

int main()
{   
    int nFac = 0;
    nFac = faculty(12);
    std::cout << nFac <<std::endl;
    return 0; 
}
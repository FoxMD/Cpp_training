#include <cstdlib>
#include <iostream>

int main()
{
    //std::unique_ptr<int> p{new int[5]{1,2,3,4,5}};  // probles with delete and referencing p[0] = 10; not possibly... need to use p.get()[0]=10;
    std::unique_ptr<int[]> p{new int[5]{1,2,3,4,5}};  // for shared pointer in C++17
    // use a container for dynamic arrays
    
    return 0;
}
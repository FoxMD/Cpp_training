#include <cstdlib>
#include <iostream>

// make functions can¨t use custom deleters !!!
class Point
{
    public:
        Point(int x, int y) {};
};

int main()
{
    //std::unique_ptr<int> p{new int{5}};  // for shared pointer in C++17
    auto p = std::make_unique<int>(5);      // creates type in heap initializes with values and stores unique ptr and returns it
    // return p from type unique pointer of type int with initializer 5

    auto pt = std::make_unique<Point>(3,5);
    auto pArr = std::make_unique<int[]>(5); // argument specifies size
    pArr[0] = 10;

    // same goes to share -> make_shared<>();
    return 0;
}
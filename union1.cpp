#include <iostream>
// are placed behind each other in memory
union Test
{
    int x;
    char c;
    Test(): x{1}{}
    ~Test() {}
};

int main()
{
    Test t;
    t.x = 100;

    return 0;
}
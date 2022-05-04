#include "iostream"
#include "Integer.h"

int main()
{
    // primitive to user
    Integer a{5};
    Integer b = 4; // initialization, called constructor with const int

    a = 7; // assignment implicit conversion
    // if we type explicit before our constructor we can disallow it.

    // user to primitive
    // type conversion operator ... operator<type>() no arg or return
    int x = static_cast<int>(a); // calls Integer::operator int() {return *m_pInt;} it is recomendet to use explicit (without call is int x = a;), with static_cast
    return 0;
}
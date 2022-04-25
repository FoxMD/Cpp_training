#include "iostream"

int main()
{
    // for C and Cpp
    int *p = (int *)calloc(5, sizeof(int)); // size for 5 ints
    if(p == NULL)
    {
        return -1;
    }

    *p = 5;
    free(p);
    p = NULL;   // needs to be set to NULL /dying pointer

    // For Cpp new/delete
    int *q = new int;   // or new int(5); for init with number
    *q = 6;             // initialize with number
    delete q;
    q = nullptr;
    // new can call Constructor
}
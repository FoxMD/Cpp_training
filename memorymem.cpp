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




}
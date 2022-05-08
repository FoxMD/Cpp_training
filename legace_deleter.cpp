#include <cstdlib>
#include <iostream>

// call function object
struct Free{
    void operator()(int* p)
    {
        free(p);
        std::cout << "Pointer freed" << std::endl;
    }
};

int main()
{
    //int *p = (int*) malloc(4);
    std::unique_ptr<int, Free> p{(int*) malloc(4), Free{}}; // specify the deleter and obj of deleter; we can do it with fcn but not recomendet void(*)(int*)
    // std::shared_ptr<int> p{(int*) malloc(4), Free{}}; // for shared pointers
    *p = 100;
    std::cout << *p << '\n';
    //free(p);
    return 0;
}

/*
// Undefined behaviour !!
int main()
{
    //int *p = (int*) malloc(4);
    std::unique_ptr<int> p{(int*) malloc(4)};
    *p = 100;
    std::cout << *p << '\n';
    //free(p);
    return 0;
}
*/
#include "iostream"
#

int Add(int* a, int* b);
void AddVal(int* a, int* b, int* result);
void Swap(int* a, int* b);
void Factorial(int* a, int* result);

int main()
{
    int a{4}, b{6}, x{0};
    
    x = Add(&a, &b);
    std::cout << x << std::endl; 
    x = 0;

    AddVal(&a, &b, &x);
    std::cout << x << std::endl; 
    x = 0;

    Swap(&a, &b);
    std::cout << a << " " << b << std::endl; 

    a = 10;
    Factorial(&a, &x);
    std::cout << x << std::endl; 
}

int Add(int* a, int* b)
{
    return *a + *b;
}

void AddVal(int* a, int* b, int* result)
{
    *result = (*a + *b);
}

void Swap(int* a, int* b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp; 
}

void Factorial(int* a, int* result)
{  
    static int tmp = 1;
    while(*a > 0)
    {
        tmp *= *a;
        --*a;
        Factorial(a, &tmp);
    }
    *result = tmp;
}
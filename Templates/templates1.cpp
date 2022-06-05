#include <iostream>

template<typename T>
T Add(T a, T b)
{
    return a + b;
}

template<typename T>
T Max(T a, T b)
{
    return x > y ? x : y;
}

// explicit instantiation
template<> const char * Max(const char *a, const char *b)
{
    return strcmp(a,b) > 0? a : b;
}

template<typename T, int size>
T Sum(T (&parr)[size])
{
    T sum{};
    for(int i = 0; i < size; ++i)
    {
        sum += parr[i];
    }
    return sum;
}

int main()
{
    Add(static_cast<double>(3), 3.5);
    Add<double>(3, 3.5);
    int (*pfn)(int, int) = Add; // instantiate for int

    // explicit instantiation, for example for strings
    // explicit instantiation needs to be in cpp
    const char *b{"B"};
    const char *a{"A"};
    Max(a, b);

    int arr[]{1,2,3,4};
    int sum = Sum(arr);
}
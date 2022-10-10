#include <iostream>

template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp)
{
    for(int i = 0; i < size -1; ++i)
    {
        for(int j = 0; j < size -1; ++j)
        {
            if(comp(arr[j], arr[j + 1]))
            {
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j + 1]);
                arr[j + 1] = std::move(temp);
            }
        }
    }
}

bool Comp(int x, int y)
{
    return x > y;
}

bool Comp1(int x, int y)
{
    return x < y;
}

struct Comp2 
{
    bool operator()(int x, int y) { return x > y; }
};

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation)
{
    for(int i = 0; i < size -1; ++i )
    {
        operation(arr[i]);
    }
}

int main()
{
    Comp2 comp;
    comp(3, 5); // comp.operator()(3, 5)

    int arr[]{1,4,9,8,0,3};
    for(auto x: arr)
    {
        std::cout << x << ", ";
    }
    Sort(arr, [](auto x, auto y) { return x > y;});
    for(auto x: arr)
    {
        std::cout << x << ", ";
    }

    ForEach(arr, [](auto x) { std::cout << x << std::endl;});
    
    int offset = 4;
    ForEach(arr, [offset](auto &x) { x += offset;});    // capture list [] contains some local variable, but it cannot be modified
    
    // to access and modify the value in capture list we need to use mutable
    ForEach(arr, [offset](auto &x) mutable { x += offset; ++offset;});
    
    return 0;
}

/*  Implementation from compiler
template<typename T>
struct Unnamed
{
    int offset;
    Unnamed() : offset(off) const {}    // if we use mutable there is no const
    void operator()(T &x)
    {
        x += offset;
        ++offset;
    }
};
*/
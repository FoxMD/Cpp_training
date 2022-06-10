#include <iostream>

//template<typename T, int size>
//void Sort(T(&arr)[size])
//{
//    for(int i = 0; i < size -1; ++i)
//    {
//       for(int j = 0; j < size -1; ++j)
//        {
//            if(arr[j] > arr[j + 1])
//            {
//                T temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//   }
//}
//using Comparator = bool(*)(int, int);   // fnc pointers cannot be optimized
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

int main()
{
    Comp2 comp;
    comp(3, 5); // comp.operator()(3, 5)

    int arr[]{1,4,9,8,0,3};
    for(auto x: arr)
    {
        std::cout << x << ", ";
    }
    Sort(arr, Comp);
    for(auto x: arr)
    {
        std::cout << x << ", ";
    }
    return 0;
}
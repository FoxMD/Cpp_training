#include "iostream"

int main()
{
    int arr[] = {1,2,3,4,5};

    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << std::endl;
    }

    for (int element : arr)
    {
        std::cout << element << std::endl;
    }

    for (auto &element : arr)
    {
        element += 1;
        std::cout << element << std::endl;
    }

    for (const auto &element : arr)
    {
        std::cout << element << std::endl;
    }

    int *begin = &arr[0];   // Or auto begin = &arr[0];
    int *end = &arr[5];
    
    while (begin != end)
    {
                std::cout << *begin << std::endl;
                ++begin;
    }

    int *begin_modern = std::begin(arr);    
    int *end_modern = std::end(arr);

    while (begin_modern != end_modern)
    {
                std::cout << *begin << std::endl;
                ++begin;
    }

    return 0;
}
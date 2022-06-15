#include <iostream>
#include <array>
#include <vector>

// Quicker and reliabler than own implementation
int main()
{
    // array
    // supports iterators, cannot grow
    std::array<int, 5> arr;
    for(int i = 0; i < arr.size(); ++i)
    {
        arr[i] = i;
    }
    // iterator - pointerlike object
    auto itr = arr.begin();
    for(auto x: arr)
    {

    }
    arr.data();

    // vector - like a dynamic array
    std::vector<int> coll{1,2,3,4};
    for(int i = 0; i < 5; ++i)
    {
        coll.push_back(i * 10);
    }
    return 0;
}
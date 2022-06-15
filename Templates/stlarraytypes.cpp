#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

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
    coll.size();
    auto itr1 = coll.begin();
    while(itr1 != coll.end())
    {
        std::cout << *itr1++ << std::endl;
    }
    coll.insert(coll.begin(), 45);
    coll.erase(coll.begin());

    // deque - double ended que, grows automaticaly
    std::deque<int> deq{1,2,3,4};
    for(int i = 0; i < 5; ++i)
    {
        deq.push_back(i * 10);
    }
        for(int i = 0; i < 5; ++i)
    {
        deq.push_front(i * 10);
    }
    deq.insert(deq.begin(), 45);
    deq.erase(deq.begin());
    deq.pop_back();
    deq.pop_front();

    // list, forward_list - 2way linked list/1way, insertion/deletion friendly
    std::list<int> lst;
    for(int i = 0; i < 5; ++i)
    {
        lst.push_back(i * 10);  // forward has push_front
    }
    auto itr2 = lst.begin();
    lst.insert(itr2, 12);
    lst.erase(itr2);

    std::forward_list<int> flst;
    for(int i = 0; i < 5; ++i)
    {
        flst.push_front(i * 10); 
    }
    auto itr3 = flst.begin();
    flst.insert_after(itr3, 12);
    flst.erase_after(itr3);
    
    return 0;
}
#include <iostream>
#include <vector>

int main()
{
    int arr[10];
    int* pArr = new int[10];
    for(int i = 0; i < 10; i++)
    {
        pArr[i] = i * 10;
    }
    // not good for dynamic characteristics... 

    std::vector<int> data{1,2,3};
    for(int i = 0; i < 5; ++i)
    {
        data.push_back(i * 10);
    }

    // access
    for(int i = 0; i < data.size(); ++i)
    {

    }

    for (auto x : data)
    {

    }

    auto it = data.begin();
    std::cout << *it;
    ++it;
    
    // delete
    it = data.begin();
    data.erase(it);
    
    // insert
    it = data.begin() + 5;
    data.insert(it, 500); 
}
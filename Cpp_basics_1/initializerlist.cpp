#include <iostream>
#include <initializer_list>
#include <cassert>

class Bag
{
    int arr[10];
    int m_Size{};
    public:
        Bag(std::initializer_list<int> values)
        {
            auto it = values.begin();
            while(it != values.end())
            {
                Add(*it);
                it++;
            } 
            /*
            for(auto x : values)
            {
                
            }
            */
        }
        void Add(int value)
        {
            //assert(m_size < 10);
            arr[m_Size++] = value;
        }
        void Remove()
        {
            m_Size--;
        }
        int operator [](int index)
        {
            return arr[index];
        }
        int GetSize()const
        {
            return m_Size;
        }
}; 

int main()
{
    int x{0};
    int arr[5]{0,1,2,3,4};
    std::initializer_list<int> data = {1,2,3,4,5};
    Bag b{0,1,2,3,4}; // only with initializer list possilble
    return 0;
}
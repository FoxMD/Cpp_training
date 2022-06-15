#include <iostream>
#include <set>
#include <map>
#include <functional>

void Set()
{
    std::set<int> s{0,1,2,3,4,5};
    s.insert(1);
    s.insert(2);

    auto itr = s.begin();
    s.erase(0); // 0 is the key for value 0
    s.erase(s.begin());
    auto found = s.find(9);

    // we can sort them 9->0
    std::set<int, std::greater<int>> sg{0,1,2,3,4,5};
    sg.insert(9);
    sg.insert(2);

    // set doesnt allow duplicates
}

void Multiset()
{
    std::multiset<int> s{0,1,2,3,4,5};
    s.insert(1);
    s.insert(2);

    auto found = s.equal_range(3);
    while(found.first != found.second)
    {
        std::cout << *found.first++ << std::endl;
    }
}

// key + value
void Map()
{
    std::map<int, std::string> m{{1, "Superman"},{2, "Batmann"},{3, "Arrow"}};
    m.insert(std::pair<int, std::string>(4, "Aquaman"));
    m.insert(std::make_pair(6, "Thalia"));

    m[0] = "Flash"; // we cannot modify key, but we can modify value
    auto itr = m.begin();
    std::cout << itr->first << ": " << itr->second << std::endl; 

    for(const auto &element: m)
    {
        std::cout << element.first << ": " << element.second << std::endl; 
    }

    m.erase(0);
    m.find(4);
}

// for multiple entries
void Multimap()
{
    std::multimap<int, std::string> m{{1, "Superman"},{2, "Batmann"},{3, "Arrow"}};
    m.insert(std::pair<int, std::string>(4, "Aquaman"));
    
    auto found = m.equal_range(6);
    while(found.first != found.second)
    {
        std::cout << found.first->first << ": " << found.first->second << std::endl;
        found.first++;
    }
}

int main()
{
    return 0;
}
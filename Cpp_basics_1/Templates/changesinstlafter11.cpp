/* Changes from 11+:
    - containers use noexcept specifiers (on iterators)
    - containers have brace initializer
        - std::vector<int> myVec{1,2,3,4,5}
    - they preffer std::move before copy
    - emplace/emplace_back were added
        - emplace makes a construction of object
        - push placec an existing object
        - example:
            - std::vector<std::pair><int, std::string>> data;
            - data.push_back(std::pair<int, std::string>{100, "C++"});
            - data.emplace_back(100, "C++");
    - for use of move operation on our classes we need to specify noexcept on move operations(move constructor and operator)

    - vector .size, .capacity
        - even if you remove elemenst the capacity wont shrink
        - leads to waste of memory
        - from c++11 there is a vector: .shrink_to_fit();
        - which leads to capacity = size

    - in C++17 - filesystem library, good for files
        - use with std::vector or std::string and theres .data() operator
        - no need for memory management on heap

    - removing elements in vector, list, deque with c++20 style erase()
    - emplace_hint, is quicker when you have a iterator close to a position
        - it is quicker if you give it a correct place hint
    - contains (it is like find) c++20
    - update a value since c++17 - .extract
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <deque>
#include <set>
#include <list>

void Emplace()
{

}
void Shrink()
{

}
int File()
{
    std::ifstream input{"main.cpp"};
    if(!input)
    {
        return -1;
    }
    //char buffer[1024]{};
    //input.read(buffer, 1024);
    auto size = std::filesystem::file_size("main.cpp");
    //  //  char * buff = new char[size]{};
    //  //  input.read(buff, size);
    std::vector<char> buff;
    buff.resize(size);
    input.read(buff.data(), size);
    std::cout << buff.data();
    // // std::cout << buff;
    // // delete []buff;
    return 0;
}
void Erase()
{
    std::vector<int> vInt{1,2,3,4,5};
    std::list<int> lstInt{1,2,3,4,5,6};
    std::deque<int> deqInt{1,2,3,4,5,6};

    std::erase(vInt, 2);
    std::erase(lstInt, 2);
    std::erase(deqInt, 2);
}
void EmplaceHint()
{
    std::set<int> data{1,2,3,4,5,6};
    data.emplace_hint(data.begin(), 0);
    auto found = data.contains(6);
    if(found)
    {
        std::cout << "Found";
    }
}
void Extract()
{
    std::set<std::string> names{"Pavel", "Lichal", "David"};
    auto it = names.find("Lichal");
    auto name = *it;
    name[0] = 'M';
    names.erase(it);
    names.insert(name);
    
    // much better way since c++17
    auto node = names.extract(it);
    node.value()[0] = 'M';
    names.insert(std::move(node));
}

int main()
{

    return 0;
}
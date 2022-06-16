#include <iostream>
#include <unordered_set>
#include <string>

void UnSet()
{
    std::unordered_set<std::string> coll;
    coll.insert("Hulk");
    coll.insert("Iron man");
    coll.insert("The Flash");
    coll.insert("Batman");
    coll.insert("Wolwerine");
    coll.insert("Wonder woman");

    for(const auto element: coll)
    {
        std::cout << "Bucket #:" << coll.bucket(element) << " contains: " << element << std::endl;
    }

    std::cout << "Bucket count: " << coll.bucket_count() << std::endl;
    std::cout << "Number of elements: " << coll.size() << std::endl;
    std::cout << "Load factor: " << coll.load_factor() << std::endl; 
}

int main()
{
    return 0;
}
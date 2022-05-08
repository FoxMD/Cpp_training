#include <iostream>
#include <cstring>
#include <string>

int main()
{
    std::string first;     // Length not variable
    std::string last;
    std::getline(std::cin, first);
    std::getline(std::cin, last);
    
    std::string pFullName = first + last;   // wont work, local scope of fullname in Combine
 
    std::cout << pFullName << std::endl;
    printf("%s", pFullName.c_str());

    return 0;
}
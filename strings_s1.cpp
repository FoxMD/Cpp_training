#include <iostream>
#include <cstring>

const char* Combine(const char* pFirst, const char* pLast)
{
    //char fullname[20];
    char *fullname = new char[strlen(pFirst) + strlen(pLast) + 1]; // + null termination
    strcpy(fullname, pFirst);
    strcat(fullname, pLast);
    return fullname;
} 

int main()
{
    char first[10];     // Length not variable
    char last[10];
    std::cin.getline(first, 10);
    std::cin.getline(last, 10);
    const char* pFullName = Combine(first, last);   // wont work, local scope of fullname in Combine
 
    std::cout << pFullName << std::endl;
    delete[] pFullName;

    return 0;
}
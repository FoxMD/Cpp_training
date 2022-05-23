#include <iostream>
#include <string>

int main()
{
    std::string rawstring{R"(C:\ignored\backslach)"};
    std::string specialchar{R"MSG(This is my super C++ special message with everthing "(In C++17)")MSG"};
    return 0;
}

// more to come """"
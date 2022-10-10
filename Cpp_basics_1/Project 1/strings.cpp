#include <iostream>
#include <string>
#include <fstream>

void Write()
{
    std::ofstream out{"data.txt"};
    out << "Hello world" << std::endl;
    out.close();
}

void Read()
{
    std::ifstream in{"data.txt"};
    std::string message;
    std::getline(in, message);
    if(in.good()) std::cout << "reading succesfull" << std::endl;
    in.close();
    //in.eof() - end of file
    //in.fail() - some operation failed (reading non existing file or line)
    //in.clear() - resets flags
    //in.setstate(std::ios::failbit); - sets a failbit
}

int main()
{
    std::string rawstring{R"(C:\ignored\backslach)"};
    std::string specialchar{R"MSG(This is my super C++ special message with everthing "(In C++17)")MSG"};
    return 0;
}

// more to come """"
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    int a{5}, b{6};
    int sum = a + b;

    //std::cout << "Sum of " << a << " & " << b << " is " << sum << std::endl;
    //std::string output = "Sum of " + a + " & " + b + " is " + sum; 
    //std::stringstream ss - rw
    //std::istringstream is - r
    //std::ostringstream os - w
    std::stringstream ss;
    ss << "Sum of " << a << " & " << b << " is " << sum << std::endl;
    std::string s = ss.str();
    std::cout << s << std::endl;

    auto ssum = std::to_string(sum);

    std::string data = "12 15 16";
    int a;
    std::stringstream dataStream;
    dataStream.str(data);

    while(!dataStream.fail())   // dataStream >> a so it terminates sooner
    {
        dataStream >> a;
        std::cout << a << std::endl;
    }

    return 0;
}
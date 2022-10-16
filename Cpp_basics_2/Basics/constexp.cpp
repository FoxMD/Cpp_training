#include <iostream>
#include <string>

constexpr std::string_view HW_VERSION = "1.2";  // C++17 +

void GPIO_Init()
{
    if constexpr (HW_VERSION == "1.2")
    {

    }
    else if constexpr (HW_VERSION == "2.0")
    {

    }
    else
    {

    }
}

int main()
{
    GPIO_Init();
    return 0;
}
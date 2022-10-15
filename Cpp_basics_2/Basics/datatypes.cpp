#include <iostream>
#include <cstdint>

int main()
{
    bool val0 = true;   // 8bit
    char val1 = 10;     // 8bit
    short val2 = 42;    // 16bit
    int val3 = 33;      // 32bit
    float val4 = 12.6f; // 32bit
    double val5 = 13.0; // 64bit

    uint8_t val6 = 12;  // 8bit
    uint16_t val7 = 13; // 16bit
    uint32_t val8 = 14; // 32bit
    uint64_t val9 = 15; // 64bit

    //int8_t -> int64_t signed variation

    int32_t input = 0;
    std::cout << "Enter a number" << std::endl;
    std::cin >> input;
    std::cout << "Your value: " << input << std::endl;

    return 0;
}
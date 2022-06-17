#include <iostream>
#include <list>
#include <string>

std::list<int> g_Data;
const size_t SIZE{5000000};

void Download()
{
    std::cout << R"MSG([Downloader] Started download)MSG" << std::endl;
    for(int i = 0; i < SIZE; ++i) {
        g_Data.push_back(i);
    }
    std::cout << R"MSG([Downloader] Finished download)MSG" << std::endl;
}

int main()
{
    std::cout << R"MSG([Main] User started download)MSG" << std::endl;
    Download(); // takes time
    std::cout << R"MSG([Main] User started ...)MSG" << std::endl;

    return 0;
}
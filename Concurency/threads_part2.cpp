#include <iostream>
#include <list>
#include <string>
#include <thread>

std::list<int> g_Data;
const size_t SIZE{5000000};

void Download(std::string arg)
{
    std::cout << R"MSG([Downloader] Started download: )MSG" << arg << std::endl;
    for(int i = 0; i < SIZE; ++i) {
        g_Data.push_back(i);
    }
    std::cout << R"MSG([Downloader] Finished download)MSG" << std::endl;
}

int main()
{
    std::string name{"MyFileName.txt"};
    std::cout << R"MSG([Main] User started download)MSG" << std::endl;
    std::thread thDownaloader(Download, name);
    thDownaloader.detach();
    std::cout << R"MSG([Main] User started ...)MSG" << std::endl;

    if(thDownaloader.joinable())    
        thDownaloader.join();
    
    system("pause");
    return 0;
}
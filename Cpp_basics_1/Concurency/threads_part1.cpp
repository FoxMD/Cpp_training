#include <iostream>
#include <list>
#include <string>
#include <thread>

/*  std::thread
    - accepts a callable and executes in a separate thread
    - constructor does not wait for the thread to start, it returns immediately
        - we need to wait for the child thread to finish
*/
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
//    std::cout << R"MSG([Main] User started download)MSG" << std::endl;
//    std::thread thDownaloader(Download);
//    std::cout << R"MSG([Main] User started ...)MSG" << std::endl;

//    thDownaloader.join();   // call before the object is destroyed
    // if we dont wanna wait we can:
    std::cout << R"MSG([Main] User started download)MSG" << std::endl;
    std::thread thDownaloader(Download);
    thDownaloader.detach();
    std::cout << R"MSG([Main] User started ...)MSG" << std::endl;
    // exists before finishing the thread
    if(thDownaloader.joinable())    
        thDownaloader.join();
    
    system("pause");    // we see detached task to finish
    return 0;
}
#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <mutex>

std::list<int> g_Data;
const size_t SIZE{5000000};
std::mutex g_Mutex;

class String
{
    public:
        String() {std::cout << "String()" << "\n";} // default
        String(const String &) {std::cout << "String(const String&)" << "\n";} // copy 
        ~String() {std::cout << "~String()" << "\n";} // destructor
        String & operator=(const String&) { // assignment operator
            std::cout << "Operator =(const String&)" << std::endl;
            return *this;
        }
};

void Download(String &arg)
{
    std::cout << R"MSG([Downloader] Started download: )MSG" << std::endl;
    for(int i = 0; i < SIZE; ++i) {
        g_Mutex.lock();
        g_Data.push_back(i);
    }
    g_Mutex.unlock();
    std::cout << R"MSG([Downloader] Finished download)MSG" << std::endl;
}

void Download2(String &arg)
{
    std::cout << R"MSG([Downloader 2] Started download: )MSG" << std::endl;
    for(int i = 0; i < SIZE; ++i) {
        g_Mutex.lock();
        g_Data.push_back(i);
    }
    g_Mutex.unlock();
    std::cout << R"MSG([Downloader 2] Finished download)MSG" << std::endl;
}

int main()
{
    String name;
    std::cout << R"MSG([Main] User started download)MSG" << std::endl;
    // race condition - 2 thread are using 1 data
    std::thread thDownaloader(Download, std::ref(name));    // for const String &arg use std::cref()
    std::thread thDownaloader2(Download2, std::ref(name));
    //thDownaloader.detach();
    std::cout << R"MSG([Main] User started ...)MSG" << std::endl;

    if(thDownaloader.joinable())    
        thDownaloader.join();

    if(thDownaloader2.joinable())    
        thDownaloader2.join();
    
    system("pause");
    return 0;
}
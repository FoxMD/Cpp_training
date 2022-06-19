#include <iostream>
#include <list>
#include <string>
#include <thread>

std::list<int> g_Data;
const size_t SIZE{5000000};

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
        g_Data.push_back(i);
    }
    std::cout << R"MSG([Downloader] Finished download)MSG" << std::endl;
}

int main()
{
    String name;
    std::cout << R"MSG([Main] User started download)MSG" << std::endl;
    std::thread thDownaloader(Download, std::ref(name));
    //thDownaloader.detach();
    std::cout << R"MSG([Main] User started ...)MSG" << std::endl;

    if(thDownaloader.joinable())    
        thDownaloader.join();
    
    system("pause");
    return 0;
}
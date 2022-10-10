#include <iostream>
#include <filesystem>

int main()
{
    try {
        std::cout << std::filesystem::current_path() << std::endl;
        std::error_code ec{};
        std::filesystem::current_path(R"(E:\Data)", ec);
        if(ec){
            std::cout << "Data does not exist" << std::endl;
        }
    }
    catch(std::exception& ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    return 0; 
}
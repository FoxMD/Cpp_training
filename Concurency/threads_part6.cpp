#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <mutex>
#include <Windows.h>
#include <future>

int Operation(std::promise<int> &data)
{
    using namespace std::chrono_literals;
    auto f = data.get_future();
    try {
        auto count = f.get(); // wait for the data
        int sum{};
        for(int i = 0; i < count; ++i) {
            std::cout << '.';
            sum += i;
            std::this_thread::sleep_for(300ms);
        }
        return sum;
    }
    catch(std::exception &ex) {
        std::cout << "Exception happend: " << ex.what() << std::endl;
    }
}

int main()
{
    std::promise<int> data;
    std::future<int> result = std::async(std::launch::async, Operation, std::ref(data));    // part of high lvl concurency, takes calloble
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "main continues and prints asynchronously after 1s\n" << std::endl;
    try {
        throw std::runtime_error{"Data not available"};
        data.set_value(10);

        if(result.valid()){
            auto sum = result.get();
            std::cout << sum << std::endl;
        }
    }
    catch(std::exception &ex) {
        data.set_exception(std::make_exception_ptr(ex));
    }
    return 0;
}
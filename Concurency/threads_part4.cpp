#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <mutex>
#include <Windows.h>
#include <future>

int Operation(int count)
{
    using namespace std::chrono_literals;
    int sum{};
    for(int i = 0; i < count; ++i) {
        std::cout << '.';
        sum += i;
        std::this_thread::sleep_for(300ms);
    }
    return sum;
}

int main()
{
    // execute as a task
    std::future<int> result = std::async(Operation, 10);    // part of high lvl concurency, takes calloble
    std::cout << "main continues" << std::endl;
    // lauch policy:
    // deferred - task is synchronous
    // async - task is asynchronous - without lauch policy doesnt need always create a new thread

    // std::promise is a input channel 
    // std::future is a output channel
    if(result.valid()){
        auto sum = result.get();
        std::cout << sum << std::endl;
    }
    return 0;
}
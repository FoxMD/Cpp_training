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
    std::future<int> result = std::async(std::launch::async, Operation, 10);    // part of high lvl concurency, takes calloble
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "main continues and prints asynchronously after 1s\n" << std::endl;

    if(result.valid()){
        // wait_until takes timepoint
        // std::chrono::system_clock::now + 1s -> wait for 1 secund from now 
        auto status = result.wait_for(std::chrono::seconds(1));
        switch(status)
        {
            case std::future_status::deferred:  // you cannot wait for it
                break;
            case std::future_status::ready:     // you can get call get
                break;
            case std::future_status::timeout:   // if it is not ready (still running)
                break;
        }
        // result.wait(); // waits until shareds state is ready but blocks main
        auto sum = result.get();
        std::cout << sum << std::endl;
    }
    return 0;
}
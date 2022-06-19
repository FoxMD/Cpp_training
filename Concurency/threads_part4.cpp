#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <mutex>
#include <Windows.h>

void Process()
{
    std::cout << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::thread t1(Process);
    auto id = t1.get_id();
    std::cout << id <<std::endl;
    // for linux: pthread_setname_np
    HANDLE handle = t1.native_handle();
    SetThreadDescription(handle, L"MyThread"); // L for widestring
    // this handle was added in Windows 10 developers update

    int cores = std::thread::hardware_concurrency();
    std::cout << cores << std::endl;
    t1.join();
    system("pause");
    return 0;
}
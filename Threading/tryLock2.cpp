#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx1, mtx2, mtx3;

void threadFunction(std::string name)
{
    if (std::try_lock(mtx1, mtx2, mtx3) == 0) {
        std::cout << "Thread " << name << " locks all mutex." << std::endl;
        mtx1.unlock();
        mtx2.unlock();
        mtx3.unlock();
    } else {
        std::cout << "Thread " << name << " failed to lock all mutex." << std::endl;
    }
}

int main()
{
    std::thread t1(threadFunction, "1");
    std::thread t2(threadFunction, "2");
    t1.join();
    t2.join();
}


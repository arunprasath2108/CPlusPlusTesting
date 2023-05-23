#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;
int count = 0;

void increment(int num) {
   for(int i=0;i<5;i++)
    {
        mtx.lock();
        count++;
        std::cout << "Num :" << num << " count -> " << count << std::endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);
    t1.join();
    t2.join();
}
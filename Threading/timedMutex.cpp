#include <iostream>
#include <thread>
#include <mutex>

std::timed_mutex mtx;
int sharedVar = 0;

void increment(std::string name)
{
    if (mtx.try_lock_for(std::chrono::seconds(1)))
    {
        ++sharedVar;
        std::cout << " shared var incremented by thread :  " << name << std::endl;
        mtx.unlock();
    }
    else
    {
        std::cout << " unable to lock by thread : " << name << std::endl;
    }
}

int main()
{
    std::thread t1(increment, "t1");
    std::thread t2(increment, "t2");

    t1.join();
    t2.join();

    std::cout << "Final shared variable : " << sharedVar << std::endl;

}
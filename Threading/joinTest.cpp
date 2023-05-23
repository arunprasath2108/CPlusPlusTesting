#include <iostream>
#include <thread>
#include <chrono>

 
void foo()
{
    std::cout << " In function" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
}
 
int main()
{ 
    std::thread t;
    std::cout << "before starting, joinable: " << t.joinable() << '\n';
 
    t = std::thread(foo);
    std::cout << "after starting, joinable: " << t.joinable() << '\n';
 
    t.join();
    std::cout << "after joining, joinable: " << t.joinable() << '\n';
 
    t = std::thread(foo);
    t.detach();
    std::cout << "after detaching, joinable: " << t.joinable() << '\n';
    // std::this_thread::sleep_for(std::chrono::seconds(2));
}
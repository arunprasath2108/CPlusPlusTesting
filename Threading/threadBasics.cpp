#include <iostream>
#include <thread>

//1.Function pointer
void print(int num) {
        std::cout << "1. Function pointer " << std::endl;
}

//3.functor
class Base {
    public:
    void operator()(int num) {
        std::cout << "3. in functor class" << std::endl;
    }
};

//-std=c++11
//4. non-static member function
class First {
    public:
    void print() {
        std::cout << "4. in A class" << std::endl;
    }
    static void display() {
        std::cout << "5. in A class display method" << std::endl;
    }

};

int main() {

    //1.Function pointer
    std::thread t(print, 5);
    t.join();

    //2.Lambda expression
    auto lambdaFunc = [](int num) {
            std::cout << "2. lambda function " << std::endl;
    };
    //we can directly use lambda expression here, instead of lamdaFunc;
    std::thread t1(lambdaFunc, 5);
    t1.join();

    // //3.Functor
    std::thread t2(Base(), 5);
    t2.join();

    // //4.non-static member
    First obj;
    std::thread t3(&First::print, &obj);
    t3.join();

    //5.static member
    //no need of object as parameter -> bcz, the display method is static;
    std::thread t4(&First::display);
    t4.join();

    return 0;
}

//we can check how many threads are in Processor
// unsigned int numThreads = std::thread::hardware_concurrency();
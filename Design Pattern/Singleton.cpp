#include<iostream>
#include<thread>
#include <mutex>
std::mutex mutex1;
std::mutex mutex2;

class Singleton {

    int data;
    static Singleton* instance;

    Singleton() {}

    public:
    static Singleton* getInstance() {
        
        if(!instance) {
            std::lock_guard<std::mutex> lock(mutex1);
            if(!instance) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    void setData(int data) {
        std::lock_guard<std::mutex> lock(mutex2);
        this->data = data;
        std::cout << "Data : " << this->data << std::endl;
    }

    int getData() {
        return data;
    }
};

Singleton* Singleton::instance = nullptr;

void singletonExample(int num) {

    Singleton* s = Singleton::getInstance();
    s->setData(num);
}

int main() {

    std::thread t1(singletonExample, 123);
    std::thread t2(singletonExample, 234);
    t1.join();
    t2.join();

}


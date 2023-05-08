#include <iostream>
using namespace std;

//pure virtual func, virtual void sayHello() = 0;
//it will make the class as abstract -> can't create object for that.

class Base {
public:
    //virtual keyword, calls the derived class
    virtual void sayHello() {
        cout << "Hello from Base" << endl;
    }
};

class Derived : public Base {
public:
    void sayHello()  {
        cout << "Hello from Derived" << endl;
    }
};

int main() {
    Base *base;
    Derived derived;
    base = &derived;
    base->sayHello();   // Output: Hello from Derived
    return 0;
}





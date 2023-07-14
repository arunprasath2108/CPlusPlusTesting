#include <iostream>
using namespace std;

class Base1 {
    public:
        void print() {
            cout << "Base1" << endl;
        }
};

class Base2 {
    public:
        void print() {
            cout << "Base2" << endl;
        }
};

class Derived : public Base1, public Base2 {
    public:
        void display() {
            // print();
            //the above line will produce ambiguity issue, bcz it present in two base classes;

            // solution 1: rename the ambiguous function in Base1
            // solution 2: qualify the function call with the name of the base class
            Base1::print();
            Base2::print();
        }
};

int main() {
    Derived derived;
    derived.display();
    return 0;
}

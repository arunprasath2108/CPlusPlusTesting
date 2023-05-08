#include <iostream>
using namespace std;

class Animal {
    public :
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
    public :
    void bark() {
        cout << "Barking..." << endl;
    }
};


int main() {
    Dog dog;
    //using the parent class properties.
    dog.eat();
    //child class properties.
    dog.bark();
}
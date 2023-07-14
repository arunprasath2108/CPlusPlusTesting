#include <iostream>

class Animal {
    public:
        void eat() {
            std::cout << "Animal is eating.\n";
        }
};

class Mammal : public Animal {
    public:
        void giveBirth() {
            std::cout << "Mammal is giving birth.\n";
        }
};

class Bird {
    public:
        void fly() {
            std::cout << "Bird is flying.\n";
        }
};

class Bat : public Mammal, public Bird {
    public:
        void fly() {
            std::cout << "Bat is flying.\n";
        }
};

int main() {
    Bat bat;
    bat.eat();          // call Animal::eat() through Mammal
    bat.giveBirth();    // call Mammal::giveBirth()
    bat.fly();           // call Bat::fly() because it overrides Bird::fly()
    return 0;
}

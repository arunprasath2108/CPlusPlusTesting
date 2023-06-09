#include <iostream>

// save and restore the state of object
class Memento {

    std::string state;

    public:
    Memento(std::string state) {
        this->state = state; 
    }

    std::string getState() {
        return state;
    }
};

// creates the memento
// save the state of memento
class Originator {

    std::string state;

    public:
    void setState(std::string state) {
        this->state = state;
    }

    Memento createMemento() {
        return Memento(state);
    }

    void restoreMemento(Memento memento) {
        state = memento.getState();
    }

    void printState() {
        std::cout << "current State: " << state << std::endl;
    }
};

//store and retrieve memento
class Caretaker {

    std::vector<Memento> mementos;

    public:
    void addMemento(Memento memento) {
        mementos.push_back(memento);
    }

    Memento getMemento(int index) {
        if (index >= 0 && index < mementos.size()) {
            return mementos[index];
        }
        return Memento("");
    }
};

int main() {

    Originator originator;
    Caretaker caretaker;

    originator.setState("State 1");
    originator.printState();

    Memento memento1 = originator.createMemento();
    caretaker.addMemento(memento1);

    originator.setState("State 2");
    originator.printState();

    Memento memento2 = originator.createMemento();
    caretaker.addMemento(memento2);

    originator.restoreMemento(caretaker.getMemento(0));
    originator.printState();
}






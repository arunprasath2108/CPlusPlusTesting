#include <iostream>
#include <vector>

class ElementA;
class ElementB;

class Visitor {
    public:
        virtual void visit(ElementA* element) = 0;
        virtual void visit(ElementB* element) = 0;
};

class ConcreteVisitor : public Visitor {

    public:
    void visit(ElementA* element) {
        std::cout << "Visit Element A" << std::endl;
    }

    void visit(ElementB* element)  {
        std::cout << "Visit Element B" << std::endl;
    }
};

class Element {
    public:
    virtual void accept(Visitor* visitor) = 0;
};

class ElementA : public Element {

    public:
    void accept(Visitor* visitor) {
        visitor->visit(this);
    }

    void operationA() {
        std::cout << "Operation A of Element A" << std::endl;
    }
};

class ElementB : public Element {
    
    public:
    void accept(Visitor* visitor) {
        visitor->visit(this);
    }

    void operationB() {
        std::cout << "Operation B of Element B" << std::endl;
    }
};

int main() {

    ElementA elementA;
    ElementB elementB;
    ConcreteVisitor visitor;

    elementA.accept(&visitor);
    elementB.accept(&visitor);
}

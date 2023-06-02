#include <iostream>

class Pizza {

    public:
    virtual std::string getPizza() = 0;
    virtual int getPrice() = 0;
};

class ClassicPizza: public Pizza {

    public:
    std::string getPizza() {
        return "Classic Pizza";
    }

    int getPrice() {
        return 200;
    }
};

class PizzaDecorator : public Pizza {

    Pizza* pizza;

    public:
    PizzaDecorator() {}
    PizzaDecorator(Pizza* pizza) {
        this->pizza = pizza;
    }

    std::string getPizza() {
        return pizza->getPizza();
    }

    int getPrice() {
        return pizza->getPrice();
    }
};

class ExtraCheeseDecorator : public PizzaDecorator {
    
    Pizza* pizza;

    public:
    ExtraCheeseDecorator(Pizza* pizza) {
        this->pizza = pizza;
    }

    std::string getPizza() {
        return pizza->getPizza() + "with Extra Cheese";
    }

    int getPrice() {
        return pizza->getPrice() + 20;
    }
};

int main() {

    // classic Pizza
    Pizza* classic = new ClassicPizza();
    std::cout << "Pizza: " << classic->getPizza() << std::endl;
    std::cout << "Price: " << classic->getPrice() << std::endl;

    // Decorating classic Pizza with Extra Cheese
    Pizza* classicWithExtraCheese = new ExtraCheeseDecorator(classic);
    std::cout << "Pizza: " << classicWithExtraCheese->getPizza() << std::endl;
    std::cout << "Price: " << classicWithExtraCheese->getPrice() << std::endl;

    return 0;
}

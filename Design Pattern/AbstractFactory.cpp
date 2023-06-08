#include <iostream>

class Product {
    public:
        virtual void buy() = 0;
};

class Laptop : public Product {
    public:
    void buy() {
        std::cout << "buying Laptop" << std::endl;
    }
};

class Mobile : public Product {
    public:
    void buy() {
        std::cout << "buying Mobile" << std::endl;
    }
};

class Factory {
    public:
    virtual Product* createProduct() = 0;
};

class LaptopFactory : public Factory {

    public:
    Product* createProduct() {
        return new Laptop();
    }
};

class MobileFactory : public Factory {

    public:
    Product* createProduct() {
        return new Mobile();
    }
};

int main() {

    Factory* laptopFactory = new LaptopFactory();
    Product* laptop = laptopFactory->createProduct();
    laptop->buy();

    Factory* mobileFactory = new MobileFactory();
    Product* mobile = mobileFactory->createProduct();
    mobile->buy();
}

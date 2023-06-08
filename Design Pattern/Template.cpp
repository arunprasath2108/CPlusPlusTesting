#include <iostream>

class CarTemplate {

    void setChasis() {
        std::cout << "Chasis is ready for Car.." << std::endl;
    }

    void setEngine() {
        std::cout << "Engine fitted perfectly!" << std::endl;
    }

    public:
    //template method 
    void makeCar() {
        setChasis();
        setWheels();
        setEngine();
        setBody();
        setInterior();
    }

    virtual void setWheels() = 0;
    virtual void setBody() = 0;
    virtual void setInterior() = 0;
};

class BasicCar : public CarTemplate {

    public:
    void setWheels() {
        std::cout << "Basic wheels are fixed!" << std::endl;
    }

    void setBody() {
        std::cout << "Car with a basic design!" << std::endl;
    }

    void setInterior() {
        std::cout << "it's a Four seater car!" << std::endl;
    }
};

class SportsCar : public CarTemplate {

    public:
    void setWheels() {
        std::cout << "Sport wheels are fixed!" << std::endl;
    }

    void setBody() {
        std::cout << "Car with a sportive design!" << std::endl;
    }

    void setInterior() {
        std::cout << "it is designed for Sporting!" << std::endl;
    }
};

int main() {
    
    CarTemplate* basicCar = new BasicCar();
    basicCar->makeCar();

    CarTemplate* sportCar = new SportsCar();
    sportCar->makeCar();
}
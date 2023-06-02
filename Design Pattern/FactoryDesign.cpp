#include <iostream>

class Transport {

    public:
    virtual void delivery() = 0;
}; 

class RoadTransport: public Transport {

    public:
    void delivery() {
        std::cout << "delivering via Roadways.." << std::endl;
    }
};

class SeaTransport: public Transport {

    public:
    void delivery() {
        std::cout << "delivering via Sea ways.." << std::endl;
    }
};

class AirTransport: public Transport {

    public:
    void delivery() {
        std::cout << "delivering via Airways.." << std::endl;
    }
};

//factory class
class TransportOrganizer {

    public:
    Transport* getTransport(int parcel_kg) {

        if(parcel_kg < 100) {
            return new RoadTransport();
        } 
        else if(parcel_kg > 100 && parcel_kg < 1000) {
            return new AirTransport();
        }
        else if(parcel_kg >=1000) {
            return new SeaTransport();
        }
        else {
            return nullptr;
        }
    }
};



int main() {

    //transportation boxes in kg.
    int product1 = 70;
    int product2 = 500;
    int product3 = 3000;

    TransportOrganizer transport_company;
    Transport* transport1 = transport_company.getTransport(product1);
    Transport* transport2 = transport_company.getTransport(product2);
    Transport* transport3 = transport_company.getTransport(product3);

    transport1->delivery();
    transport2->delivery();
    transport3->delivery();
}
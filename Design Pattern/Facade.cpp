#include<iostream>

class Booking {

    public:
    void checkAvailability() {
        std::cout << "Cab is Available to pickup." << std::endl;
    }
    void getPickUpLocation() {
        std::cout << "pickup location." << std::endl;
    }
    void getDropLocation() {
        std::cout << "Drop location." << std::endl;
    }
    void getTripFare() {
        std::cout << "Calculating Trip fare." << std::endl;
    }
    void bookCab() {
        std::cout << "Booked!" << std::endl;
    }
    void sendConfirmation() {
        std::cout << "Your booking is confirmed." << std::endl;
    }
};

//facade
class CabService {

    Booking book;

    public:
    void bookCab() {
        book.getPickUpLocation();
        book.getDropLocation();
        book.checkAvailability();
        book.getTripFare();
        book.bookCab();
        book.sendConfirmation();
    }

    void enquiry() {
        book.getPickUpLocation();
        book.getDropLocation();
        book.getTripFare();
    }
};

int main() {

    CabService cab;
    cab.enquiry();
    cab.bookCab();
}

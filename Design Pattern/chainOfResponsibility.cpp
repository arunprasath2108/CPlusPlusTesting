#include<iostream>
using namespace std;

class Order {

    public:
    std::string customer_name;
    std::string product;
    int pincode;
    int payment;

    Order(string customer_name, string product, int pincode, int payment) {
        this->customer_name = customer_name;
        this->product = product;
        this->pincode = pincode;
        this->payment = payment;
    }
};

//abstract class
class Handler {

    public:
    virtual void setNextHandler(Handler* handler) = 0;
    virtual void processOrder(Order* order) = 0;
};

class AvailabilityHandler : public Handler {

    Handler* nextHandler = nullptr;

    public:
    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

    void processOrder(Order* order) {
        if(order->product.empty()) {
            cout << " Order is empty." << endl;
            return;
        }

        if(nextHandler != nullptr) {
            nextHandler->processOrder(order);
        }
    }
};

class AddressHandler : public Handler {

    Handler* nextHandler = nullptr;

    public:
    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

    void processOrder(Order* order) {
        if(order->pincode == 0) {
            cout << " Product is not delivered to this location." << endl;
            return;
        }

        if(nextHandler != nullptr) {
            nextHandler->processOrder(order);
        }
    }
};

class PaymentHandler : public Handler {

    Handler* nextHandler = nullptr;

    public:
    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

    void processOrder(Order* order) {
        if(order->payment <= 0) {
            cout << " Payment failed." << endl;
            return;
        }

        if(nextHandler != nullptr) {
            nextHandler->processOrder(order);
        }
    }
};

class PlaceOrderHandler : public Handler {

    Handler* nextHandler = nullptr;

    public:
    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

    void processOrder(Order* order) {
        if(order->customer_name.empty()) {
            cout << "Please provide a valid information." << endl;
            return;
        }

        cout << "Delivery details : " << endl;
        cout << "customer name : " << order->customer_name << endl;
        cout << "Product : " << order->product << endl;
        cout << "Address : " << order->pincode << endl;
    }

};

int main() {
                //name, product, pincode, payment
    Order order("arun", "mobile", 633123, 10000);

    Handler* availabilityHandler = new AvailabilityHandler();
    Handler* addressHandler = new AddressHandler();
    Handler* paymentHandler = new PaymentHandler();
    Handler* placeOrder = new PlaceOrderHandler();

    availabilityHandler->setNextHandler(addressHandler);
    addressHandler->setNextHandler(paymentHandler);
    paymentHandler->setNextHandler(placeOrder);

    availabilityHandler->processOrder(&order);

}
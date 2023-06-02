#include <iostream>
using namespace std;

class PaymentStrategy {

    public:
    virtual void pay(int) = 0;
};

class DebitCardPayment: public PaymentStrategy {

    string name;
	string cardNumber;
	string cvv;
	string dateOfExpiry;

    public:
    DebitCardPayment(string name, string cNum, string cvv, string expiryDate){
		this->name = name;
		this->cardNumber = cNum;
		this->cvv = cvv;
		this->dateOfExpiry = expiryDate;
	}

    void pay(int amount) {
        cout << "Payment successful through Debit card of Rs." << amount << endl;
    }
};

class CreditCardPayment: public PaymentStrategy {

    string name;
	string cardNumber;
	string cvv;
	string dateOfExpiry;

    public:
    CreditCardPayment(string name, string cNum, string cvv, string expiryDate){
		this->name = name;
		this->cardNumber = cNum;
		this->cvv = cvv;
		this->dateOfExpiry = expiryDate;
	}

    public:
    void pay(int amount) {
        cout << "Payment successful through Credit card of Rs." << amount << endl;
    }

};

class COD: public PaymentStrategy {

    string name;
	string address;

    public:
    COD(string name, string address){
		this->name = name;
		this->address = address;
	}

    public:
    void pay(int amount) {
        cout << "Payment will be colected through offline mode of Rs." << amount << endl;
    }
};

class Product {

    public:
    string item;
    int price;

    Product(string item, int price) {
        this->item = item;
        this->price = price;
    }
};

class ShoppingCart {

    vector<Product> listOfProducts;
    int billTotal = 0;

    public:
    void addProductInCart(Product product) {
        listOfProducts.push_back(product);
    }

    void processPayment(PaymentStrategy* paymentMode) {
        paymentMode->pay(billTotal);
    }

    void generateBill() {
        cout << "Bill details: " << endl;

        for(int i=0; i<listOfProducts.size(); i++) {
            cout << "product: " << listOfProducts[i].item << " - ";
            cout << "price: " << listOfProducts[i].price << endl;
            billTotal +=listOfProducts[i].price;
        }
        cout << "Total  =  " << billTotal << endl;
    }
};

int main() {

    Product product1("mobile", 19999);
    Product product2("watch", 3500);
    Product product3("bag", 1250);

    ShoppingCart shoppingCart;
    shoppingCart.addProductInCart(product1);
    shoppingCart.addProductInCart(product2);
    shoppingCart.addProductInCart(product3);
    shoppingCart.generateBill();
    shoppingCart.processPayment(new DebitCardPayment("abc", "1232", "345", "12/2/26"));
}
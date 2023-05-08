#include <iostream>
using namespace std;

class Number {
    public:
    int num1;
    int num2;

    Number() {
        num1 = 0;
        num2 = 0;
    }
    Number(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }

    void print() {
        cout << "Number1 : " << num1 << " Number2 : " << num2 << endl;
    }

    // Overload the + operator by the overloading method
    Number operator + (Number number) {
        Number temp;
        temp.num1 = num1 + number.num1;
        temp.num2 = num2 + number.num2;
        return temp;
    }

};

int main() {
    Number n1(1,2);
    Number n2(3,4);
    Number n3;
    //here, we can't use + for Object(User-defined data types)
    // n3 = n1+n2;
    //to overload an operator, write a operator overloading method..
    n3 = n1 + n2;
    // cout << n3.num1 << n3.num2 << endl;
    n3.print();

}
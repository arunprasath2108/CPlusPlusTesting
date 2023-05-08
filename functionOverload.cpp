#include <iostream>    
using namespace std;   

class Cal {    

    public:    
    //function with same name, and differnt parameters..
    //function and constructors can be overloaded..
    int add(int a,int b) {      
        return a + b;      
    }      
    int add(int a, int b, int c) {      
        return a + b + c;      
    }      
    //can have different types of parameters
    double add(int a, float b, double c) {
        return a + b + c;
    }
};     

int main() {    
    Cal C;                                                    //     class object declaration.   
    cout << C.add(10, 20) <<endl;      
    cout << C.add(12, 20, 23) <<endl;   
    cout  << C.add(1,1.2,1.3);
    
}    
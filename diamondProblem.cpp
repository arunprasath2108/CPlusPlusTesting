#include <iostream>
using namespace std;

//if the same base class A is inherited by two classes B, C
//class D inherits both B, C
//each class B, C has the copy of base class A
//copy of instance is shared between these classes (diamond problem occurs)

class A { 
    public:
    A() {
        cout << "constructor invoked in A" << endl;
    }
  void print() {
      cout << "in A" << endl;
  }    
};  

//by using virtual keyword, we can reduce the redundancy code of the base class
class B: virtual public A {
    public:
    B() {
        cout << "constructor invoked in B" << endl;
    }
    void print() {
        cout << "in B" << endl;
    }
};

class C : virtual public A {
    public:
    C() {
        cout << "constructor invoked in C" << endl;
    }
      void print() {
        cout << "in C" << endl;
    }
};

class D : public B, public C {
    public:
    D() {
        cout << "constructor invoked in D" << endl;
    }
      void print() {
        cout << "in D" << endl;
    }
};

int main() {
        //output :  -> if virtual inheritance is not used
        // constructor invoked in A
        // constructor invoked in B
        // constructor invoked in A     //called for second time, wasting memory
        // constructor invoked in C
        // constructor invoked in D
    D object;
}
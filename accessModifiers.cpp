#include <iostream>
using namespace std;

class Base {
    
    public :
    int publicVar = 1;
    private :
    int privateVar = 2;
    protected :
    int protectedVar = 3;

    public :
    int getPrivateVar() {
        return privateVar;
    }
    
};

class DerivedPublicClass : public Base {
    //public :
    //we can access the public variable.

    //private :
    // can't directly access the private
    //access the private member through getters from base class;

    //protected :
    //access the protected members through this:
    //we can't directly access the protected member
    public :
    int getProtectedVar() {
        return protectedVar;
    }
    
};

class DerivedPrivateClass : private Base {
    //public, protected, getPrivate become private here.
    //can't access private here.

    public :
    int getProtectedVar() {
        return protectedVar;
    }

    int getPublicVar() {
        return publicVar;
    }

    // int getPrivateVar() {
    //     return Base::getPrivateVar();
    // }
    
};

class DerivedProtectedClass : protected Base {
    // public and protected members become protected here.
    // can't access private, bcz private members are only accessible within the class
    public :
    int getProtectedVar() {
        return protectedVar;
    }

    int getPublicVar() {
        return publicVar;
    }

    // int getPrivateVar() {
    //     return Base :: getPrivateVar();
    // }
};



int main() {

    DerivedPublicClass derivedPublic;
    DerivedPrivateClass derivedPrivate;
    DerivedProtectedClass derivedProtected;

    //derived as public class:
    cout << derivedPublic.publicVar << endl;
    cout << derivedPublic.getPrivateVar() << endl;
    cout << derivedPublic.getProtectedVar() << endl;

    //derived as private class :
    cout << "private members : " << endl;
    cout << derivedPrivate.getPublicVar() << endl;
    // cout << derivedPrivate.getPrivateVar() << endl;
    cout << derivedPrivate.getProtectedVar() << endl;

    //derived as protected class :
    cout << "protected members : " << endl;
    cout << derivedProtected.getPublicVar() << endl;
    // cout << derivedProtected.getPrivateVar() << endl;
    cout << derivedProtected.getProtectedVar() << endl;
}
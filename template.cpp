#include<iostream>
using namespace std;

//declare the syntax for template (generic function)
template <typename T> 
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

//template class declaration
template <class T1, class T2> 
class TemplateClass {
    public:
    T1 number1;
    T2 number2;
    
    TemplateClass(T1 a, T2 b) {
        number1 = a;
        number2 = b;
        cout << "template class constructor invoked" << endl;
    }
};

int main() {
    //calling template function
    cout << maxValue(1,2) << endl;
    cout << maxValue('a', 'f') << endl;

    //template class example
    TemplateClass<int, float> templateObject(10, 1.5);
}
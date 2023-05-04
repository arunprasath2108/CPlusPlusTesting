#include <iostream>

int main() {

    //it's a variable
    int number = 10;  

    //declaring a empty pointer variable
    int *pointVar;

    //it is pointer storing the address of a variable - number;  & -> address operator
    int *ptr;
    ptr = &number;  

    // *ptr -> gives the value of variable
    //  ptr -> gives the memory address
    std::cout << "value ->  " << *ptr <<  "   address ->   " << ptr << std::endl;

    //changing the value using pointer
    *ptr = 11;
    std::cout << "value ->  " << *ptr <<  "   address ->   " << ptr << std::endl;

    int arr[5];
    int* arrPtr = arr;  //it will refer the first element memory address;
}

//    g++ pointerTest.cpp
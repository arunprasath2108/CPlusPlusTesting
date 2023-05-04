#include <iostream>

int main() {

    //declaring array with fixed size
    int arr[10];  
    //declares the values withouty specifying the size
    int arr2[] = {1,2,3,4,5};    
    int size = 5;
    int valuesArr[size];

    //getting the values using index
    for(int i=0;i<size;i++) {
        std::cin >> valuesArr[i];    
    }
    std::cout << "Printing the values of Array" << std::endl;
    for(int i=0;i<size;i++) {
        std::cout << valuesArr[i] << std::endl;
    }

    int twoDimArray[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    //printing the values of two dimesnional array
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            std::cout << twoDimArray[i][j] << " ";
        }
        std::cout << "\n";
    }

}

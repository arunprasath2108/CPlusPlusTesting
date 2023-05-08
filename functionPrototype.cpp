#include <iostream>  
using namespace std;  


int add(int = 5, int = 5);   //need to declare if the function definition comes after the main() call;

int main() {  
   // int number;
   // number = new int;
   // cin >> *number;

   // cout << sizeof(number) << endl;
   // delete number;
   // cout << sizeof(number) << endl;
   // int age;
   cout << add() << endl;

   // cout << "Enter a value" << endl;    //Output displayed on Console using cout
   // cin >> age;   //getting input from user with cin
   // cout << number << "AGE : " << age << endl;
   return 0;  
}  

int add(int num1, int num2) {
   return num1+num2;
}

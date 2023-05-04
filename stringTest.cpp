// g++ stringTest.cpp
#include <iostream>
#include <string>
using namespace std;

int main() {

    string emptyStr;
    string str;
    string str1 = "hello";
    string str2("how are you?");
    cout << str2.size() << endl;
    // cout << str1.compare(str2) << endl;
    // cin >> emptyStr;        //while getting input from cin only, before the whitespace chars. are taken as input;
    cin.get()
    getline(cin, emptyStr);
    cout << emptyStr << endl;

}
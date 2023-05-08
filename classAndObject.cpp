#include <iostream>

using namespace std;

class Student {

    //data members
    public :
    int id;
    string name;
    string favSubject;
    
    //member function
    void printStudentData() {
        cout << "Student ID     : " << id << endl;
        cout << "Student Name   : " << name << endl;
        cout << "Fav. Subject   : " << favSubject << endl;
        cout << "Marks          : " << marks << endl;
    }
    
    private :
    int marks;

    public :
    Student() {
        //default constructor
        cout << "Default constructor is called when an instance is created." << endl;
    }
    Student(int id, string name, string favSubject, int marks) {
        //parameterized constructor
        this->id = id;
        this->name = name;
        this->favSubject = favSubject;
        this->marks = marks;
    }
    ~ Student() { 
        //destructor -> deallocates the memory allocated by the constructor.
        cout << "destructor called" << endl;
    }

    public :
    void setMarks(int mark) {
        marks = mark;
    }
};

int main() {

    //craetes instance
    Student student; 
    cout << student.name << endl;
    //accessing the data members through (.) opeartor
    student.id = 1;
    student.name = "Arun";
    student.favSubject = "Science";
    student.setMarks(88);

    //calling the class member function by using object
    student.printStudentData();    
}
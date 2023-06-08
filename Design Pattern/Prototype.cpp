#include <iostream>
#include <vector>
using namespace std;

class Employee {

    vector<string> empList;

    public:
    Employee() {}
    Employee(std::vector<std::string> list) {
        empList = list;
    }

    void addEmployee() {
        empList.push_back("aravind");
        empList.push_back("Raj");
        empList.push_back("sanjay");
        empList.push_back("harish");
    }

    vector<string> getEmployeeList() {
        return empList;
    }

    Employee clone() {
        return Employee(empList);
    }
};

int main() {

    Employee employees;
    employees.addEmployee();

    Employee clonedEmployees = employees.clone();

    vector<string> list1 = clonedEmployees.getEmployeeList();
    list1.pop_back();

    for (string employee : employees.getEmployeeList()) {
        std::cout << employee << " ";
    }
    std::cout << std::endl;

    std::cout << "Cloned employees: \n";
    for (string employee : list1) {
        std::cout << employee << " ";
    }
    std::cout << std::endl;
}


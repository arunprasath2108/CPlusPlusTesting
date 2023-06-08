#include <iostream>
#include <vector>

class CreditMoney {

    public:
    std::string name;
    std::string accountNumber;
    std::string amount_to_credit;

    CreditMoney(std::string name, std::string accountNumber,std::string amount_to_credit) {
        this->name = name;
        this->accountNumber = accountNumber;
        this->amount_to_credit = amount_to_credit;
    }
};

//existing class
class Bank {

    public:
    void processSalary(std::vector<CreditMoney*> accounts) {

        for(int i=0; i<accounts.size(); i++) {
            std::cout << "Dear " << accounts[i]->name << ", Rs." <<accounts[i]->amount_to_credit << " credited to your Ac." << accounts[i]->accountNumber << std::endl;
        }
    }
};

class Employee {

    public:
    int id;
    std::string name;
    std::string role;
    std::string accountNumber;
    std::string salary;

    Employee(int id, std::string name, std::string role, std::string accountNumber, std::string salary) {
        this->id = id;
        this->name = name;
        this->role = role;
        this->accountNumber = accountNumber;
        this->salary = salary;
    }

    std::string getSalary() {
        return salary;
    }

    void setSalary(double salary) {
        this->salary = salary;
    }
};

//adapter for calculating employee salary
class SalaryAdapter {

    Bank bank;
    std::vector<CreditMoney*> accounts;
    
    public:
    void processSalary(std::vector<Employee*> employees) {

        for(int i=0; i< employees.size(); i++) {
            CreditMoney* credit = new CreditMoney(employees[i]->name,
                                                  employees[i]->accountNumber,
                                                  employees[i]->salary);
            accounts.push_back(credit);
        }
        bank.processSalary(accounts);
    }
};

class Company {

    SalaryAdapter processSalary;
    
    public:
    std::vector <Employee*> employeeList;

    void addEmployee(Employee* emp) {
        employeeList.push_back(emp);
    }

    void depositSalary() {
        processSalary.processSalary(employeeList);
    }
};

int main() {
    
    Company company;
    Employee* e1 = new Employee(1,"harish", "mts", "3434567887", "35024.00");
    Employee* e2 = new Employee(1,"mahesh", "mts", "345678987654", "42345.00");
    Employee* e3 = new Employee(1,"aravind", "mts", "234567898722", "23459.00");
    company.addEmployee(e1);
    company.addEmployee(e2);
    company.addEmployee(e3);
    company.depositSalary();

}
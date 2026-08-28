//============================================================================
// Name        : HRPayrollEngine.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Employee {

private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:

    // Constructor
    Employee() {
        empId = 0;
        name = "";
        department = "";
        grade = 'D';
        basicSalary = 0.0;
        isActive = true;

        employeeCount++;
    }

    // Destructor
    ~Employee() {
        employeeCount--;
    }

    // Setters
    void setEmpId(int id) {
        if (id > 0) {
            empId = id;
        } else {
            cout << "Invalid Employee ID!" << endl;
        }
    }

    void setName(const string& n) {
        if (!n.empty()) {
            this->name = n;
        } else {
            cout << "Invalid Name!" << endl;
        }
    }

    void setDepartment(const string& dept) {
        if (!dept.empty()) {
            this->department = dept;
        } else {
            cout << "Invalid Department!" << endl;
        }
    }

    void setGrade(char g) {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D') {
            this->grade = g;
        } else {
            cout << "Invalid Grade! Using D." << endl;
            this->grade = 'D';
        }
    }

    void setBasicSalary(double salary) {
        if (salary >= 0) {
            this->basicSalary = salary;
        } else {
            cout << "Invalid Salary!" << endl;
        }
    }

    // Deactivate employee
    void deactivate() {
        isActive = false;
    }

    // Getters
    int getEmpId() const {
        return empId;
    }

    string getName() const {
        return name;
    }

    string getDepartment() const {
        return department;
    }

    char getGrade() const {
        return grade;
    }

    double getBasicSalary() const {
        return basicSalary;
    }

    bool getIsActive() const {
        return isActive;
    }

    // Calculate allowances
    double computeAllowances() const {

        switch (grade) {

        case 'A':
            return basicSalary * 0.40;

        case 'B':
            return basicSalary * 0.30;

        case 'C':
            return basicSalary * 0.20;

        case 'D':
            return basicSalary * 0.10;

        default:
            return 0.0;
        }
    }

    // Calculate gross salary
    double computeGrossSalary() const {

        return basicSalary + computeAllowances();
    }

    // Calculate tax
    double computeTax() const {

        double gross = computeGrossSalary();

        if (gross <= 50000) {

            return 0.0;

        } else if (gross <= 100000) {

            return (gross - 50000) * 0.10;

        } else {

            return 5000 + (gross - 100000) * 0.20;
        }
    }

    // Calculate net salary
    double computeNetSalary() const {

        return computeGrossSalary() - computeTax();
    }

    // Print payslip
    void printPayslip() const {

        cout << "\n====================================" << endl;
        cout << "           EMPLOYEE PAYSLIP         " << endl;
        cout << "====================================" << endl;

        cout << "Employee ID     : " << empId << endl;
        cout << "Name            : " << name << endl;
        cout << "Department      : " << department << endl;
        cout << "Grade           : " << grade << endl;
        cout << "Basic Salary    : " << basicSalary << endl;
        cout << "Allowances      : " << computeAllowances() << endl;
        cout << "Gross Salary    : " << computeGrossSalary() << endl;
        cout << "Tax             : " << computeTax() << endl;
        cout << "Net Salary      : " << computeNetSalary() << endl;
        cout << "Status          : "
             << (isActive ? "Active" : "Inactive") << endl;

        cout << "====================================" << endl;
    }

    // Static function
    static int getEmployeeCount() {

        return employeeCount;
    }

    // Accept employee details
    void acceptDetails() {

        int id;
        string n;
        string dept;
        char g;
        double salary;

        cout << "\nEnter Employee ID: ";
        cin >> id;
        setEmpId(id);

        cout << "Enter Name: ";
        cin >> n;
        setName(n);

        cout << "Enter Department: ";
        cin >> dept;
        setDepartment(dept);

        cout << "Enter Grade (A/B/C/D): ";
        cin >> g;
        setGrade(g);

        cout << "Enter Basic Salary: ";
        cin >> salary;
        setBasicSalary(salary);
    }
};

// Static member definition
int Employee::employeeCount = 0;


int main() {

    // One object on stack
    Employee e1;

    // Two objects on heap
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    // Accept details
    cout << "\nEnter details for Employee 1";
    e1.acceptDetails();

    cout << "\nEnter details for Employee 2";
    e2->acceptDetails();

    cout << "\nEnter details for Employee 3";
    e3->acceptDetails();

    // These will give compiler errors because members are private.
    // e1.empId = 999;
    // e1.basicSalary = -1000;

    // Print payslips
    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    // Simulate resignation
    e3->deactivate();

    if (!e3->getIsActive()) {

        cout << "\n"
             << e3->getName()
             << " is no longer active. Payroll skipped."
             << endl;
    }

    // Employee count
    cout << "\nTotal Employees : "
         << Employee::getEmployeeCount()
         << endl;

    // Free heap memory
    delete e2;
    delete e3;

    cout << "Employees after delete : "
         << Employee::getEmployeeCount()
         << endl;

    return 0;
}

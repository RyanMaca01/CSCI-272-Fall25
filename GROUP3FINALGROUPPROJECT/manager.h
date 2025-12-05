//Ryans Code 
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "employee.h"
using namespace std;

class Manager {
private:
    string name;
    int idNumber;
    string department;
    string position;
    double salary;
    double raise;
    vector<Employee> employees;

public:
    // Constructor
    Manager(string n, int id, string dept, string pos, double sal, double r)
        : name(n), idNumber(id), department(dept), position(pos), salary(sal), raise(r) {}

    // Getters
    string getName() const { return name; }
    int getIdNumber() const { return idNumber; }
    string getDepartment() const { return department; }
    string getPosition() const { return position; }
    double getSalary() const { return salary; }
    double getRaise() const { return raise; }

    // Setters
    void setName(const string& n) { name = n; }
    void setIdNumber(int id) { idNumber = id; }
    void setDepartment(const string& dept) { department = dept; }
    void setPosition(const string& pos) { position = pos; }
    void setSalary(double sal) { salary = sal; }
    void setRaise(double r) { raise = r; }

    // Employee management
    void addEmployee(const Employee& emp) {
        employees.push_back(emp);
    }

    bool removeEmployee(int empId) {
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getIdNumber() == empId) {
                employees.erase(employees.begin() + i);
                return true;
            }
        }
        return false;
    }

    Employee* findEmployee(int empId) {
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getIdNumber() == empId) {
                return &employees[i];
            }
        }
        return nullptr;
    }

    // Payroll / reporting
    void printPayroll() const {
        if (employees.empty()) {
            cout << "No employees to display." << endl;
            return;
        }

        cout << "\n========================================" << endl;
        cout << "          PAYROLL REPORT" << endl;
        cout << "    Department: " << department << endl;
        cout << "========================================" << endl;
        cout << left << setw(6) << "ID" 
             << setw(12) << "Name" 
             << setw(10) << "Salary" 
             << setw(10) << "Hours" 
             << setw(10) << "Total Pay" << endl;
        cout << "----------------------------------------" << endl;

        double totalPayroll = 0.0;

        for (const Employee& emp : employees) {
            cout << left << setw(6) << emp.getIdNumber()
                 << setw(12) << emp.getName()
                 << "$" << setw(9) << fixed << setprecision(2) << emp.getSalary()
                 << setw(10) << emp.getHoursWorked()
                 << "$" << setw(9) << emp.calculatePay() << endl;

            totalPayroll += emp.calculatePay();
        }

        cout << "========================================" << endl;
        cout << "Total Payroll: $" << fixed << setprecision(2) << totalPayroll << endl;
        cout << "========================================\n" << endl;
    }
};

#endif
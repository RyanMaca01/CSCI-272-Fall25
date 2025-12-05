// Part Time Employee header
// Inherits from Employee
#ifndef PARTIME_H
#define PARTIME_H

#include "employee.h"
#include <string>
using namespace std;

class PartTimeEmployee : public Employee {
private:
    int maxHours; // Max hours per week for part time

public:
    // Constructor
    PartTimeEmployee(string n, int id, string dept, string pos, double sal, double hours)
        : Employee(n, id, dept, pos, sal, hours) {
        maxHours = 30; // Part time limit
    }

    // Override calculatePay - just hourly rate times hours
    double calculatePay() const override {
        return getSalary() * getHoursWorked();
    }

    // Override status message
    string statusMessage() const override {
        if (getHoursWorked() > maxHours) {
            return "Warning: Exceeding part-time hours!";
        }
        if (getHoursWorked() < 15) {
            return "Warning: Low hours for part-time!";
        }
        return "Part-time hours are good.";
    }

    // Get max hours
    int getMaxHours() const {
        return maxHours;
    }
};

#endif
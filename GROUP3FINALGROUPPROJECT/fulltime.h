// Full Time Employee header
// Inherits from Employee
#ifndef FULLTIME_H
#define FULLTIME_H

#include "employee.h"
#include <string>
using namespace std;

class FullTimeEmployee : public Employee {
private:
    double overtimeRate; // 1.5x for overtime

public:
    // Constructor
    FullTimeEmployee(string n, int id, string dept, string pos, double sal, double hours)
        : Employee(n, id, dept, pos, sal, hours) {
        overtimeRate = 1.5;
    }

    // Override calculatePay - includes overtime after 40 hours
    double calculatePay() const override {
        double hours = getHoursWorked();
        double rate = getSalary();

        if (hours <= 40) {
            // Regular pay
            return rate * hours;
        } else {
            // Regular pay + overtime
            double regularPay = rate * 40;
            double overtimeHours = hours - 40;
            double overtimePay = rate * overtimeRate * overtimeHours;
            return regularPay + overtimePay;
        }
    }

    // Override status message
    string statusMessage() const override {
        double hours = getHoursWorked();

        if (hours > 60) {
            return "Warning: Overworked! Take a break.";
        }
        if (hours >= 40) {
            return "Full-time hours complete. Overtime applied!";
        }
        if (hours < 40) {
            return "Warning: Below full-time hours!";
        }
        return "Full-time status good.";
    }

    // Get overtime rate
    double getOvertimeRate() const {
        return overtimeRate;
    }
};

#endif
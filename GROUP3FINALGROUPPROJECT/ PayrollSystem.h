#ifndef PAYROLLSYSTEM_H
#define PAYROLLSYSTEM_H

#include <string>
#include <vector>
#include "manager.h"

using namespace std;

class PayrollSystem {
private:
    vector<Employee> allEmployees;
    vector<Manager> allManagers;
    string databaseFile;

public:
    // Constructor
    PayrollSystem(const string& dbFile = "database.txt");

    // Database operations
    bool loadDatabase();
    bool saveDatabase();

    // User authentication
    Employee* loginAsEmployee(int empId);
    Manager* loginAsManager(int managerId);

    // Main menu system
    void run();

    // Portal launchers
    void employeePortal(Employee* emp);
    void managerPortal(Manager* mgr);

    // Utility functions
    void displayWelcome();
    int getValidInt(const string& prompt);
    double getValidDouble(const string& prompt);
};

#endif
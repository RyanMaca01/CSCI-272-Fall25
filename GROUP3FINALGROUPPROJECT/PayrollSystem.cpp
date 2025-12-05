//J Julian 
// PayrollSystem Implementation
// Unified system that integrates Employee and Manager portals

#include "PayrollSystem.h"
#include "Partime.h"
#include "fulltime.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include <iomanip>

using namespace std;

// Constructor
PayrollSystem::PayrollSystem(const string& dbFile) : databaseFile(dbFile) {}

// Load all employees from database file
bool PayrollSystem::loadDatabase() {
    try {
        ifstream inFile(databaseFile);

        if (!inFile) {
            throw runtime_error("Could not open " + databaseFile);
        }

        // Database format: id name salary type
        // Example: 0 Noeleen 55.50 F
        int tempId;
        string tempName, tempType;
        double tempSalary;

        // Read all employees from file
        while (inFile >> tempId >> tempName >> tempSalary >> tempType) {
            // Create appropriate employee type based on F or P
            if (tempType == "F") {
                // Full-time employee
                FullTimeEmployee emp(tempName, tempId, "Sales", "Employee", tempSalary, 0);
                // Store as base Employee (object slicing happens but works for this system)
                Employee baseEmp(tempName, tempId, "Sales", "Employee", tempSalary, 0);
                allEmployees.push_back(baseEmp);
            } else {
                // Part-time employee
                PartTimeEmployee emp(tempName, tempId, "Sales", "Employee", tempSalary, 0);
                Employee baseEmp(tempName, tempId, "Sales", "Employee", tempSalary, 0);
                allEmployees.push_back(baseEmp);
            }
        }

        inFile.close();

        if (allEmployees.empty()) {
            throw runtime_error("No employees found in database");
        }

        cout << "\nDatabase loaded successfully! " << allEmployees.size() << " employees found." << endl;
        return true;

    } catch (const runtime_error& e) {
        cout << "\nError: " << e.what() << endl;
        cout << "Make sure the database file is in the same folder!" << endl;
        return false;
    } catch (...) {
        cout << "\nUnexpected error loading database." << endl;
        return false;
    }
}

// Save all employees back to database file
bool PayrollSystem::saveDatabase() {
    try {
        ofstream outFile(databaseFile);

        if (!outFile) {
            throw runtime_error("Could not save to " + databaseFile);
        }

        // Write each employee to file in simple format
        // Format: id name salary type
        for (const Employee& emp : allEmployees) {
            outFile << emp.getIdNumber() << " "
                    << emp.getName() << " "
                    << emp.getSalary() << " "
                    << "F" << endl; // Default to F for now
        }

        outFile.close();
        cout << "\nDatabase saved successfully!" << endl;
        return true;

    } catch (const runtime_error& e) {
        cout << "\nError: " << e.what() << endl;
        return false;
    }
}

// Find and return pointer to employee by ID
Employee* PayrollSystem::loginAsEmployee(int empId) {
    for (Employee& emp : allEmployees) {
        if (emp.getIdNumber() == empId) {
            return &emp;
        }
    }
    return nullptr;
}

// Create and return pointer to manager by ID (managers authenticate as employees first)
Manager* PayrollSystem::loginAsManager(int managerId) {
    // First check if this ID exists in employee database
    Employee* emp = loginAsEmployee(managerId);

    if (emp == nullptr) {
        return nullptr;
    }

    // Check if this employee is a manager
    if (emp->getPosition() != "Manager" && emp->getPosition() != "manager") {
        cout << "\nAccess denied: This ID is not registered as a Manager." << endl;
        return nullptr;
    }

    // Create a Manager object from the employee data
    Manager* mgr = new Manager(
        emp->getName(),
        emp->getIdNumber(),
        emp->getDepartment(),
        emp->getPosition(),
        emp->getSalary(),
        emp->getSalary() * 0.1  // Default raise is 10% of salary
    );

    // Add all employees from the same department to this manager
    for (Employee& e : allEmployees) {
        if (e.getDepartment() == mgr->getDepartment()) {
            mgr->addEmployee(e);
        }
    }

    allManagers.push_back(*mgr);
    return mgr;
}

// Helper function for validated integer input with exception handling
int PayrollSystem::getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        try {
            if (cin >> value) {
                cin.ignore(1000, '\n');
                // Check if the value makes sense
                if (value < 0) {
                    throw invalid_argument("Value cannot be negative");
                }
                return value;
            } else {
                throw runtime_error("Invalid input - please enter a number");
            }
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

// Helper function for validated double input
double PayrollSystem::getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        try {
            if (cin >> value) {
                cin.ignore(1000, '\n');
                if (value < 0) {
                    throw invalid_argument("Value cannot be negative");
                }
                return value;
            } else {
                throw runtime_error("Invalid input - please enter a number");
            }
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

// Display welcome screen
void PayrollSystem::displayWelcome() {
    cout << "\033[31m";
    cout << "========================================" << endl;
    cout << "     UNIFIED PAYROLL SYSTEM v1.0        " << endl;
    cout << "========================================" << endl;
    cout << "\033[0m";
}

// Employee Portal functionality
void PayrollSystem::employeePortal(Employee* emp) {
    cout << "\033[31m";
    cout << "\n---------------" << endl;
    cout << "Employee Information and Report" << endl;
    cout << "---------------" << endl;
    cout << "\033[0m";

    cout << "Name: " << emp->getName() << endl;
    cout << "ID: " << emp->getIdNumber() << endl;
    cout << "Department: " << emp->getDepartment() << endl;
    cout << "Position: " << emp->getPosition() << endl;

    // Use stringstream to format the salary nicely
    stringstream salaryStream;
    salaryStream << fixed << setprecision(2) << emp->getSalary();
    cout << "Salary: $" << salaryStream.str() << " per hour" << endl;

    cout << "Hours Worked: " << emp->getHoursWorked() << endl;

    // Use stringstream for total pay formatting
    stringstream payStream;
    payStream << fixed << setprecision(2) << emp->calculatePay();
    cout << "Total Pay: $" << payStream.str() << endl;

    cout << "Status: " << emp->statusMessage() << endl;

    cout << "\033[31m";
    cout << "---------------" << endl;
    cout << "\033[0m";

    // Employee menu
    int choice;
    cout << "\nWhat do you want to do?" << endl;
    cout << "1. Add more hours" << endl;
    cout << "2. View updated information" << endl;
    cout << "3. Exit to main menu" << endl;
    choice = getValidInt("Enter choice: ");

    if (choice == 1) {
        double moreHours = getValidDouble("How many hours? ");
        emp->clockHours(moreHours);

        // Format the output with stringstream
        stringstream hoursStream, newPayStream;
        hoursStream << fixed << setprecision(2) << emp->getHoursWorked();
        newPayStream << fixed << setprecision(2) << emp->calculatePay();

        cout << "\nNew hours: " << hoursStream.str() << endl;
        cout << "New pay: $" << newPayStream.str() << endl;

        // Save changes to database
        saveDatabase();

    } else if (choice == 2) {
        cout << "\nUpdated Information:" << endl;
        cout << "Hours Worked: " << emp->getHoursWorked() << endl;

        stringstream payStream2;
        payStream2 << fixed << setprecision(2) << emp->calculatePay();
        cout << "Total Pay: $" << payStream2.str() << endl;
    }
}

// Manager Portal functionality
void PayrollSystem::managerPortal(Manager* mgr) {
    cout << "\033[31m";
    cout << "\n----------------------------------------" << endl;
    cout << "Manager: " << mgr->getName() << " | Dept: " << mgr->getDepartment() << endl;
    cout << "----------------------------------------" << endl;
    cout << "\033[0m";

    int choice = 0;

    while (choice != 4) {
        cout << "\n----------------------------------------" << endl;
        cout << "Manager Menu" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. View payroll report for department" << endl;
        cout << "2. Give a raise to an employee" << endl;
        cout << "3. View employee details" << endl;
        cout << "4. Exit to main menu" << endl;

        choice = getValidInt("Enter your choice (1-4): ");

        if (choice == 1) {
            cout << "\nGenerating payroll report..." << endl;
            mgr->printPayroll();

        } else if (choice == 2) {
            int id = getValidInt("\nEnter the employee ID to give a raise: ");
            double extraRaise = getValidDouble("Enter the raise amount to add to their hourly salary: ");

            Employee* empPtr = mgr->findEmployee(id);

            if (empPtr != nullptr) {
                double oldSalary = empPtr->getSalary();
                empPtr->setSalary(oldSalary + extraRaise);

                // Update in main employee list too
                for (Employee& e : allEmployees) {
                    if (e.getIdNumber() == id) {
                        e.setSalary(oldSalary + extraRaise);
                        break;
                    }
                }

                cout << "\nRaise applied successfully." << endl;
                cout << "Employee: " << empPtr->getName() << endl;

                // Format salary display with stringstream
                stringstream oldSal, newSal;
                oldSal << fixed << setprecision(2) << oldSalary;
                newSal << fixed << setprecision(2) << empPtr->getSalary();

                cout << "Old salary: $" << oldSal.str() << " per hour" << endl;
                cout << "New salary: $" << newSal.str() << " per hour" << endl;

                // Save changes to database
                saveDatabase();
            } else {
                cout << "\nEmployee with that ID was not found in your department." << endl;
            }

        } else if (choice == 3) {
            int id = getValidInt("\nEnter the employee ID to view: ");
            Employee* empPtr = mgr->findEmployee(id);

            if (empPtr != nullptr) {
                cout << "\n--- Employee Details ---" << endl;
                cout << "Name: " << empPtr->getName() << endl;
                cout << "ID: " << empPtr->getIdNumber() << endl;
                cout << "Department: " << empPtr->getDepartment() << endl;
                cout << "Position: " << empPtr->getPosition() << endl;

                // Use stringstream for formatting
                stringstream salStream, payStream;
                salStream << fixed << setprecision(2) << empPtr->getSalary();
                payStream << fixed << setprecision(2) << empPtr->calculatePay();

                cout << "Salary: $" << salStream.str() << " per hour" << endl;
                cout << "Hours Worked: " << empPtr->getHoursWorked() << endl;
                cout << "Total Pay: $" << payStream.str() << endl;
                cout << "Status: " << empPtr->statusMessage() << endl;
            } else {
                cout << "\nEmployee not found in your department." << endl;
            }

        } else if (choice == 4) {
            cout << "\nReturning to main menu..." << endl;

        } else {
            cout << "\nInvalid option. Please enter a number from 1 to 4." << endl;
        }
    }
}

// Main system run loop
void PayrollSystem::run() {
    displayWelcome();

    // Load the database
    if (!loadDatabase()) {
        cout << "\nCannot proceed without database. Exiting..." << endl;
        return;
    }

    int mainChoice = 0;

    while (mainChoice != 3) {
        cout << "\n========================================" << endl;
        cout << "Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "1. Employee Login" << endl;
        cout << "2. Manager Login" << endl;
        cout << "3. Exit System" << endl;

        mainChoice = getValidInt("Enter your choice (1-3): ");

        if (mainChoice == 1) {
            // Employee Login
            int empId = getValidInt("\nEnter your Employee ID: ");
            Employee* emp = loginAsEmployee(empId);

            if (emp != nullptr) {
                cout << "\nWelcome, " << emp->getName() << "!" << endl;
                employeePortal(emp);
            } else {
                cout << "\nEmployee ID not found. Please try again." << endl;
            }

        } else if (mainChoice == 2) {
            // Manager Login
            int mgrId = getValidInt("\nEnter your Manager ID: ");
            Manager* mgr = loginAsManager(mgrId);

            if (mgr != nullptr) {
                cout << "\nWelcome, Manager " << mgr->getName() << "!" << endl;
                managerPortal(mgr);
            } else {
                cout << "\nManager login failed. Please try again." << endl;
            }

        } else if (mainChoice == 3) {
            cout << "\nThank you for using the Payroll System. Goodbye!" << endl;

        } else {
            cout << "\nInvalid choice. Please enter 1, 2, or 3." << endl;
        }
    }
}
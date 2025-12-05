// Employee Portal
// Randol + Ryan code
// used ai to help with colors
#include "employee.h"
#include "Partime.h"
#include "fulltime.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "\033[31m";
  cout << "---------------" << endl;
  cout << "Welcome to the Employee Portal!" << endl;
  cout << "---------------" << endl;
  cout << "\033[0m";

  // Employee stuff
  string employeeName, employeeDept, employeePos, employeeType;
  int employeeId;
  double employeeSalary, employeeHours;

  // Ask for ID
  int searchId;
  bool found = false;

  // Keep asking until we find a valid employee
  while (!found) {
    cout << "Please enter your Employee ID: ";
    cin >> searchId;

    ifstream inFile;
    inFile.open("database.txt");

    if (!inFile) {
      cout << "Error opening file!" << endl;
      return 1;
    }

    // Read file to find matching employee
    int tempId;
    string tempName, tempType;
    double tempSalary;

    while (inFile >> tempId >> tempName >> tempSalary >> tempType) {
      if (tempId == searchId) {
        // Found the employee, save their info
        employeeName = tempName;
        employeeId = tempId;
        employeeDept = "Sales";
        employeePos = "Employee";
        employeeSalary = tempSalary;
        employeeHours = 0;  // Start with zero hours
        employeeType = tempType;
        found = true;
        break;
      }
    }

    inFile.close();

    if (!found) {
      cout << "ID not found! Try again." << endl;
    }
  }

  // Create employee based on type using polymorphism
  // Initialize pointer to null first for safety
  Employee* myEmployee = nullptr;

  if (employeeType == "F") {
    // Full-time employee with overtime benefits
    myEmployee = new FullTimeEmployee(employeeName, employeeId, employeeDept, 
                                      employeePos, employeeSalary, employeeHours);
    cout << "\n\033[31m";
    cout << "Employee Type: Full-Time" << endl;
    cout << "\033[0m";
    cout << "Benefits: Overtime pay (1.5x) after 40 hours" << endl;
  } else {
    // Part-time employee with flexible schedule
    myEmployee = new PartTimeEmployee(employeeName, employeeId, employeeDept, 
                                      employeePos, employeeSalary, employeeHours);
    cout << "\n\033[31m";
    cout << "Employee Type: Part-Time" << endl;
    cout << "\033[0m";
    cout << "Benefits: Flexible schedule, max 30 hours/week" << endl;
  }

  // Show info
  cout << "\033[31m";
  cout << "\n---------------" << endl;
  cout << "Employee Info" << endl;
  cout << "---------------" << endl;
  cout << "\033[0m";
  cout << "Name: " << myEmployee->getName() << endl;
  cout << "ID: " << myEmployee->getIdNumber() << endl;
  cout << "Department: " << myEmployee->getDepartment() << endl;
  cout << "Position: " << myEmployee->getPosition() << endl;
  cout << "Hourly Rate: $" << myEmployee->getSalary() << endl;
  cout << "Hours: " << myEmployee->getHoursWorked() << endl;
  cout << "Total Pay: $" << myEmployee->calculatePay() << endl;
  cout << "Status: " << myEmployee->statusMessage() << endl;
  cout << "\033[31m";
  cout << "---------------" << endl;
  cout << "\033[0m";

  // Menu
  int choice = 0;

  while (choice != 2) {
    cout << "\nMenu:" << endl;
    cout << "1. Add hours" << endl;
    cout << "2. Exit" << endl;
    cout << "Pick: ";

    // Check if input is valid
    if (!(cin >> choice)) {
      cout << "Invalid input!" << endl;
      cin.clear();  // Clear error flags
      cin.ignore(1000, '\n');  // Ignore bad input
      continue;
    }

    if (choice == 1) {
      double hours;
      cout << "Hours to add: ";

      // Validate hours input
      if (!(cin >> hours)) {
        cout << "Invalid hours!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
      }

      // Add the hours to employee's total
      myEmployee->clockHours(hours);

      cout << "\n\033[31m";
      cout << "--- Updated Info ---" << endl;
      cout << "\033[0m";
      cout << "Total hours: " << myEmployee->getHoursWorked() << endl;
      cout << "Total pay: $" << myEmployee->calculatePay() << endl;
      cout << "Status: " << myEmployee->statusMessage() << endl;

      // Show overtime info for full-time
      if (employeeType == "F" && myEmployee->getHoursWorked() > 40) {
          double overtimeHours = myEmployee->getHoursWorked() - 40;
          cout << "Overtime hours: " << overtimeHours << " hours" << endl;
      }

    } else if (choice == 2) {
      cout << "\nBye!" << endl;

    } else {
      cout << "Invalid choice." << endl;
    }
  }

  // Clean up - delete the dynamically allocated employee
  delete myEmployee;

  return 0;
}
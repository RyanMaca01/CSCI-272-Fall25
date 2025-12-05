// Josiah code - Manager Portal with line-based input validation
// This program lets a manager enter their info, load employees from a file,
// and then manage them using a menu (view payroll, give raises, remove employees).
// Updated to handle Part-Time and Full-Time employees

#include "manager.h"
#include "employee.h"
#include "Partime.h"
#include "fulltime.h"

#include <iostream>
#include <fstream>
using namespace std;

// Helper function to safely read an int from the user
int getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;          // Ask the user for a value
        if (cin >> value) {      // If reading succeeds, return the value
            // Clear the rest of the line (in case user typed extra stuff)
            cin.ignore(1000, '\n');
            return value;
        } else {
            // If reading fails (user typed something not a number)
            cout << "Invalid input. Please enter a whole number." << endl;
            cin.clear();                     // Clear the error flag on cin
            cin.ignore(1000, '\n');          // Throw away the entire wrong line
        }
    }
}

// Helper function to safely read a double from the user
double getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;          // Ask the user for a value
        if (cin >> value) {      // If reading succeeds, return the value
            cin.ignore(1000, '\n');  // Clear the rest of the line
            return value;
        } else {
            // If reading fails (user typed something not a number)
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();                     // Clear the error flag on cin
            cin.ignore(1000, '\n');          // Throw away the entire wrong line
        }
    }
}

// Helper function to safely read a char from the user
char getValidChar(const string& prompt) {
    char value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(1000, '\n');
            return value;
        } else {
            cout << "Invalid input. Please enter a character." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

int main() {
    // Intro banner with red color to make it stand out
    cout << "\033[31m";
    cout << "----------------------------------------" << endl;
    cout << "        Welcome to the Manager Portal   " << endl;
    cout << "----------------------------------------" << endl;
    cout << "\033[0m";

    // Variables to store manager information
    string managerName;
    int managerId;
    string managerDept;
    string managerPos = "Manager";   // Fixed title for this portal
    double managerSalary;
    double managerRaise;

    cout << "Please enter your manager information below." << endl;

    // Get basic manager info from the user
    cout << "Manager Name (one word): ";
    cin >> managerName;
    cin.ignore(1000, '\n');  // Clear the rest of the line

    managerId = getValidInt("Manager ID (number): ");

    cout << "Department you manage (one word): ";
    cin >> managerDept;
    cin.ignore(1000, '\n');  // Clear the rest of the line

    managerSalary = getValidDouble("Your base salary: ");

    managerRaise = getValidDouble("Standard raise amount you can apply: ");

    // Create a Manager object using the info above
    Manager myManager(managerName, managerId, managerDept,
                      managerPos, managerSalary, managerRaise);

    // Try to open the employee database file
    ifstream inFile("database.txt");

    if (!inFile) {
        // If the file cannot be opened, show an error and exit
        cout << "\nError: Could not open database.txt." << endl;
        cout << "Make sure database.txt is in the same folder as this program." << endl;
        return 1;
    }

    // Temporary variables used to read each employee from the file
    string tempName, tempType;
    int tempId;
    double tempSalary;

    // Read each employee from the file
    // Expected format per line: id name salary type
    while (inFile >> tempId >> tempName >> tempSalary >> tempType) {
        // Create the appropriate employee type based on the type field
        // Using pointers so the objects stay in memory until we add them
        if (tempType == "F") {
            // Create a Full-Time Employee
            FullTimeEmployee* emp = new FullTimeEmployee(tempName, tempId, "Sales", "Employee", tempSalary, 0);
            myManager.addEmployee(*emp);
            delete emp;  // Clean up after adding
        } else {
            // Create a Part-Time Employee
            PartTimeEmployee* emp = new PartTimeEmployee(tempName, tempId, "Sales", "Employee", tempSalary, 0);
            myManager.addEmployee(*emp);
            delete emp;  // Clean up after adding
        }
    }

    // Close the file after reading all employees
    inFile.close();

    // Main menu loop for manager actions
    int choice = 0;

    // Keep showing the menu until the user chooses option 5 (Exit)
    while (choice != 5) {
        cout << "\n----------------------------------------" << endl;
        cout << "Manager Menu" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. View payroll report for all employees" << endl;
        cout << "2. Give a raise to one employee" << endl;
        cout << "3. Remove an employee by ID" << endl;
        cout << "4. Add new employee" << endl;
        cout << "5. Exit" << endl;

        // Get a valid menu choice from the user
        choice = getValidInt("Enter your choice (1-5): ");

        // Option 1: Show payroll for all employees
        if (choice == 1) {
            cout << "\nGenerating payroll report..." << endl;
            myManager.printPayroll();

        // Option 2: Give a raise to a specific employee
        } else if (choice == 2) {
            // Ask for the employee ID and raise amount with validation
            int id = getValidInt("\nEnter the employee ID to give a raise: ");
            double extraRaise = getValidDouble("Enter the raise amount to add to their hourly rate: ");

            // Try to find the employee in the manager's list
            Employee* empPtr = myManager.findEmployee(id);

            if (empPtr != nullptr) {
                // If found, update their salary
                double oldSalary = empPtr->getSalary();
                empPtr->setSalary(oldSalary + extraRaise);

                cout << "\nRaise applied successfully." << endl;
                cout << "Employee: " << empPtr->getName() << endl;
                cout << "Old hourly rate: $" << oldSalary << endl;
                cout << "New hourly rate: $" << empPtr->getSalary() << endl;
            } else {
                // If not found, let the user know
                cout << "\nEmployee with that ID was not found." << endl;
            }

        // Option 3: Remove an employee by their ID
        } else if (choice == 3) {
            int id = getValidInt("\nEnter the employee ID to remove: ");

            // Try to remove the employee
            bool removed = myManager.removeEmployee(id);

            if (removed) {
                cout << "Employee removed successfully." << endl;
                // Note: Would need to restart to fully update database
                cout << "Note: Restart program to update database file." << endl;
            } else {
                cout << "No employee found with that ID." << endl;
            }

        // Option 4: Add new employee
        } else if (choice == 4) {
            cout << "\n--- Add New Employee ---" << endl;

            int newId = getValidInt("Employee ID: ");

            cout << "Employee Name (one word): ";
            string newName;
            cin >> newName;
            cin.ignore(1000, '\n');

            double newSalary = getValidDouble("Hourly Rate: $");

            char empType = getValidChar("Employee Type (F for Full-Time, P for Part-Time): ");

            // Validate and normalize type
            if (empType == 'f') empType = 'F';
            if (empType == 'p') empType = 'P';

            if (empType != 'F' && empType != 'P') {
                cout << "Invalid type! Defaulting to Part-Time." << endl;
                empType = 'P';
            }

            // Create the appropriate employee type using pointers
            if (empType == 'F') {
                FullTimeEmployee* newEmp = new FullTimeEmployee(newName, newId, "Sales", "Employee", newSalary, 0);
                myManager.addEmployee(*newEmp);
                delete newEmp;  // Clean up memory
                cout << "\nFull-Time employee added successfully!" << endl;
                cout << "Benefits: Overtime pay (1.5x) after 40 hours" << endl;
            } else {
                PartTimeEmployee* newEmp = new PartTimeEmployee(newName, newId, "Sales", "Employee", newSalary, 0);
                myManager.addEmployee(*newEmp);
                delete newEmp;  // Clean up memory
                cout << "\nPart-Time employee added successfully!" << endl;
                cout << "Benefits: Flexible schedule, max 30 hours/week" << endl;
            }

            // Append to database file
            ofstream outFile("database.txt", ios::app);
            if (outFile) {
                outFile << newId << " " << newName << " " << newSalary << " " << empType << endl;
                cout << "Employee added to database." << endl;
            } else {
                cout << "Warning: Could not update database file." << endl;
            }
            outFile.close();

        // Option 5: Exit the program
        } else if (choice == 5) {
            cout << "\nThank you for using the Manager Portal. Goodbye!" << endl;

        // If the user enters a number not between 1 and 5
        } else {
            cout << "\nInvalid menu option. Please enter a number from 1 to 5." << endl;
        }
    }

    // End of program
    return 0;
}
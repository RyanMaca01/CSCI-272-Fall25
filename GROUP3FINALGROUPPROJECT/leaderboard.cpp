// Leaderboard Portal
// Randols code
#include "employee.h"
#include "Partime.h"
#include "fulltime.h"
#include "leaderboard.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "\033[31m";
    cout << "---------------" << endl;
    cout << "Leaderboard Portal" << endl;
    cout << "---------------" << endl;
    cout << "\033[0m";

    // Load leaderboard data from file if it exists
    Leaderboard board;
    board.loadData();

    // Ask for employee ID
    int id;
    cout << "Enter your Employee ID: ";

    // Validate the ID input
    if (!(cin >> id)) {
        cout << "Invalid ID!" << endl;
        return 1;
    }

    // Load all employees from database to update leaderboard
    ifstream file("database.txt");
    if (!file) {
        // Check if file opened successfully
        cout << "Error: Could not open database.txt" << endl;
        return 1;
    }

    int tempId;
    string tempName, tempType;
    double tempSalary;

    // Read each employee and update the leaderboard
    while (file >> tempId >> tempName >> tempSalary >> tempType) {
        // Create temp employee with current data based on type
        // Start with null pointer for safety
        Employee* emp = nullptr;

        if (tempType == "F") {
            // Create full-time employee
            emp = new FullTimeEmployee(tempName, tempId, "Sales", "Employee", tempSalary, 0);
        } else {
            // Create part-time employee
            emp = new PartTimeEmployee(tempName, tempId, "Sales", "Employee", tempSalary, 0);
        }

        // Update leaderboard if employee was created successfully
        if (emp != nullptr) {
            board.updateEmployee(*emp);
            delete emp;  // Clean up memory
        }
    }
    file.close();

    // Show full leaderboard
    board.showLeaderboard();

    // Show user's rank
    int rank = board.getRank(id);
    if (rank > 0) {
        cout << "\033[31m";
        cout << "Your current rank: #" << rank << endl;
        cout << "\033[0m" << endl;
    } else {
        // ID not found in rankings
        cout << "Your ID was not found in rankings." << endl;
        return 0;
    }

    // Menu for options
    int choice = 0;
    while (choice != 3) {
        cout << "\nOptions:" << endl;
        cout << "1. View leaderboard again" << endl;
        cout << "2. Get improvement tips" << endl;
        cout << "3. Exit" << endl;
        cout << "Pick: ";

        // Validate menu choice
        if (!(cin >> choice)) {
            cout << "Invalid input!" << endl;
            cin.clear();  // Clear error state
            cin.ignore(1000, '\n');  // Ignore bad input
            continue;
        }

        if (choice == 1) {
            // Show the leaderboard again
            board.showLeaderboard();
            rank = board.getRank(id);
            if (rank > 0) {
                cout << "Your rank: #" << rank << endl;
            }

        } else if (choice == 2) {
            // Find employee to show tips
            ifstream inFile("database.txt");
            bool found = false;

            if (inFile) {
                int tempId;
                string tempName, tempType;
                double tempSalary;

                // Search for the employee in database
                while (inFile >> tempId >> tempName >> tempSalary >> tempType) {
                    if (tempId == id) {
                        // Found the employee, create object
                        Employee* emp = nullptr;

                        if (tempType == "F") {
                            emp = new FullTimeEmployee(tempName, tempId, "Sales", "Employee", tempSalary, 0);
                        } else {
                            emp = new PartTimeEmployee(tempName, tempId, "Sales", "Employee", tempSalary, 0);
                        }

                        // Show tips if employee was created
                        if (emp != nullptr) {
                            board.showTips(*emp);
                            delete emp;  // Clean up
                            found = true;
                        }
                        break;
                    }
                }
                inFile.close();
            }

            if (!found) {
                cout << "Could not load your info." << endl;
            }

        } else if (choice == 3) {
            cout << "Bye!" << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
// Leaderboard header
// randols code
#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "employee.h"
using namespace std;

// Employee stats for leaderboard
struct EmployeeStats {
    string name;
    int id;
    double totalPay;
    double hours;
};

// Compare for sorting
bool comparePay(EmployeeStats a, EmployeeStats b) {
    return a.totalPay > b.totalPay;
}


// mainly used youtube but still used some ai to help with the sorting and comparing, couldnt figure out how to sort properly
template <typename Iterator, typename Compare>
void sort(Iterator begin, Iterator end, Compare comp) {
    int n = end - begin;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!comp(*(begin + j), *(begin + j + 1))) {
                auto temp = *(begin + j);
                *(begin + j) = *(begin + j + 1);
                *(begin + j + 1) = temp;
            }
        }
    }
}

class Leaderboard {
private:
    vector<EmployeeStats> employees;

public:
    Leaderboard() {}

    // Add or update employee
    void updateEmployee(Employee emp) {
        bool found = false;

        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].id == emp.getIdNumber()) {
                employees[i].totalPay = emp.calculatePay();
                employees[i].hours = emp.getHoursWorked();
                found = true;
                break;
            }
        }

        if (!found) {
            EmployeeStats newEmp;
            newEmp.name = emp.getName();
            newEmp.id = emp.getIdNumber();
            newEmp.totalPay = emp.calculatePay();
            newEmp.hours = emp.getHoursWorked();
            employees.push_back(newEmp);
        }
    }

    // Display leaderboard
    void showLeaderboard() {
        if (employees.size() == 0) {
            cout << "No employee data yet." << endl;
            return;
        }

        vector<EmployeeStats> sorted = employees;
        sort(sorted.begin(), sorted.end(), comparePay);

        cout << "\n==============================" << endl;
        cout << "      EMPLOYEE LEADERBOARD" << endl;
        cout << "==============================" << endl;
        cout << "Rank  Name        ID      Pay" << endl;
        cout << "------------------------------" << endl;

        for (int i = 0; i < sorted.size(); i++) {
            cout << "#" << i + 1 << "   ";
            cout << sorted[i].name << "      ";
            cout << sorted[i].id << "    ";
            cout << "$" << sorted[i].totalPay << endl;
        }

        cout << "==============================\n" << endl;
    }

    // Get employee's rank
    int getRank(int id) {
        vector<EmployeeStats> sorted = employees;
        sort(sorted.begin(), sorted.end(), comparePay);

        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i].id == id) {
                return i + 1;
            }
        }
        return -1;
    }

    // Performance tips
    void showTips(Employee emp) {
        double hours = emp.getHoursWorked();
        double pay = emp.calculatePay();
        int rank = getRank(emp.getIdNumber());

        cout << "\n--- Your Performance Tips ---" << endl;

        if (hours < 20) {
            cout << "- Low hours. Try to work at least 20!" << endl;
        } else if (hours < 40) {
            cout << "- Part-time hours. Consider more shifts." << endl;
        } else {
            cout << "- Great! Full-time hours." << endl;
        }

        if (pay < 500) {
            cout << "- Work more hours to increase earnings." << endl;
        } else if (pay < 1000) {
            cout << "- Good earnings, keep it up!" << endl;
        } else {
            cout << "- Excellent pay!" << endl;
        }

        if (rank == 1) {
            cout << "- You're #1! Amazing!" << endl;
        } else if (rank <= 3) {
            cout << "- Top 3! Keep pushing for #1." << endl;
        } else if (rank > 0) {
            cout << "- Rank #" << rank << ". Work more to climb up!" << endl;
        }

        cout << endl;
    }

    // Save to file
    void saveData() {
        ofstream file("leaderboard.txt");
        if (!file) return;

        for (int i = 0; i < employees.size(); i++) {
            file << employees[i].name << " ";
            file << employees[i].id << " ";
            file << employees[i].totalPay << " ";
            file << employees[i].hours << endl;
        }
        file.close();
    }

    // Load from file
    void loadData() {
        ifstream file("leaderboard.txt");
        if (!file) return;

        employees.clear();
        EmployeeStats temp;

        while (file >> temp.name >> temp.id >> temp.totalPay >> temp.hours) {
            employees.push_back(temp);
        }
        file.close();
    }
};

#endif
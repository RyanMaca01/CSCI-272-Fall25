#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    string ownerName;
    int accountNumber;
    double balance;
    vector<string> history;
//Ryan + Noeleen Collab 
public:
    BankAccount(const string& name, int accNum, double initialBalance)
        : ownerName(name), accountNumber(accNum), balance(initialBalance) {
        history.push_back("Account created with initial deposit of $" + to_string(initialBalance));
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back("Deposited $" + to_string(amount));
        cout << "Deposited $" << fixed << setprecision(2) << amount << endl;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
            return false;
        }
        balance -= amount;
        history.push_back("Withdrew $" + to_string(amount));
        cout << "Withdrew $" << fixed << setprecision(2) << amount << endl;
        if (balance == 0) {
            cout << "Balance is now zero." << endl;
        }
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << "Owner: " << ownerName << endl
             << "Account Number: " << accountNumber << endl
             << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void showHistory() const {
        cout << "Transaction History (" << history.size() << "):" << endl;
        for (const auto& transaction : history) {
            cout << "- " << transaction << endl;
        }
    }
};
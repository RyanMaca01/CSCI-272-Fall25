#include <iostream>
#include <iomanip>
#include "BankAccount.h"
#include <string>
#include <vector>
using namespace std; 

/*
                            Our Reflections: 

Ryan Maca Reflection: what I found tricky was making the menu function and making sure it works when a user chooses another function. I learned that you could use cin.clear() function when a user input something incorrect. Also, I had to debug and make sure our main functions were calling the correct function names. I found it hard to have the functions print out the statements for each part of the menu. I have learned how to come up with ways to get the statements to work. 

Noeleen: When working on the main function, I had to make sure that after each response the menu would not only reappear, but make sure that each action was performed correctly (i.e. the balance updating with each action). I originally tried to use a switch statement for the menu, but found that it was easier to use if-else statements. Another thing I had to do was make sure that the correct functions were being called from the BankAccount class to ensure that the program was working correctly. In addition to this, I helped debug the program from some inevitable syntax errors.

Randol: I worked on functions and code formatting. The biggest challenge I faced during this program was making sure input validation worked correctly and dealt with all kinds of users mistakes without breaking the program. I also had to check that each function returned the proper values and interacted well with the main program. Making the code consistent and easy to read took a little time, though it helped make the overall program easier to understand.
*/


// Function to validate and return a positive double
double DoubleNum(string question) {
    double num;
    while (true) {
        cout << question;
        cin >> num;
        if (cin.fail()) {
            cout << "Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (num > 0) {
            return num;
        } else {
            cout << "Please enter a positive number." << endl;
        }
    }
}

// Function to validate and return a positive integer
int IntNum(string question) {
    int num;
    while (true) {
        cout << question;
        cin >> num;
        if (cin.fail()) {
            cout << "Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (num > 0) {
            return num;
        } else {
            cout << "Please enter a positive number." << endl;
        }
    }
}


// randol: added formating and made the main menu look better, added spacing so it looks cleaner and easier to read rather than all cramped together
int main(){
//Ryan Has edited this part of the code and added the bank name to the main menu
cout << "==================================" << endl;
cout << "     Welcome to John Jay Bank     " << endl;
cout << "==================================" << endl;
string name;
cout << "Please enter your name: ";
cin.ignore(); // clears leftover newline if needed
getline(cin, name);
cout << "==================================" << endl;
int accountNumber = IntNum("Please enter your account number: ");
cout << "==================================" << endl;
double initialBalance = DoubleNum("Please enter your initial account balance: ");
cout << "==================================" << endl;

BankAccount account(name, accountNumber, initialBalance);
int choice = 0;
while (true) {
cout << "Menu:" << endl;
cout << "1. Deposit" << endl;
cout << "2. Withdraw" << endl;
cout << "3. Show Balance" << endl;
cout << "4. Show Account Info" << endl;
cout << "5. Show Transaction History" << endl;
cout << "6. Exit" << endl;
cout << "==================================" << endl;
cout << "Please select an option: ";
cin >> choice;

if (cin.fail()) {
cout << "Invalid input. Please enter a number between 1 and 6." << endl;
cin.clear();
cin.ignore(1000, '\n');
continue;
  } // randol: added all lines and formating here so it looks less cramped and more organized, hard to read once it was all cramped together
  if (choice == 1) {
          cout << "==================================" << endl;
          double amount = DoubleNum("Enter deposit amount: ");
          account.deposit(amount);
          cout << "==================================" << endl;
      }
      else if (choice == 2) {
          cout << "==================================" << endl;
          double amount = DoubleNum("Enter withdrawal amount: ");
          account.withdraw(amount);
          cout << "==================================" << endl;
      }
      else if (choice == 3) {
          cout << "==================================" << endl;
          cout << "Current Balance: $" << account.getBalance() << endl;
          cout << "==================================" << endl;
      }
      else if (choice == 4) {
          cout << "==================================" << endl;
          account.display();
          cout << "==================================" << endl;
      }
      else if (choice == 5) {
          cout << "==================================" << endl;
          account.showHistory();
          cout << "==================================" << endl;
      }
      else if (choice == 6) {
          cout << "==================================" << endl;
          cout << "Thank you for using John Jay Bank. Goodbye!" << endl;
          break; // exits the loop
      }
      else {
          cout << "Invalid option. Please try again." << endl;
      }
  } // end of while loop



} // end of main


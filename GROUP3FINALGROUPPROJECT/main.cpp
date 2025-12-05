#include <iostream>
#include <iomanip>
#include <string>
#include "PayrollSystem.h"
using namespace std;

int main(){
    // Try to run the whole system with error handling
    try {
        // Make the payroll system object
        PayrollSystem system("database.txt");

        // Start the main program
        system.run();
    } catch (const exception& e) {
        // Catch any standard exceptions
        cerr << "\nSystem Error: " << e.what() << endl;
        cerr << "The program needs to close." << endl;
        return 1;
    } catch (...) {
        // Catch anything else that might go wrong
        cerr << "\nUnknown error happened in the system." << endl;
        return 1;
    }
    return 0;
}
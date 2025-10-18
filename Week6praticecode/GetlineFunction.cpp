#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {

    cout << "Enter a character: ";
    char ch = cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout << "You entered: " << ch << std::endl;


   cout << "Enter your full name: ";
   string fullName;


    getline(cin, fullName);
    cout << "Hello, " << fullName << "!" << endl;

    return 0;
}

#include "user.h"
using namespace std;
int main(){

User user1("userName123", "password123");
bool success = user1.login("userName1234", "password123");



    if (success){
        // Display a message indicating successful login.
        cout << "User logged in successfully!" << endl;
    }
    else{
        // Display a message indicating a failed login attempt.
        cout << "Login failed. Please check your credentials and try again." << endl;
    }
























}
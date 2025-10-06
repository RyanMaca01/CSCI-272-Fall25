#include "bankaccount.h"
#include <iostream>

using namespace std;

int main(){

// You need to make the bankaccount strucutre/ this is going to be the blue print
BankAccount bankAccount1;



//This would Deposit funds (11.5) into the "bankaccount" using the "deposit" method
bankAccount1.deposit(11.5);


cout << "Account Balance $" << bankAccount1.getBalance() << endl;





}


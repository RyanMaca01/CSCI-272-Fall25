// Start with definting the bank account 
 class BankAccount{
private:
double balance = 00.0; 

public:

void deposit (double amount){
    balance += amount;
}

double getBalance() const{
    return balance;
}

void withdraw(double amount){
    if ( amount <= balance){
        balance -= amount;
    }
}




 };
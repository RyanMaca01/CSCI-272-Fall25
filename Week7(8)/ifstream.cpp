#include <iostream> 
#include <fstream> 
#include  <cstdlib>
#include <iomanip> 

using namespace std;

void outputline(int account, const string& name, double balance){
    cout << left << setw(10) << account
    << setw(15) << name 
    << setw(10)<< fixed << setprecision(2) << right << balance << endl;
}



int main(){

ifstream inClientfILE("clients.txt", ios::in);
if (!inClientfILE){
    cerr << "File could not be opened! \n";
    exit(EXIT_FAILURE);
}

cout << left << setw(10) << "account" << setw(15) << "name" << setw(10) << right << "balance" << endl;


//we need to declare the varibales 
int account;
string name;
double balance;

while( inClientfILE >> account >> name >> balance ){
    outputline(account, name , balance);
}


//extract, save data, then save the data and then display it











}
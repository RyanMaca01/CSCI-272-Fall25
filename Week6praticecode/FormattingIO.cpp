#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){

//This example pratice question 

double var1 = 21.5305830;
string name = "Ryan";
int age = 20;
//Using the setw to get the set field width and set fill character

cout << setw(10) << setfill('-') << "Name:" << setw(15) << name << left << "Age" << setw(5) << age << endl;

cout << "This is var 1, with presion of 2" << setprecision(3) << var1 << endl;

cout << setprecision(8);


}
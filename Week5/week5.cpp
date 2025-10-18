#include <iostream>
#include <iomanip>

using namespace std;


int main(){

/*
int number; 
cout << "Enter a number" << endl;
cin >> number; 
cout  << "You entered: " << number << endl;

cerr << "This is an error message\n" << endl;
clog << "This is log message\n" << endl;*/

string item = "Coffee";
double price = 2.5;
double tax = 0.20;
double total = price + tax; 


cout << setw(10) << left << "Item" << setw(10) << right << "Price"  << endl;
cout << setw(10) << left << item << setw(10) << right << fixed << setprecision(5) << total << endl;
cout << setw(10) << setfill('_') << "Menu" << endl << setw(10) << left << item << setw(10) << right << total << endl;





}
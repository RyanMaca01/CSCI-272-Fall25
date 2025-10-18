#include <iostream> 
#include <sstream>

using namespace std;




int main(){
string input;
int number;

cout <<"Enter an integer between 0 and 100: ";
cin >> input;

istringstream iss(input); //we created a stream from a string (input)

if(iss >> number){
    if(number >= 0 && number <= 100)
      cout << "Vavlid Input: " << number << endl;
    else 
    cout << number << "Out of range!\n";
}else{
    cout << "Invalid input (not an integer)\n";
}







}
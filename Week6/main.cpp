#include <iostream>
#include <string> 
#include <sstream> //String Stream 


using namespace std;


class Person{
public: 
string name;
int age;

};


int main(){
/*
string inputString = "Alice 30 Female";

istringstream input(inputString);

Person person1;

input >> person1.name >> person1.age >> person1.gender;


cout << "Name" << person1.name << endl;
cout << "Age" << person1.age << endl;
cout << "Gender" << person1.gender << endl;
return 0;
*/

const int SIZE = 80; // it has the limit 80 
char buffer[SIZE]; //our char can contanin 80 characters 

cout << "Enter  a sentence: \n";
cin.read(buffer,5); 

cout <<"\nThe sentence entered: \n";
cout.write(buffer, cin.gcount());
cout << endl;
cout << "Input # of character: " << cin.gcount() << endl;




}
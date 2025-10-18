#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Person{
public: 
string name;
int age;
}; 


int main(){

string inputString = "Snoopy 30"; 
istringstream input(inputString);
Person person;

input >> person.name >> person.age;
cout << "Name: " << person.name << endl;
cout << "Age: " << person.age << endl;


}

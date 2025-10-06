#include <iostream>
using namespace std;


class Person{
public: 
string name{ "John Doe"};
int age {30};
char gender{'M'};

public: 
void introduce(){
    cout << "I'M "  << name << ".Age: " << age;

  if (gender == 'M'){
    cout << " I idenfity as a male" << endl; 
  }else if (gender == 'F'){
   cout << " I idenfity as a female" << endl; 
  }else {
    cout << "Gender not specified." << endl;
  }

}

};
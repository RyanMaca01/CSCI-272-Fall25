#include <iostream>
using namespace std;

class Person {
public:
  
    string name{"Ryan"};
    int age{20};
    char gender{'M'};

public:
void introduce() {   
cout << "Hello, I'm " << name << ". I'm " << age << " years old.";

// Check the gender and provide additional information accordingly.
if (gender == 'M') {
cout << " I'm a male." << std::endl;
} else if (gender == 'F') {
cout << " I'm a female." << std::endl;
} else {
cout << " Gender unspecified." << std::endl;
}
}
};


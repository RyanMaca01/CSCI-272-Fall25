#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
    string name;

public:
    Person(string n) : name(n) {
        cout << "Person constructor\n";
    }

    ~Person() {
        cout << "Person destructor\n";
    }

    void showName() const {
        cout << "Name is: " << name << endl;
    }
};

#endif
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "person.h"
using namespace std;

class Student : public Person {
private:
    int studentID;

public:
    Student(string n, int id)
        : Person(n), studentID(id)
    {
        cout << "Student constructor\n";
    }

    ~Student() {
        cout << "Student destructor\n";
    }

    void showInfo() const {
        showName();
        cout << "ID is: " << studentID << endl;
    }
};

#endif
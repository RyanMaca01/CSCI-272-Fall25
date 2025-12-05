//Ryans Code 
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>


using namespace std;


class  Employee{

private:
    string name;   
    int idNumber; 
    string department;  
    string position;   
    double salary; 
    double hoursWorked;

public:


Employee(string n, int id, string dept, string pos, double sal, double hours)
: name(n), idNumber(id), department(dept), position(pos), salary(sal), hoursWorked(0) {}

// Virtual destructor for polymorphism
virtual ~Employee() {}

// Getters
string getName() const { return name; }
int getIdNumber() const { return idNumber; }
string getDepartment() const { return department; }
string getPosition() const { return position; }
double getSalary() const { return salary; }
double getHoursWorked() const { return hoursWorked; }

// Setters
void setName(const string& n) { name = n; }
void setIdNumber(int id) { idNumber = id; }
void setDepartment(const string& dept) { department = dept; }
void setPosition(const string& pos) { position = pos; }
void setSalary(double sal) { salary = sal; }
void setHoursWorked(double hours) { hoursWorked = hours; }

// Add hours
void clockHours(double hours) { hoursWorked += hours; }

// Virtual functions for polymorphism - can be overridden by derived classes
virtual double calculatePay() const { return salary * hoursWorked; }
virtual string statusMessage() const {
    if (hoursWorked < 20) return "Warning: Low hours!";
    return "Hours are sufficient.";
}

// Operator overloading
// Lets us compare employees easier
// used ai to help with this part, couldnt figure out how to compare employees properly
// Check if two employees are same by id
// Randol Add this part to the H file
bool operator==(const Employee& other) const {
    return idNumber == other.idNumber;
}

// Compare by salary used for sorting
bool operator<(const Employee& other) const {
    return salary < other.salary;
}

// Compare by salary the other way
bool operator>(const Employee& other) const {
    return salary > other.salary;
}

// Print employee with cout makes output easier
friend ostream& operator<<(ostream& os, const Employee& emp) {
    os << "ID: " << emp.idNumber << " | Name: " << emp.name 
       << " | Dept: " << emp.department << " | Salary: $" << emp.salary;
    return os;
}

};

#endif
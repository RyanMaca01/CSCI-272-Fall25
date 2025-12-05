#include <iostream>
#include "MyClass.h"
using namespace std;

int MyClass::count = 0; // Initialize the static member

int main(){

    MyClass obj1;
    MyClass obj2;

    std::cout << obj1.getCount() << " " << obj2.getCount() << std::endl; // Outputs 5 5

    obj1.setCount(5); // Access static member
    std::cout << obj1.getCount() << " " << obj2.getCount() << std::endl; // Outputs 5 5
    return 0;

}

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    void showMessage() {
        std::cout << "Hello from Singleton!" << std::endl;
    }
    // Delete the copy constructor and assignment operator
    Singleton(Singleton const&) = delete;
    void operator=(Singleton const&) = delete;
private:
    Singleton() {} // Private constructor to prevent instantiation.
};

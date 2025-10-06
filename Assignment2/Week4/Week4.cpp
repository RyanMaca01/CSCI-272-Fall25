
//Classess
#include <iostream>
using namespace std;

//Class is a blueprint
class Car{
    private: 
    string brand{"Honda"};
    string model{"Civic"};
    int year {2025};

 public:
 void startEngine(){
    cout << "Engine Started for: " << year << " " << brand << model << endl;
 }

 void accelerate(){
    cout << "Accelerate car" << model << endl;
 }

};


int main(){
Car car1;  //Create an object :: what does this do?


car1.startEngine();
car1.accelerate();



}

#include <iostream>
using namespace std;


class Car{
    private: 
    string brand{"Honda"};
    string model{"Civic"};
    int year {2025};

 public:
 Car(){     //defalt constructor
 }
   Car (string b, string m, string y){
      brand = b;
      model = m;
      year = y;
   }

//Copy Constructor 
Car (const Car& other){
   brand = other.brand;
   model = other.model;
   year =other.year;
}



 void startEngine(){
    cout << "Engine Started for: " << year << " " << brand << model << endl;
 }

 /*
 void accelerate(){
    cout << "Accelerate car" << model << endl;
 }*/

};



//Destructors 

#include <iostream> 
#include <string>

using namespace std;


class Car{

private: 
string brand = "Toyota";
string model = "Carmy";
int year = 2022;
//creating the blueprint ^


public: 
Car (){
    //Nothing here, the defaults already handle it.
    cout << "Destroy" << brand << " " << model << " " << year << endl;
}



//Destructor
~Car(){
}

//Paremterized Constructor 
Car(string b, string m, int y){
    brand = b;
    model = m;
    year = y;
}

Car(const Car & other){
    brand = other.brand;
    model = other.model;
    year =other.year +1;
}   

void startEngine(){
    cout << "Start Enging for:" << "Brand " << brand << " model " << model << "year " << year << endl;
}

//Member function 
void accelerate(){
cout << "Accelerate engine" << "Brand " << brand << " model " << model << "year " << year << endl;
}

};





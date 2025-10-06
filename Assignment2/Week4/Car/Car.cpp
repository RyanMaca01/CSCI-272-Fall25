
#include "header.h"
#include <iostream>
#include <string> 
using namespace std;



int main(){
Car car1;  //Create an object :: what does this do?
Car car2; ("Tesla", "Model X", 2025);
Car car3(car2);


Car* pCar1 = new Car;
Car* pCar2 = new Car ("Testla", "Model Y", 2025);
Car car[20];



car1.startEngine();
car2.startEngine();
car3.startEngine();

pCar1 -> startEngine();
pCar2 -> startEngine();

car[14].startEngine();

//car1.accelerate();



}


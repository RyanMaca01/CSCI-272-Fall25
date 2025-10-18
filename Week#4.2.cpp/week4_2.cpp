#include "car.h"
#include <iostream> 
#include <string>
using namespace std;

int main(){
//Create a carr object 
Car car1;

//parameter
Car car2("Honda", "civic", 2024);

//Copy constructor
Car car3(car2);

//Call memeber function 
car1.startEngine();
car2.startEngine();
car3.startEngine();


car2.accelerate();
car3.accelerate();



}
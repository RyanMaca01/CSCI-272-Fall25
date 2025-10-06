#include "car2.h"


int main(){
    
    Car car1;

    
    Car car2("Tesla", "X", 2022);

    Car car3(car2);
    car1.startEngine();

    car2.startEngine();


    car3.startEngine();

  

    return 0;
}
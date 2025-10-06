#include "car.h"

int main(){
 
car car1;
car car2("Tesla", "X", 2022);
car car3(car2);
car* pcar1 = new car;
car* pcar2 = new car("Tesla", "X", 2022);
car carArray[20];

car1.startEngine();
car2.startEngine();
car3.startEngine();
pcar1->startEngine();
pcar2->startEngine();
carArray[0].startEngine();

delete pcar1;
delete pcar2;


}
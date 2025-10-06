#include <iostream> 
using namespace std;
//We have to define a class name called "car"

class car {

private:
string brand{"Volkswagen"};
string model{"Polo"};
int year {2025};

public: 
car(){

}


car(string b, string m, int y){
brand = b;
model = m;
year = y;
}

car(const car& other){
brand = other.brand;
model = other.model;
year = other.year;
}

void startEngine(){
    cout << "Starting the engine of car{brand:" << brand << "|model:" << model << "}" << std::endl;
}

void accelerate() {
cout << "Accelerating the car {brand:" << brand << "|model:" << model << "}" << std::endl;
}


};
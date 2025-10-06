#include <iostream>
using namespace std;

class Car{
private:
string brand{"Volkswagen"};
string model = "Polo";  

public:
int year{2012}; 
~Car(){
    cout << "Object is destroyed" << std::endl;
}

Car(){
}

Car(string b, string m, int y){
    	brand = b;
    	model = m;
    	year = y;
    }


Car(const Car & other){
    brand = other.brand;
    model = other.model;
    year = other.year + 1; // Increment the year by 1
}


void startEngine() {
cout << "start engine" << "{brand:" << brand << "|model:" << model << "}" << std::endl;
}
 
void accelerate() {
cout << "accelerate engine" << "{brand:" << brand << "|model:" << model << "}" << std::endl;
}

};
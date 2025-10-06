#include <iostream>
using namespace std;
class Car {
private:
    string brand{"Volkswagen"};
    string model="Polo";
    int year {2012};

public:

    void startEngine() {
    cout << "start engine" << std::endl;
    }

    void accelerate() {
     cout << "accelerate engine" << std::endl;
    }
};



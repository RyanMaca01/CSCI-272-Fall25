#include <iostream>
using namespace std;

class MyClass {
private:
    static int count;

public:
    int getCount(){
    return count;
    }

    void setCount(int b){
    count = b;
    }
};


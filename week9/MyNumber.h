/*#include <iostream> 

using namespace std;

//h.file
class MyNumber{
private: 
int value; // interanl stored int; 

public:
// constructor 
MyNumber( int val = 0){
    value = val;
}

//getter to read the store value

int getvalue() const{
    return value;
}


//overload the Minus: -num
// this is not going to change the riginail object 

MyNumber operator-() const{
    return MyNumber(-value);
}

//overload the prefic ++; ++num
// This will change the current object (increments value)

MyNumber operator++(){
    ++value; //this will increase the storeed value by 1 
    return MyNumber(value);
}



};*/
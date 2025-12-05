#include <iostream>
using namespace std;

class Integer{
    private: 
    int value;  //the actual interger value we will wrap
    public:

// constructor 
Integer(int val =0){
    value = val;
}


//getter to read the sorted values 

int getValue() const{
    return value;
}

//overload the binary + opeartor to add two Integer objects
// eX. INTGER C= A+B

Integer operator+ (const Integer& other) const{
return Integer (this -> value + other.value);
}

};


int main(){

Integer numb1 (19);
Integer numb2 (20);

//call numb1.opeator +(num2)

Integer sum = numb1 + numb2;

cout << "Numb 1:" << numb1.getValue() << endl;
cout << "Numb 2:" << numb2.getValue() << endl;

cout << "Sum (numb1 + numb2):"  << sum.getValue() << endl;

}
//.h file 
#include <iostream> 
using namespace std;


class Complex{

private: 
double real;
double imaginary; 

public: 
//constructor 
Complex(double re= 0.0, double im = 0.0) 
: real (re), imaginary (im){}

//Getter for real part 
double getReal() const{
    return real;
}

//Getter for imaginary part 
double getImaginary() const{
    return imaginary;
}

//Overloading 
//ab = a *b;
// overload the - opeartor to subrtract two complex numbers
// (a1 +b1 i) -(a2+b2 i) = (a1-b2) +(b1-b2)i
// overloaded- opearator


Complex operator-(const Complex& other) const{
    double newReal = this->real - other.real;
    double newImag = this->imaginary - other.imaginary;
    return Complex(newReal, newImag);
}


};

int main(){

Complex z1(12.0,3.1); //12 + 3.1i
Complex z2(7.77,36.2); // 7.77 +36.2i 

//Calls z1.oerator (-z2)
Complex diff = z1- z2;

cout << "Z1 = " << z1.getReal() << "+" << z1.getImaginary() << "i" << endl;
//output : z1 = 12+3.1i 
cout << "Z2 = " << z2.getReal() << "+" << z2.getImaginary() << "i" << endl;
// output: z2 = 7.77 + 36.2i
cout << "Z1- Z2 = " << diff.getReal() << "+" << diff.getImaginary() << "i " << endl;



}
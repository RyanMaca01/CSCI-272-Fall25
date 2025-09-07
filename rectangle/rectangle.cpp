# include <iostream>
using namespace std;

//Make two functions one for the area and one of the perimeter 

double calcArea(double length, double width){
    return length * width;
}

double calcPer(double length, double width){
    return 2 *(length * width);
}

int main(){
double length, width;
cout << "Enter the length of the rectangle:" << endl;
cin >> length;

cout << "Enter the width of the rectangle:" << endl;
cin >> width;

//Calculate the area and perimeter using the funtions 
double area = calcArea (length, width);
double perimeter = calcPer (length, width);

//Display back: 
cout << "The area of rectangle is: " << area << endl;
cout << "The perimeter of the rectangle is " << perimeter << endl;

}

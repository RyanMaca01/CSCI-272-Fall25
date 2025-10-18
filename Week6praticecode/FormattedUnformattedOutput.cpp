#include <iostream>
#include <string>
using namespace std;


int main(){

double num1 = 3.3232;
char ch = 'R'; 

string strValue = std::to_string(num1);
const char* charPtr = strValue.c_str();

cout << "Double: " << num1 << std::endl;
cout << "char* : "; cout.write(charPtr, 7)<< endl;
cout.write(reinterpret_cast<const char*>(&num1), sizeof(num1));
cout << "\nCharacter Output: "; std::cout.put(ch).put('\n');

}
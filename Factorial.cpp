
#include <iostream>
using namespace std;

//I had to look at the code in the brightspace

int factorial(int n){
    int result = 1; 
for(int i=1; i <= n; i++){
    result *= i;
}
return result;
}
// Mu questions are: Why did we have to use (int n)?, Why did we make the default result equal to one? Is it because we need a postive integer? Also, we did we use the result *=i? 



int main(){

int integer;

cout << "Hello, Please enter a postive integer: " << endl;
cin >> integer;

int result=factorial(integer);

cout << "Here is the Factor of" << integer << "which is " << result << endl;

}

#include <iostream>
#include <sstream>
#include <string>



using namespace std;




//Declare the function

bool isValidPhoneNumber(const string& input);

int main(){
    string input;

    do{
    cout << "Enter a U.S Phone number (e.g. ,800.999.9999): ";
    getline (cin, input);

   if(!isValidPhoneNumber(input)){
    cout << "Invalid Input,try again\n";
   }while(!isValidPhoneNumber(input));
   cout << "Valid input \n";

    }

  


   //Call a validation function

   if (isValidPhoneNumber(input)){
    cout << "Valid! Cool...." << endl;
   }else{
    cout << "Invalid, pplease follow the format" << endl;
   }


}

//function definition 

bool isValidPhoneNumber(const string& input){
    istringstream iss (input);
    char openParen,closeParen,dash;
    int areaCode, firstPart, secondPart;
    if (iss >>openParen >> areaCode >> closeParen >> firstPart >> dash >> secondPart){
        if(openParen =='(' && closeParen == ')' && dash =='-' && areaCode >=100 && firstPart >=100 && firstPart <= 999 && secondPart >=1000){
            return true;
        } 
    }
     return false;
}
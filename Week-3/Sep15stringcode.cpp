#include <iostream>
#include <string> 
#include <cctype> //tolower()/ toupper()
using namespace std;


//Case insenstive comparison 

bool caseInsenstiveCompare(const string& str1, const string& str2){
    if (str1.length() != str2.length()){
        return false;
    }
    for (size_t i =0; i < str1.length();i++){
        if (tolower(str1[i])!= tolower(str2[i])){
            return false;
        }
    }
    return true;
}




int main(){
/*
string firstName;
string lastName;

cout << "First Name: " << endl;
cin >> firstName; // saving user input in first Name variable 

cout << "Last name" << endl;
cin >> lastName; //saving user input in LastName variable 

string fullName =firstName + " " +lastName; // This needs to be in the end 
cout << "Full name: " << fullName << endl;

fullName += "Jr." ; // dont do this because its going to give you name + jr at the end
// but rather fullName=fullName + "jr.";  
 cout << "Full name with suffix: " << fullName << endl;


fullName.insert(0, "Dr.");
//or fullName = "Dr. " +fullName;
cout << "Full name with Prefix: " << fullName << endl;
*/

//example 2
/*
string message = "Hello, World!"; //13 char
int messageLength = message.size();
int messageSize = message.size();
cout << "Lenght: " << messageLength << endl << "size: " << messageSize << endl;

char firstChar = message[0];
char lastChar = message[message.length()-1]; //>> 13-1 12 

cout << "First Char: " << firstChar  << endl << "Last char" << lastChar << endl;*/




//example 3
/*
string str1= "capple";
string str2= "abanana"; 

if(str1 == str2){
    cout << "Both strings are equal!" << endl;
}else if (str1 > str2){
    cout << "Str1 is lexicographically greater than str2." << endl;
}else{
    cout << "Str1 isl exicographically less than str2. " << endl;
}
*/



string str1 = "Hello";
string str2 = "hello";


if(caseInsenstiveCompare (str1,str2)){
    cout << "Strings are case-insentitive equal" << endl;
}else{
    cout << "Strings are NOT case-insentitive equal" << endl;
}






}

// // #include <iostream>
// // #include <sstream> 
// // #include <iomanip>

// // using namespace std;

// // int main(){



// // ostringstream oss; //output string stream object oss 


// // string name = "Alice";
// // int sccore = 95;
// // double gpa = 3.876;



// // //build a message using oss 

// // oss << "Student: " << name << " | Score" << sccore << "| GPA: " << fixed << setprecision(2) << gpa;

// // //convert the stream into a string
// // string message  = oss.str();
// // cout << message << endl;

// // ostringstream oss1;   //create a new object 
// // oss1 << "Test data" << endl;   //new stream

// // cout << message << endl;
// // cout << oss1.str() << endl; // print the string of oss1



// // }


// //second pratice, the way to comment all of the code is commmand A backslash or backspace

// /*
// #include <iostream>
// #include <sstream> 
// #include <iomanip>

// using namespace std;




// int main(){


// string whatever = "1003.5";

// istringstream iss(whatever); //Stream containing 100 & 3.5; 

// int quantity; // integer 0 
// double price; // double 0.00


// iss >> quantity >> price; 
// cout << "Total cost: "  << quantity * price << endl;
// cout << quantity << endl;
// cout << price << endl;





// }*/



// //failed  * clear 
// #include <iostream>
// #include <sstream> 
// using namespace std;

// int main(){


// string data =  "7 ate 9"; // int string int 
// istringstream iss(data); //creating input string stream object named iss 

// int value; // 7,9

// while (iss >> value ) {
//     cout << "Read int: " << value << endl;
// }

// // When a bad token stops the extraction

// if(iss.fail()){
//     cout << "Stream failed. Skipped bad token...." << endl;
//     iss.clear(); //clearing the fail state
//     string bad;
//     iss >> bad;
//     cout << bad;
// }

// //resume reading the next value 

// while(iss >> value){
//     cout << "Read int cont:" << value << endl;
// }



// }


#include <iostream>
#include <sstream> 
using namespace std;

int main(){

string data {"input Test 123 4.7 A"};
istringstream iss(data);

string exString1; 
string exString2; 
int exiInt; 
double exDouble;
char exChar;


iss >> exString1 >> exString2 >> exiInt  >> exDouble >> exChar;
cout  << "The folloing items were extracted from istringstream object: "
<< "\nstring:" << exString1 << "\nstring:" <<  exString2 <<  "\nInt" << exiInt << "\ndouble" << exDouble << "\nexChar" << endl;

long value;
iss >> value;



if(iss.good()){
    cout << "Value is: " << value << endl;
}else{

cout << "\n ISS exploded. Its emplty. EOF. " << endl;

}
}


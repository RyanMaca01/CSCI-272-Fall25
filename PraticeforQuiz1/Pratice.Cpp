#include <iostream> 
#include <vector> 
#include <string>
using namespace std;



int main(){
/*
    int x[6] ={1,2,3,4,5,6};
    int firstElement = x[0];
    int secondElement = x[1];
    int lastelement= x[5];


    int a;
    int *p; 

    p = &a;
    a = 3;

    cout << p << endl;
    cout << &p << endl;
    cout << &a << endl;

    *p = 5; 
    cout  << "a" << endl;*/

// vector 

vector < int > numbers = {1,2,3,4,5};
vector<int>emptyVector;
vector<int>copyVector(numbers);
vector <int> rangeVector(numbers.begin(),numbers.begin()+3);



vector < int > numbers = {1,2,3,4,5};
for ( int num : numbers){
    cout << num << " ";
}

vector < string > fruits {"Apple, your dad"};
fruits.push_back("orange");
fruits.insert(fruits.begin()+1, "Grapes");
fruits.emplace_back("mangos");


vector < int > test = {10, 20, 30 , 40 , 50 };
int firstElement = test.front();
int lastElement = test.back();
int secondElement = test.at(2);

string greeting = "Hello yo";
cout << "String:" << greeting << endl;

char firstChar = greeting[0];


string name;
cout << "Enter your name: " << endl;
cin >> name;




}
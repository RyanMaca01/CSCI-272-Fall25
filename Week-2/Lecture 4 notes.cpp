#include <iostream> 
using namespace std;
#include <vector> 

int main(){
/*
vector<int> numbers= {10,20,30,40,50};

cout << "First element: " << numbers.front() << endl;
cout << "Last element: " << numbers.back() << endl;
cout << "Second element: "<< numbers[1] << endl;
cout << "Third element: " << numbers.at(2) << endl;

//vector modification 

numbers[1] = 35;  //replaces the value of the 25 to 35
numbers.at(2) = 35; //replaces the value of the 20 to 35
numbers.front()=5; //this would make the value of 10 become 5
numbers.back()=5; //this would replace the 50 with 5
numbers.push_back(272); //this would move 272 to become the 6th element and will not affect the 5 other ones 

cout << "\n\n=======After  Modifications======\n\n";

cout << "First element: " << numbers.front() << endl;
cout << "Last element: " << numbers.back() << endl;
cout << "Second element: "<< numbers[1] << endl;
cout << "Third element: " << numbers.at(2) << endl;
//the final output would be 5,35,35,40,50,272
*/

//Example 2

vector <int> numbers;

numbers.reserve(2);
cout <<"First E1 = " << numbers.front() << endl;
cout << "Last E1= " << numbers.back() << endl;

cout << "Reserved: " << endl << "Size = " << numbers.size()<< ",Capcity = " << numbers.capacity() << endl << endl;

numbers.push_back(10);
cout << "After addimg 10: " << endl << "Size = " << numbers.size() << ",Capcity = " << numbers.capacity() << endl;
cout <<"First E1 = " << numbers.front() << endl;
cout << "Last E1= " << numbers.back() << endl;

numbers.push_back(20);
cout << "After addimg 20: " << endl << "Size = " << numbers.size() << ",Capcity = " << numbers.capacity() << endl;
cout <<"First E1 = " << numbers.front() << endl;
cout << "Last E1= " << numbers.back() << endl;


numbers.push_back(40);
cout << "After addimg 40: " << endl << "Size = " << numbers.size() << ",Capcity = " << numbers.capacity() << endl;
cout <<"First E1 = " << numbers.front() << endl;
cout << "Last E1= " << numbers.back() << endl;

//when you are addiing the reseverce, you are purchase two sets
//every time you put an reserve number whenere size is increasting it is increasing the saem more spaces 
//what every the reserve would add by add itself: resever is 5 but i add a six element, the new resever would be 10
// pre allcoatding for the elements that would come 
// we use reresver for inefficanly 













}
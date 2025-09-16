#include <iostream>
#include <vector> 
using namespace std;

int main (){
    /*
vector<int>data={1,2,3};
data.push_back(12);
cout << data[3] << endl;
cout << data[data.size()-1] << endl;*/


vector<int>numbers;
numbers.push_back(0); //insert elements into vector
for (int i =1 ; i <= 10; i++){
    numbers.push_back(i);
}

//for (int number:numbers )
//cout << number << endl;

//iterators: Are like specail functions that point out important locations beging and end

for (auto it = numbers.begin(); it != numbers.end(); it++){
  //  cout << it << endl; you can't print the itterator itself 

  cout << &it << endl;
  cout << *it << endl;
}

auto it = numbers.begin();
cout << *(it+5);

}
#include <iostream> 
#include <vector>
#include <string>
using namespace std; 

int main(){

vector <int> numbers{};
numbers.push_back(2);
numbers.push_back(3);
numbers.insert(numbers.begin()+1, 3);
numbers.emplace_back(4);

int fristElement = numbers.front();
numbers.size();
numbers.empty();

for (int nums: numbers){
    cout << nums << " " << endl;
}


vector<string>list{};
list.push_back("Apples");
list.push_back("Chiken");

for (string eh :list ){
    cout << eh << " " << endl;
}









}
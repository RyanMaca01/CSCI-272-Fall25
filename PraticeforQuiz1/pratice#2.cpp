#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

vector<string> list;
list.push_back  ("Apple");
list.push_back  ("Chip");
list.push_back  ("Yogurt");
list.push_back  ("chicken");
list.push_back  ("rice");
list.push_back  ("juice");
list.insert(list.begin()+2, "Grapes");

list.pop_back();


for (string item : list ){
    cout << "Your list" << list << endl;
}



}
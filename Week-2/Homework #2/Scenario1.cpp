#include <iostream> 
#include <vector>
using namespace std;

int main(){

vector<string>menu;
//menu.push_back(5); we should not do this because we are using strings/ need names  
//menu.insert(menu.second +1 )
//menu.erase(4);
/*
for (int num : numbers){
    cout << num << " ";
}*/


//we need to add the 5 dishes like this using the push back 
menu.push_back("Hot Chicken");
menu.push_back("Pizza");
menu.push_back("Fries");
menu.push_back("Soup");
menu.push_back("Sandwhich");

 // Insert a new dish at the 2nd position (index 1)
menu.insert(menu.begin()+1,"Salad");

 // Remove the 4th dish (index 3 after insertion)
menu.erase(menu.begin() + 3);

// Print final menu using range-based for loop
for (const string& dish : menu) {
 cout << dish << endl;
}


}
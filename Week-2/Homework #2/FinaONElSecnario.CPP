#include <iostream> 
#include <vector>
using namespace std;

int main(){


// We need to start of by calling our vector, and we are using string in order to 
// give the names of the dishes, and there is no numberial values give
 
vector<string>menu;

//we need to add and create the 5 dishes like this using the push back 
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
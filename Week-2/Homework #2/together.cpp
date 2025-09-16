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



#include <iostream> 
#include <vector> 
using namespace std;

//we were told to have sperate functions:

//This function will calculate the average of all of the IDS
double getAverage(const vector<int>& ids){
//we need to add the ids to then end of onst vector<int>&, because 
// it allowed to give the name of the paremeter and give a defintion to the function
    double sum = 0;
 for (int id : ids) {
    sum += id;
 }
//I asked CHAT.GPT for the reason why we used the for function and why we need to format it as for (int id : ids) ?
 // For the For function I had to use AI to help me write this part of the code.
 // Purpose for the For function in this case is to add each student ID in the list, and each time, add it to the sum.
 // Also, this is knowm as the range-based for loop, which makes it easier for the use and gets ride 
 // of using  (size_t i = 0; i < ids.size(); i++). 

 return sum/ids.size();
}

//This function will calculate the highest ID value
int getHighest(const vector<int>& ids){
int maxVal = ids[0];
for (int id : ids) {
    if (id > maxVal){
        maxVal = id;
    }
}

//The same reason would apply why use the (int id : ids) in this function as well to save time 
// from writing the (size_t i = 0; i < ids.size(); i++).
// According to AI, "it allows us to quickly check each ID against
// the current maximum and update maxVal if we find a larger number."
return maxVal;
}



int main(){
// We need to make our vector, to which I gave it the name ids 
// Then we had the opinion to add the values of john jay ids, to which we added the 
// the values inside of the ids 

vector<int>ids{9999,8888,7777,6666,5555,4444,2222,1111};
//I wanted to use something we learned in class, to show we can apply things 
//we learned in class into this problem. 
ids.push_back(0000);

//We gave the names of the functions 
double average = getAverage(ids);
int Highest = getHighest(ids);


//Here we print out the values back
cout << "The Average student ID is" << average << endl;
cout << "The highest student ID is " << Highest << endl;
}
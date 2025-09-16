#include <iostream> 
#include <vector> 
using namespace std;


//we used ai give me: promt, explain the concepts 
// I used ai for this part 
double getAverage(const vector<int>& ids){
//ids+each other /number of ids = result 
//cout << result << endl;

int sum = 0;
for (int id :ids){
    sum +=id;
}
return static_cast<double>(sum) / ids.size();
}


// I used ai for this part 
int getHighest(const vector<int>& ids){
//check for the higlest value 
int Highest = ids[0];
for (int id : ids){
    if (id > Highest){
        Highest = id;
    }
}
}

int main(){
vector<int>IDS;

for(int i= 0; i < 10 ; i++){
int id;
cout << "Please enter your John Jay student ID:" << endl;
cin >> id;
IDS.push_back(id); // why is this need 
}

double average = getAverage(IDS);
int Highest =  getHighest(IDS);

cout << "The average student ID is" << average << endl;
cout << "The highest student ID is " << Highest << endl;


}
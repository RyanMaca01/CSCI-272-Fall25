#include <iostream> 
#include <fstream>       //File processing
#include <cstdlib>       //For exist()

using namespace std;


int main(){
//creates an  ofstream objecte named outClientFile, file name= client.txt


/* ofstream outClientFile("client.txt",ios::out);  /change ths  */ 

ofstream outClientFile("client.txt",ios::app);

//check if file exist
//if not, show a warning 
if (!outClientFile){
cerr << "File could not be opened.\n";
exit(EXIT_FAILURE);
}
//User input 
cout << "Enter account number, name, and balace. [Space seperated] \n" <<  "Sample: 1001 Avijit 100.20 \n" << "EBTER ctrl + D in Mac/linux to end.\n";


//setup the variable and take the input 
int account; 
string name;
double balance;


//input
while (true){
    if (cin >> account >> name >> balance){
        outClientFile << account << ' ' << name << ' ' << balance << endl;
        cout << "?";
    } else if (cin.eof()){
        //end of file input marker
        cout << "\n End of file reached. Data Saved. \n";
        break;
    }else{
      // intput error (missing or inacvlid errors)
      cerr << "Invalid input format, p[ease re-enter (e.g., 100 A;ex 50.28): \n";
      cin. clear(); //clear the failbit
      cin. ignore(1000, '\n');//discards the invalid input 
    }
    
}

outClientFile.close(); //Close the file. saved.  control z 


}
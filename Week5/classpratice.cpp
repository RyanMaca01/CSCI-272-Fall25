#include <iostream>
#include <iomanip>
using namespace std;

#include <iostream>
using namespace std;


class Card{
public: 
int CardNumber;
string CardHolder;

};


//type of allias CardPtr to for card*
typedef Card* CardPtr; //cardPTR is an lias of Card*
typedef double DB; // an alias of double, DB is an alias of double 
typedef int Roy; 



int main(){
// create a new card ohbject 
Card myCard;

myCard.CardNumber = 12345;
myCard.CardHolder = "Alice";

CardPtr PtrToCard = &myCard;


cout << "Here is card numnber:" << PtrToCard -> CardNumber << endl;
cout << "Here is the card holder: " << PtrToCard ->CardHolder << endl;


}



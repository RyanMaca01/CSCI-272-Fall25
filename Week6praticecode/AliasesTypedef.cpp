#include <iostream>
using namespace std;


class Card{
public: 
int cardNum;
string cardHolder;
};

typedef Card* CardPtr;

int main(){

Card mycard;
mycard.cardNum = 2005;
mycard.cardHolder = "Ryan";

CardPtr ptrToCard = &mycard;
cout << "Card Number: " << ptrToCard->cardNum << endl;
cout << "Card Holder: " << ptrToCard->cardHolder << endl;




}

#include"Card.h"
Card::Card(){}
Card::~Card(){}
void Card:: printCard(){
	if(suit<4){
		if(suit==0)
			cout<<"\xE2\x99\xA3";
		else if(suit==1)
			cout<<"\xE2\x99\xA6";
		else if(suit==2)
			cout<<"\xE2\x99\xA5";
		else if(suit==3)
			cout<<"\xE2\x99\xA0";
		cout<<face;
	}
	else
		cout<<"joker";
}
Card Card:: setCard(Suit a,int b){
	suit=a;
	face=b;
	return (*this);
}
void resetCard(Card card[]){
	for(int i=0;i<52;i++){
		card[i].face=i%13+1;
		if(i<13)
			card[i].suit=club;
		if(i>=13&&i<26)
			card[i].suit=diamond;
		if(i>=26&&i<39)
			card[i].suit=heart;
		if(i>=39&&i<52)
			card[i].suit=spade;
	}
	for(int i=52;i<54;i++){
		card[i].suit=joker;
		card[i].face=14;
	}
}
void shuffle(Card card[]){
	int rnd;
	Card temp;
	for(int i=0;i<500;i++){
	rnd=rand()%54;
		temp=card[i%54];
		card[i%54]=card[rnd];
		card[rnd]=temp;
	}
}

Player:: Player(){
    hand=new Card[15];
    for (int i=0;i<15;i++)
	    hand[i].face=-1;
}
Player:: ~Player(){
}
void Player:: showHand(){
    for(int i=0;i<15;i++){
        if(hand[i].face>0&&hand[i].face<=14){
            if(hand[i].suit<4){
                if(hand[i].suit==0)
                    cout<<"\xE2\x99\xA3";
                else if(hand[i].suit==1)
                    cout<<"\xE2\x99\xA6";
                else if(hand[i].suit==2)
                    cout<<"\xE2\x99\xA5";
                else if(hand[i].suit==3)
                    cout<<"\xE2\x99\xA0";
                cout<<hand[i].face;
            }
            else
                cout<<"\xF0\x9F\x83\x8F";
            cout<<endl;
        }

    }

}
void Player:: setID(int id){
	ID=id;	
}
void Player :: showID(){
	cout<<ID;	
}
void deal(Card card[],Player p1,Player p2){
    for(int i=0;i<27;i++){
        p1.hand[i]=card[i];
        p2.hand[i]=card[i+27];
        }
}
void deal(Card card[],Player p1,Player p2,Player p3){
    for(int i=0;i<18;i++){
         p1.hand[i]=card[i];
         p2.hand[i]=card[i+18];
         p3.hand[i]=card[i+36];
    }
}
void deal(Card card[],Player p1,Player p2,Player p3,Player p4){
    for(int i=0;i<13;i++){
         p1.hand[i]=card[i];
         p2.hand[i]=card[i+13];
         p3.hand[i]=card[i+26];
         p4.hand[i]=card[i+39];
    }
    p1.hand[13]=card[52];
    p2.hand[13]=card[53];
} 
int Player:: getLength(){
	return length;
}
void Player:: setLength(){
	length=0;
	for(int i=0;i<15;i++){
		if(hand[i].face==-1)
			;
		else
			length++;
	}
}
int Player:: chooseX(int i){
	if(ID==2||ID==4)
		return card_X_Position[i]+3;
	else if(ID==3)
		return card_X_Position[i]+4;
}
int Player:: chooseY(int i){
	if(ID==2||ID==4)
		return card_Y_Position[i]+2;
	else if(ID==3)
		return card_Y_Position[i]+3;
}
int Player:: getID(){return ID;}

void Player:: moveChoose(int choose){
	move(chooseY(choose),chooseX(choose));
}

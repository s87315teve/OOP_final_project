#include"Card.h"
#include"Joker.h"
#include"card_UI.h"
using namespace std;
int main(){
	srand(time(NULL));
	Card card[54];
	resetCard(card);
	shuffle(card);
	Player player[4];
	deal(card,player[0],player[1],player[2],player[3]);
	for(int i=0;i<4;i++){
		player[i].setID(i+1);
		throwCard(player[i]);
		cout<<"---player"<<i+1<<"---"<<endl;
		player[i].showHand();
	}
	pickCard_Turn(player);
	for(int i=0;i<4;i++){
		cout<<"---player";
		player[i].showID();
		cout<<"---"<<endl;
		player[i].showHand();
	}
	return 0;
}

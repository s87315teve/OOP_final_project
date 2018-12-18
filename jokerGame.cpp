#include"Card.h"
#include"Joker.h"
#include"card_UI.h"
using namespace std;
void jokerGame(){
	int p1_X_Position[15]={12,21,30,39,48,57,66,75,16,25,34,43,52,61,70};
	int p1_Y_Position[15]={21,21,21,21,21,21,21,21,15,15,15,15,15,15,15};
	int p2_X_Position[15]={1,1,1,1,1,4,4,4,4,7,7,7,10,10,13};
	int p2_Y_Position[15]={1,6,11,16,21,4,9,14,19,7,12,17,10,15,13};
	int p3_X_Position[15]={12,21,30,39,48,57,66,75,16,25,34,43,52,61,70};
	int p3_Y_Position[15]={1,1,1,1,1,1,1,1,4,4,4,4,4,4,4};
	int p4_X_Position[15]={88,88,88,88,88,85,85,85,85,82,82,82,79,79,76};
	int p4_Y_Position[15]={1,6,11,16,21,4,9,14,19,7,12,17,10,15,13};
	setlocale(LC_CTYPE, "");
	int x=1,y=1;
	char ch;
	srand(time(NULL));
	Card card[54];
	resetCard(card);
	shuffle(card);
	Player player[4];
	for(int i=0;i<4;i++)
		player[i].setID(i+1);
	deal(card,player[0],player[1],player[2],player[3]);
	throwCard(player[0]);
	throwCard(player[1]);
	throwCard(player[2]);
	throwCard(player[3]);
	initial();
	player[0].setPosition(p1_Y_Position,p1_X_Position);
	player[1].setPosition(p2_Y_Position,p2_X_Position);
	player[2].setPosition(p3_Y_Position,p3_X_Position);
	player[3].setPosition(p4_Y_Position,p4_X_Position);
	print_Position(player[0]);
	print_Position(player[1]);
	print_Position(player[2]);
	print_Position(player[3]);
	player[0].setLength();
	player[1].setLength();
	player[2].setLength();
	player[3].setLength();
	mvaddstr(10,14,"(ˊ\u30FB\u03C9\u30FBˋ)   Press enter to start");
	mvaddstr(14,20,"林昱澤");
	mvaddstr(14,70,"雷宗翰");
	mvaddstr(8,45,"沈政賢");

	move(0,0);
	do {		/* 以無限迴圈不斷等待輸入 */


		ch=getch();                      /* 等待自鍵盤輸入字元 */
		switch(ch) {                     /* 判斷輸入字元為何 */

			case '\r':     		/* 判斷是否 ENTER 鍵被按下 */
				while(1){
					int win=0;
					win=pickCard_Turn(player);
					if(win==1)
						break;
				}
				return;
				break;
			default:
				break;
		}
	} while (1);
	//return 0;
}

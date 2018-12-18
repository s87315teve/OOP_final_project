#include"Joker.h"
int choose=0;
void throwCard (Player p1){
	for(int i=0;i<14;i++){
		for(int j=i+1;j<15;j++){
			if((p1.hand[i]).face==(p1.hand[j]).face&&(p1.hand[i]).suit!=joker){
				(p1.hand[i]).face=-1;
				(p1.hand[j]).face=-1;
			}

		}
	}
	sort_Card(p1);
}
void pickCard(Player p1,Player p2){
	choose=0;
	int rnd,judge;
	bool enter=false;
	char ch;
	p1.setLength();
	p2.setLength();
	if (p1.getID()!=1){ 
		while(1){
			judge=-1;
			for(int i=0;i<15;i++)
				if((p1.hand[i]).face!=-1)
					judge=1;
			for(int i=0;i<15;i++)
				if((p2.hand[i]).face!=-1)
					judge=1;
			if(judge==-1)
				break;
			rnd=rand()%15;
			if((p2.hand[rnd]).face!=-1){
				p1.hand[14]=p2.hand[rnd];
				(p2.hand[rnd]).face=-1;
				throwCard(p1);
				sort_Card(p2);
				p1.setLength();
				p2.setLength();
				break;
			}
		}
	}
	else  {
		judge=-1;
		for(int i=0;i<15;i++)
			if((p1.hand[i]).face!=-1)
				judge=1;
		for(int i=0;i<15;i++)
			if((p2.hand[i]).face!=-1)
				judge=1;
		if(judge==-1)
			return;
		do {		/* 以無限迴圈不斷等待輸入 */
			if(choose==0&&p2.getID()==2)
				move(1+2,1+3);
			else if(choose==0&&p2.getID()==3)
				move(1+3,12+4);
			else if(choose==0&&p2.getID()==4)
				move(1+2,88+3);
			else
				p2.moveChoose(choose); 
			ch=getch();                      /* 等待自鍵盤輸入字元 */
			switch(ch) {                     /* 判斷輸入字元為何 */
				case 'w': 
					if(choose==0)
						;
					else 
						choose--;
					break;
				case 's': 
					if(choose==p2.getLength()-1)
						;
					else
						choose++;
					break;
				case '\r':                    /* 判斷是否 ENTER 鍵被按下 */
					enter=true;
					break;
				default:
					break;
			}
			if (enter==true)
				break;
		} while (1);
		if(enter==true){
			p1.hand[14]=p2.hand[choose];
			(p2.hand[choose]).face=-1;
			throwCard(p1);
			sort_Card(p2);
			p1.setLength();
			p2.setLength();
		}
	}
}

void sort_Card(Player p1){
	Card tempCard;
	for(int i=0;i<14;i++)
		for(int j=i+1;j<15;j++){
			if((p1.hand[i]).face==-1&&(p1.hand[j]).face!=-1)	{
				tempCard=p1.hand[i];
				p1.hand[i]=p1.hand[j];
				p1.hand[j]=tempCard;
			}
		}
}
void judgement_And_Turn(Player player[]){
	Player tempPlayer;
	tempPlayer=player[0];
	for(int i=0;i<3;i++)
		player[i]=player[i+1];
	player[3]=tempPlayer;
	int count=0;
	for(int j=0;j<3;j++){
		for(int i=0;i<3;i++){
			sort_Card(player[i]);
			if ((player[i].hand[0]).face==-1){
				tempPlayer=player[i];
				player[i]=player[i+1];
				player[i+1]=tempPlayer;
			}
		}
	}
}
void sort_Player(Player player[]){
	Player tempPlayer;
	for(int i=0;i<3;i++){
		sort_Card(player[i]);
		if ((player[i].hand[0]).face==-1){
			tempPlayer=player[i];
			player[i]=player[i+1];
			player[i+1]=tempPlayer;
		}
	}

}
int pickCard_Turn(Player player[]){
	int cnt;
	while(1){
		usleep(500000);
		refresh();
		cnt=0;
		int temp=0;
		for(int i=0;i<4;i++)
			if ((player[i].hand[0]).face==-1)
				cnt++;
		if (cnt==3){
			sort_Player(player);
			if(player[0].ID==2){
			move(10,12);
				printw("林昱澤 is loser");
				refresh();
				usleep(3000000);
				return 1;
			}
		 	else if(player[0].ID==3){
			move(10,12);
				printw("沈政賢 is loser");
				refresh();
				usleep(3000000);
				return 1;
			}
			else if(player[0].ID==4){
			move(10,12);
				printw("雷宗翰 is loser");
				refresh();
				usleep(3000000);
				return 1;
			}
			else if(player[0].ID==1){
			move(10,12);
				printw("我輸惹QAQ");
				refresh();
				usleep(3000000);
				return 0;
			}
			break;
		}
		else{
			clear();
			print_Position(player[0]);
			print_Position(player[1]);
			print_Position(player[2]);
			print_Position(player[3]);
			pickCard(player[0],player[1]);
			clear();
			print_Position(player[0]);
			print_Position(player[1]);
			print_Position(player[2]);
			print_Position(player[3]);
			judgement_And_Turn(player);
			//if(temp==1)
			//	break;
		}
	}
}


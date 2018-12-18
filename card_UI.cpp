#include"card_UI.h"

#define pattern0 "\xE2\x99\xA3"
#define pattern1 "\xE2\x99\xA6"
#define pattern2 "\xE2\x99\xA5"
#define pattern3 "\xE2\x99\xA0"
#define pattern4 "\xF0\x9F\x83\x8F"
void initial()                       /* 自定開啟 curses 函式 */
{
	initscr();
	cbreak();
	nonl();
	noecho();
	intrflush(stdscr,FALSE);
	keypad(stdscr,TRUE);
	refresh();
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, '*' , '*');		/* 0, 0 gives default characters 
						 * for the vertical and horizontal
						 * 					 * lines			*/
	//mvaddch(starty+2,startx+2,'C');
	//mvaddch(starty+2,startx+3,'A');
	//mvaddch(starty+2,startx+4,'R');
	//mvaddch(starty+2,startx+5,'D');
	//wrefresh(local_win);		/* Show that box 		*/
	move(0,0);
	return local_win;
}
void printBox(int height,int width,int y,int x){
	mvaddstr(y,x,"\u250C");
	mvaddstr(y,x+width-1,"\u2510");
	mvaddstr(y+height-1,x+width-1,"\u2518");
	mvaddstr(y+height-1,x,"\u2514");

	for(int i=1;i<width-1;i++)
		mvaddstr(y,x+i,"\u2500");
	for(int i=1;i<width-1;i++)
		mvaddstr(y+height-1,x+i,"\u2500");
	for(int i=1;i<height-1;i++)
		mvaddstr(y+i,x,"\u2502");
	for(int i=1;i<height-1;i++)
		mvaddstr(y+i,x+width-1,"\u2502");


}
void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * 	 * result of erasing the window. It will leave it's four corners 
	 * 	 	 * and so an ugly remnant of window. 
	 * 	 	 	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 	 * 1. win: the window on which to operate
	 * 	 * 2. ls: character to be used for the left side of the window 
	 * 	 * 3. rs: character to be used for the right side of the window 
	 * 	 * 4. ts: character to be used for the top side of the window 
	 * 	 * 5. bs: character to be used for the bottom side of the window 
	 * 	 * 6. tl: character to be used for the top left corner of the window 
	 * 	 * 7. tr: character to be used for the top right corner of the window 
	 * 	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 	 * 9. br: character to be used for the bottom right corner of the window
	 * 	 	 	 	 	 	 	 	 	 	 */
	wrefresh(local_win);
	delwin(local_win);
}
void print_Position(Player player){
	char a[3];
	if(player.ID==1){
		for(int i=0;i<15;i++){
			sprintf(a,"%d",(player.hand[i]).face);
			if( (player.hand[i]).face==-1)
				;
			else{
				printBox( 5, 8, player.card_Y_Position[i],player.card_X_Position[i]);
				if((player.hand[i]).face>0&&(player.hand[i]).face<=14){
					if((player.hand[i]).suit<4){
						if((player.hand[i]).suit==0)
							mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i]+3,pattern0);
						else if((player.hand[i]).suit==1)
							mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i]+3,pattern1);
						else if((player.hand[i]).suit==2)
							mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i]+3,pattern2);
						else if((player.hand[i]).suit==3)
							mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i]+3,pattern3);
						mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i]+4,a);
					}
					else
						mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i]+1,"JOKER");
				}

			}
		}
	}
	else 
		print_Other_Position(player);

}

void Player:: setPosition(int y[],int x[]){
	for(int i=0;i<15;i++){
		card_Y_Position[i]=y[i]; 
		card_X_Position[i]=x[i];
	}
}

void print_Other_Position(Player player){
	for(int i=0;i<15;i++){
		if( (player.hand[i]).face==-1)
			;
		else{
			if(player.ID==3){
				printBox( 5, 8, player.card_Y_Position[i],player.card_X_Position[i]);
				mvaddstr(player.card_Y_Position[i]+1,player.card_X_Position[i]+1,"      ");
				mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i]+1,"      ");
				mvaddstr(player.card_Y_Position[i]+3,player.card_X_Position[i]+1,"      ");
			}
			else{
				printBox( 4, 6, player.card_Y_Position[i],player.card_X_Position[i]);
				mvaddstr(player.card_Y_Position[i]+1,player.card_X_Position[i]+1,"    ");
				mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i]+1,"    ");
			}
		}

	}
}
void destroy_Card(Player player){
	for(int i=0;i<15;i++){
		if( (player.hand[i]).face==-1)
			;
		else{
			if(player.ID==3|player.ID==1){
				mvaddstr(player.card_Y_Position[i],player.card_X_Position[i],"        ");
				mvaddstr(player.card_Y_Position[i]+1,player.card_X_Position[i],"        ");
				mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i],"        ");
				mvaddstr(player.card_Y_Position[i]+3,player.card_X_Position[i],"        ");
				mvaddstr(player.card_Y_Position[i]+4,player.card_X_Position[i],"        ");
			}
			else{
				mvaddstr(player.card_Y_Position[i],player.card_X_Position[i],"      ");
				mvaddstr(player.card_Y_Position[i]+1,player.card_X_Position[i],"      ");
				mvaddstr(player.card_Y_Position[i]+2,player.card_X_Position[i],"      ");
				mvaddstr(player.card_Y_Position[i]+3,player.card_X_Position[i],"      ");
			}
		}

	}
	
	
}

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ncurses.h>
#include"map.cpp"
using namespace std;
void initial();                       /* 自定開啟 curses 函式 */
int main(int argc,char *argv[]){
	setlocale(LC_CTYPE, "");
	initial();
	char ch;
	int x=0,y=0;
	ifstream start("kaori.txt");
	string screen;
	move(0,0);
	while(getline(start,screen,'\n')){
		printw("%s\n",screen.c_str());
	}
	start.close();
	mvaddstr(10,68,"\u2192");
	move(0,0);
	int yes=1;
	do {                              /* 以無限迴圈不斷等待輸入 */
		ch=getch();                      /* 等待自鍵盤輸入字元 */
		switch(ch) {                     /* 判斷輸入字元為何 */

			case 'w': 
				//--y;             /* 判斷是否"↑"鍵被按下 */
				mvaddch(11,68,' ');
				mvaddstr(10,68,"\u2192");
				yes=1;
				break;
			case 's': 
				//++y;           /* 判斷是否"↓"鍵被按下 */
				mvaddch(10,68,' ');
				mvaddstr(11,68,"\u2192");
				yes=0;
				break;
			case '\r':                    /* 判斷是否 ENTER 鍵被按下 */
				  clear();
				  if(yes)
					  map();

				  else{
					clear();
					  exit(1);
				  }
				  //	       x=0;
				  break;
			case 27: endwin();            /* 判斷是否[ESC]鍵被按下 */
				 exit(1);             /* 結束 curses 模式 */
				 /* 結束此程式
				  *                                   * */
			default:
				 //	 addch(ch);           /* 如果不是特殊字元, 將此字元印出 */
				 //	 x++;
				 break;
		}
		move(y,x);                      /* 移動游標至現在位置 */
	} while (1);

	return 0;
}





#include<ncurses.h>                  /* 引進 curses.h, 並自動引進 stdio.h */
#include<cstdlib>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<unistd.h>
#define StartX  1                    /* 決定游標初始位置 */
#define StartY  1
using namespace std;
class lock
{
	private:
		bool locked;
	public:
		lock(){locked=true;}
		void openlock(){locked=false;}
		bool islock(){return locked;}
};

class key
{

};
class lock1:public lock
{
	private:
		int key[4];
	public:
		lock1()
			:lock()
		{
			for(int i=0;i<4;i++)
			{
				key[i]=0;
			}
		}
		void open(int y,int x,char ch)
		{
			if(y==3&&x==22)
			{
				addch(ch);		 /* 如果不是特殊字元, 將此字元印出 */
				if(ch=='1')
				{
					key[0]=1;
				}
				else
					key[0]=0;
			}
			else if(y==3&&x==23)
			{
				addch(ch);		 /* 如果不是特殊字元, 將此字元印出 */
				if(ch=='4')
					key[1]=1;
				else
					key[1]=0;
			}
			else if(y==3&&x==24)
			{
				addch(ch);		 /* 如果不是特殊字元, 將此字元印出 */
				if(ch=='2')
					key[2]=1;
				else
					key[2]=0;
			}
			else if(y==3&&x==25)
			{
				addch(ch);		 /* 如果不是特殊字元, 將此字元印出 */
				if(ch=='2')
					key[3]=1;
				else
					key[3]=0;
			}
			if(key[0]==1&&key[1]==1&&key[2]==1&&key[3]==1)
			{
				openlock();
			}
		}

};

class lock2: public lock
{
	private:
		int key[27];
		int ans[27];
	public:
		lock2()
			:lock()
		{
			for(int i=0;i<27;i++)
			{
				key[i]=2;
			}
			ans[0]=ans[2]=ans[6]=ans[8]=ans[9]=ans[11]=ans[14]=ans[17]=ans[18]=ans[20]=ans[22]=ans[24]=ans[26]=0;
			ans[1]=ans[3]=ans[4]=ans[5]=ans[7]=ans[10]=ans[12]=ans[13]=ans[15]=ans[16]=ans[19]=ans[21]=ans[23]=ans[25]=1;
		}
		void open(int y,int x)
		{
			if(y==10&&x==6)
			{
				if(key[0]==0)
				{
					mvaddch(y,x,'L');
					key[0]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[0]=0;
				}
			}
			else if(y==10&&x==6+2)
			{
				if(key[1]==0)
				{
					mvaddch(y,x,'L');
					key[1]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[1]=0;
				}
			}
			else if(y==10&&x==6+6)
			{
				if(key[2]==0)
				{
					mvaddch(y,x,'L');
					key[2]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[2]=0;
				}
			}
			else if(y==10&&x==6+10)
			{
				if(key[3]==0)
				{
					mvaddch(y,x,'L');
					key[3]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[3]=0;
				}
			}
			else if(y==10+2&&x==6)
			{
				if(key[4]==0)
				{
					mvaddch(y,x,'L');
					key[4]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[4]=0;
				}
			}
			else if(y==10+2&&x==6+2)
			{
				if(key[5]==0)
				{
					mvaddch(y,x,'L');
					key[5]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[5]=0;
				}
			}
			else if(y==10+2&&x==6+4)
			{
				if(key[6]==0)
				{
					mvaddch(y,x,'L');
					key[6]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[6]=0;
				}
			}
			else if(y==10+2&&x==6+6)
			{
				if(key[7]==0)
				{
					mvaddch(y,x,'L');
					key[7]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[7]=0;
				}
			}
			else if(y==10+2&&x==6+8)
			{
				if(key[8]==0)
				{
					mvaddch(y,x,'L');
					key[8]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[8]=0;
				}
			}
			else if(y==10+2&&x==6+10)
			{
				if(key[9]==0)
				{
					mvaddch(y,x,'L');
					key[9]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[9]=0;
				}
			}
			else if(y==10+4&&x==6+4)
			{
				if(key[10]==0)
				{
					mvaddch(y,x,'L');
					key[10]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[10]=0;
				}
			}
			else if(y==10+4&&x==6+6)
			{
				if(key[11]==0)
				{
					mvaddch(y,x,'L');
					key[11]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[11]=0;
				}
			}
			else if(y==10+4&&x==6+10)
			{
				if(key[12]==0)
				{
					mvaddch(y,x,'L');
					key[12]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[12]=0;
				}
			}
			else if(y==10+6&&x==6)
			{
				if(key[13]==0)
				{
					mvaddch(y,x,'L');
					key[13]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[13]=0;
				}
			}
			else if(y==10+6&&x==6+4)
			{
				if(key[14]==0)
				{
					mvaddch(y,x,'L');
					key[14]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[14]=0;
				}
			}
			else if(y==10+6&&x==6+6)
			{
				if(key[15]==0)
				{
					mvaddch(y,x,'L');
					key[15]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[15]=0;
				}
			}
			else if(y==10+6&&x==6+8)
			{
				if(key[16]==0)
				{
					mvaddch(y,x,'L');
					key[16]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[16]=0;
				}
			}
			else if(y==10+6&&x==6+10)
			{
				if(key[17]==0)
				{
					mvaddch(y,x,'L');
					key[17]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[17]=0;
				}
			}
			else if(y==10+8&&x==6)
			{
				if(key[18]==0)
				{
					mvaddch(y,x,'L');
					key[18]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[18]=0;
				}
			}
			else if(y==10+8&&x==6+2)
			{
				if(key[19]==0)
				{
					mvaddch(y,x,'L');
					key[19]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[19]=0;
				}
			}
			else if(y==10+8&&x==6+4)
			{
				if(key[20]==0)
				{
					mvaddch(y,x,'L');
					key[20]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[20]=0;
				}
			}
			else if(y==10+8&&x==6+6)
			{
				if(key[21]==0)
				{
					mvaddch(y,x,'L');
					key[21]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[21]=0;
				}
			}
			else if(y==10+8&&x==6+8)
			{
				if(key[22]==0)
				{
					mvaddch(y,x,'L');
					key[22]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[22]=0;
				}
			}
			else if(y==10+10&&x==6)
			{
				if(key[23]==0)
				{
					mvaddch(y,x,'L');
					key[23]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[23]=0;
				}
			}
			else if(y==10+10&&x==6+6)
			{
				if(key[24]==0)
				{
					mvaddch(y,x,'L');
					key[24]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[24]=0;
				}
			}
			else if(y==10+10&&x==6+8)
			{
				if(key[25]==0)
				{
					mvaddch(y,x,'L');
					key[25]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[25]=0;
				}
			}
			else if(y==10+10&&x==6+10)
			{
				if(key[26]==0)
				{
					mvaddch(y,x,'L');
					key[26]=1;
				}
				else
				{
					mvaddch(y,x,'P');
					key[26]=0;
				}
			}
			if(isopen())
				openlock();

		}
		bool isopen()
		{
			for(int i=0;i<27;i++)
			{		
				if(key[i]!=ans[i])
					return false;
			}
			return true;
		}
};

class lock3:public lock
{
	private:
		int form[81];
		int check[81];
		bool gameover;
		bool win;
		bool checkans()
		{
			for(int i=0;i<81;i++)
			{
				if(check[i]!=form[i])
					return false;
			}
			return true;
		}
	public:
		lock3()
			:lock()
		{
			int copy[81]={1,1,1,1,-1,1,1,1,1,2,-1,1,2,3,4,3,-1,1,-1,2,1,1,-1,-1,-1,2,1,1,1,7,1,2,3,2,1,7,1,1,1,7,7,7,7,7,7,1,-1,1,7,7,7,7,1,1,2,2,2,7,7,7,7,1,-1,1,-1,1,7,7,7,7,1,1,1,1,1,7,7,7,7,7,7};
			for(int i=0;i<81;i++)
			{
				form[i]=copy[i];
			}
			for(int i=0;i<81;i++)
			{
				check[i]=-1;
			}
			gameover=false;
			win=false;
		}
		bool getgame(){return gameover;}
		bool getwin(){return win;}
		void reset(){gameover=false;}
		void open(int y,int x)
		{
			if(form[(y-5)*9+(x-4)-1]==1)
			{
				mvaddch(y,x,'1');
				check[(y-5)*9+(x-4)-1]=1;
				move(y,x);
			}
			else if(form[(y-5)*9+(x-4)-1]==2)
			{
				mvaddch(y,x,'2');
				check[(y-5)*9+(x-4)-1]=2;
				move(y,x);
			}
			else if(form[(y-5)*9+(x-4)-1]==3)
			{
				mvaddch(y,x,'3');
				check[(y-5)*9+(x-4)-1]=3;
				move(y,x);
			}
			else if(form[(y-5)*9+(x-4)-1]==4)
			{
				mvaddch(y,x,'4');
				check[(y-5)*9+(x-4)-1]=4;
				move(y,x);
			}
			else if(form[(y-5)*9+(x-4)-1]==7)
			{
				mvaddch(5+2,5+1,'2');
				mvaddch(5+2,5+2,'1');
				mvaddch(5+2,5+3,'1');
				mvaddch(5+2,5+7,'2');
				mvaddch(5+2,5+8,'1');
				mvaddch(5+3,5+0,'1');
				mvaddch(5+3,5+1,'1');
				mvaddch(5+3,5+2,' ');
				mvaddch(5+3,5+3,'1');
				mvaddch(5+3,5+4,'2');
				mvaddch(5+3,5+5,'3');
				mvaddch(5+3,5+6,'2');
				mvaddch(5+3,5+7,'1');
				mvaddch(5+3,5+8,' ');
				mvaddstr(5+4,5,"111      ");
				mvaddstr(5+5,5+2,"1    11");
				mvaddstr(5+6,5+2,"2    1");
				mvaddstr(5+7,5+2,"1    11");
				mvaddstr(5+8,5,"111      ");
				move(y,x);
				for(int i=0;i<81;i++)
				{
					if(i==19||i==20||i==21||i==25||i==26||(i>26&&i<45)||(i>46&&i<54)||(i>55&&i<62)||(i>64&&i<81))
						check[i]=form[i];
				}
			}
			else if(form[(y-5)*9+(x-4)-1]==-1)
			{
				gameover=true;
			}
			if(checkans())
				win=true;
		}
};

void ruby()
{
	setlocale(LC_CTYPE, "");
	int x=StartX;                     /* 宣告 x,y 並設定其初值 */
	int y=StartY;
	char ch;                           /* 宣告 ch 為整數,配合 getch() 使用 */
	initial();   	/* 呼叫 initial(), 啟動 curses 模式, */


	/* 並完成其它設定 */
	bool start=true;
	int state=0,success=0;
	lock1 ck1;
	lock2 ck2;
	lock3 ck3;

	//state0//遊戲開始
	mvaddstr(10,10,"哈哈，你以為遊戲結束了嗎？");
	mvaddstr(11,10,"你還沒有見到童媽呢");
	mvaddstr(13,10,"電資大樓只有\"身富卷氣\"的人才能找到入口呢 科科");
	mvaddstr(14,10,"用接下來的關卡證明你的聰明才智吧!!!");
	mvaddstr(15,30,"====按ENTER");

	//mvaddch(y,--x,' ');/* delete 一個字元 */
	//mvaddstr(y,x," ");
	//printw("%s ",s.c_str());
	move(x,y);                        /* 將游標移至初始位置 */

	do {                              /* 以無限迴圈不斷等待輸入 */
		ch=getch();                      /* 等待自鍵盤輸入字元 */
		switch(ch) {                     /* 判斷輸入字元為何 */

			case 'w': --y;             /* 判斷是否"↑"鍵被按下 */
				  break;
			case 's': ++y;           /* 判斷是否"↓"鍵被按下 */
				  break;
			case 'd': ++x;          /* 判斷是否"→"鍵被按下 */
				  break;
			case 'a': --x;           /* 判斷是否"←"鍵被按下 */
				  break;
			case '\r':                    /* 判斷是否 ENTER 鍵被按下 */
				  if(start)
				  {
					  clear();
					  start=false;
					  state=1;
					  break;
				  }
				  else if(state==2)
				  {
					  ck2.open(y,x);
					  break;
				  }
				  else if(state==3)
				  {
					  ck3.open(y,x);
					  if(ck3.getgame())
					  {
						state=100;
					  }
					  else if(ck3.getwin())
					  {
						  state=4;
						  clear();
						  mvaddstr(10,10,"童媽 is here!");
						  usleep(3000000);
						  clear();
						  refresh();
						  return;
					  }
				  }
				  break;
			case '\t':                    /* 判斷是否 TAB 鍵被按下 */
				  x+=7;
				  state++;
				  clear();
				  if(state==3)
				  {
					  for(int i=0;i<9;i++)
					  {
						  for(int j=0;j<9;j++)
						  {
							  mvaddstr(5+i,5+j,"\u2588");
						  }
					  }
				  }
				  break;
			case 127:                     /* 判斷是否 BACKSPACE 鍵被按下 */
				  mvaddch(y,--x,' ');/* delete 一個字元 */
				  break;

			case 27: endwin();            /* 判斷是否[ESC]鍵被按下 */
				 exit(1);             /* 結束 curses 模式 */
				 /* 結束此程式 
				  * */
			default:
				 if(state==1)
				 {
					 ck1.open(y,x,ch);	
					 x++;
				 }
				 else if(state==3)
				 {
					 if(y>4&&y<14&&x>4&&x<14)
					 {
						 if(ch=='f')
						 {
							 mvaddstr(y,x,"\u2665"); 
						 }
						 break;
					 }
				 }
				 break;
		}
		mvaddstr(0,0,"stage:");
		move(0,6);
		printw("%d",state);
		//state1//第一關
		if(state==1)
		{
			move(5,0);
			ifstream inf1("state1.txt");
			string in;
			while(getline(inf1,in,'\n'))
			{
				printw("%s\n",in.c_str());
			}
			inf1.close();
			mvaddstr(2,5,"hint:MIRROR(four numbers)");
			mvaddstr(3,5,"enter the answer:");
			if(!ck1.islock())
			{
				state=2;
				clear();
				mvaddstr(0,0,"stage:");
				move(0,6);
				printw("%d",state);
				mvaddstr(5,5,"Please full the form with L and P   (press enter to shift L and P)");
				mvaddstr(6,5,"every row and cloumn should have three L and three P");
				mvaddstr(7,5,"while never three in a row/cloumn");
				mvaddstr(9,5,"\u250C");
				for(int i=0;i<6;i++)
				{
					mvaddstr(9,6+2*i,"\u2500\u252C");
				}
				mvaddstr(9,17,"\u2510");
				for(int j=0;j<6;j++)
				{
					for(int i=0;i<7;i++)
					{
						mvaddstr(10+2*j,5+2*i,"\u2502");

					}
					mvaddstr(11+2*j,5,"\u251C");
					for(int i=0;i<5;i++)
					{
						mvaddstr(11+2*j,6+2*i,"\u2500\u253C\u2500");
					}
					mvaddstr(11+2*j,17,"\u2524");
				}
				mvaddstr(21,5,"\u2514");
				for(int i=0;i<6;i++)
				{
					mvaddstr(21,6+2*i,"\u2500\u2534");
				}
				mvaddstr(21,17,"\u2518");
				mvaddch(10,6+4,'L');
				mvaddch(10,6+8,'P');
				mvaddch(10+4,6,'P');
				mvaddch(10+4,6+2,'P');
				mvaddch(10+4,6+8,'L');
				mvaddch(10+6,6+2,'P');
				mvaddch(10+8,6+10,'L');
				mvaddch(10+10,6+2,'P');
				mvaddch(10+10,6+4,'L');
			}
		}
		else if(state==2)
		{
			mvaddstr(5,5,"Please full the form with L and P   (press enter to shift L and P)");
			mvaddstr(6,5,"every row and cloumn should have three L and three P");
			mvaddstr(7,5,"while never three in a row/cloumn");
			mvaddstr(9,5,"\u250C");
			for(int i=0;i<6;i++)
			{
				mvaddstr(9,6+2*i,"\u2500\u252C");
			}
			mvaddstr(9,17,"\u2510");
			for(int j=0;j<6;j++)
			{
				for(int i=0;i<7;i++)
				{
					mvaddstr(10+2*j,5+2*i,"\u2502");

				}
				mvaddstr(11+2*j,5,"\u251C");
				for(int i=0;i<5;i++)
				{
					mvaddstr(11+2*j,6+2*i,"\u2500\u253C\u2500");
				}
				mvaddstr(11+2*j,17,"\u2524");
			}
			mvaddstr(21,5,"\u2514");
			for(int i=0;i<6;i++)
			{
				mvaddstr(21,6+2*i,"\u2500\u2534");
			}
			mvaddstr(21,17,"\u2518");
			mvaddch(10,6+4,'L');
			mvaddch(10,6+8,'P');
			mvaddch(10+4,6,'P');
			mvaddch(10+4,6+2,'P');
			mvaddch(10+4,6+8,'L');
			mvaddch(10+6,6+2,'P');
			mvaddch(10+8,6+10,'L');
			mvaddch(10+10,6+2,'P');
			mvaddch(10+10,6+4,'L');
			if(!ck2.islock())
			{
				state=3;
				clear();
				mvaddstr(2,2,"                                 ");
				mvaddstr(3,3,"踩地雷囉~~~~");
				mvaddstr(4,3,"if you want to use flag press \"f\"(flag)");
				for(int i=0;i<9;i++)
				{
					for(int j=0;j<9;j++)
					{
						mvaddstr(5+i,5+j,"\u2588");
					}
				}
			}
		}
		else if(state==3)
		{
			mvaddstr(2,2,"                                 ");
			mvaddstr(3,3,"踩地雷囉~~~~");
			mvaddstr(4,3,"if you want to use flag press \"f\"(flag)");
		}
		else if(state==100)
		{
			clear();
			mvaddstr(2,2,"                                 ");
			mvaddstr(3,3,"踩地雷囉~~~~");
			mvaddstr(4,3,"if you want to use flag press \"f\"(flag)");
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					mvaddstr(5+i,5+j,"\u2588");
				}
			}
			state=3;
			ck3.reset();
		}
		move(y,x);                      /* 移動游標至現在位置 */
	} while (1);
}


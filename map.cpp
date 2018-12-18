#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ncurses.h>
#include"jokerGame.cpp"
#include"test.cpp"
#include"drama.cpp"
using namespace std;

void maze();
static int flag[29][96];//flag [y][x]
int dra2=0;
class Tools
{
	public:
		//map
		int IDcard;
		int money;
		int key_num;
		int key[4];
		int touch_me;
		int bird;
		int waffle;

		//maze
		int maze_key;

		Tools()
		{
			IDcard=0;
			for(int i=0;i<4;i++)
				key[i]=0;
			touch_me=0;
			bird=0;
			money=0;
			waffle=0;
			key_num=0;
		}
		Tools(int n)
		{
			maze_key=n;
		}

		void touch(int, int);//檢查有沒有碰到物件
		bool check_key(int, int);
		bool check_maze(int, int);
		void keyNum();
		friend void message(string w);
		friend void maze();
};


class HERO:public Tools
{
	private:
		int coor[2];
	public:
		HERO():Tools()
		{
			coor[1]=3;// y
			coor[2]=58;// x
		}

		//for maze
		HERO(int y, int x):Tools(0)
		{
			coor[1]=y;
			coor[2]=x;
		}
		void newhero(int ,int);
		void destroy();

		friend void message(string w);
		friend bool empty();//check if HERO touched anything
		friend void maze();


};

bool empty(int, int);
//bool touch(int, int);

void map()
{
	drama();
	setlocale(LC_CTYPE,"");
	initial();

	int y=3, x=58;
	int i=0, j=0;		//counter
	char ch;
	HERO me;
	string read;
	ifstream fin("map.txt");

	clear();
	move(0,0);
	while(getline(fin, read, '\n'))
	{
		//j=y i=x
		for( i=0 ; i<read.size() ; i++ )
		{
			if(read[i]!=' ')//有字就給他1
			{
				flag[j][i]=1;
			}
		}
		printw("%s\n", read.c_str());
		j++;		//計算進來的次數(y座標)
	}
	fin.close();

	me.newhero(y,x);	//設初始位置

	do
	{
		ch=getch();                      /* 等待自鍵盤輸入字元 */
		switch(ch)
		{                     /* 判斷輸入字元為何 */

			case 'w': --y;             /* 判斷是否"↑"鍵被按下 */
				  if(!empty(y, x))
				  {
					  y++;
					  me.touch(y, x);
					  break;
				  }
				  else if(me.check_key(y,x))
				  {
					  y++;
					  break;
				  }
				  else
					  break;
			case 's': ++y;           /* 判斷是否"↓"鍵被按下 */
				  if(!empty(y, x))
				  {
					  y--;
					  me.touch(y,x);
					  break;
				  }
				  else if(me.check_key(y,x))
				  {
					  y--;
					  break;
				  }
				  else
					  break;
			case 'd': ++x;          /* 判斷是否"→"鍵被按下 */
				  if(!empty(y, x))
				  {
					  x--;
					  me.touch(y, x);
					  break;
				  }
				  else if(me.check_key(y,x))
				  {
					  x--;
					  break;
				  }
				  else
					  break;
			case 'a': --x;           /* 判斷是否"←"鍵被按下 */
				  if(!empty(y, x))
				  {
					  x++;
					  me.touch(y, x);
					  break;
				  }
				  else if(me.check_key(y,x))
				  {
					  x++;
					  break;
				  }
				  else
					  break;
		}
		if(dra2==1)
			break;
		me.newhero(y,x);
	} while (1);


}
void message(string w)
{
	mvaddstr(27, 1, w.c_str());
}
void HERO::destroy()//消除原本的HERO
{
	int y=coor[1];
	int x=coor[2];
	mvaddstr(y, x, "  ");//replace HERO with space
	mvaddstr(y+1, x, "  ");
}	

void HERO::newhero(int y, int x)
{
	destroy();
	this->coor[1]=y;
	this->coor[2]=x;
	mvaddstr(y,x,"HE");
	mvaddstr(y+1,x,"RO");
	move(y,x);
}
bool empty(int y, int x)
{
	if(flag[y][x]==1)//H
		return 0;
	else if(flag[y+1][x]==1)//R
		return 0;
	else if(flag[y][x+1]==1)//E
		return 0;
	else if(flag[y+1][x+1]==1)//O
		return 0;
	return 1;
}
bool Tools::check_key(int y, int x)
{

	if(y==1)
	{
		if(x>=1&&x<=3)
		{
			mvaddstr(1,1,"key");
			key[0]=1;
			flag[1][1]=1;
			flag[1][2]=1;
			flag[1][3]=1;
			key_num++;
			keyNum();
			return true;
		}
	}
	else if(y==25&&x<=89&&x>=87)
		{
			mvaddstr(26,87,"key");
			key[3]=1;
			flag[26][87]=1;
			flag[26][88]=1;
			flag[26][89]=1;
			key_num++;
			keyNum();
			return true;
		}
	else if(y>=25&&y<=26)
	{
		if(x==86||x==89)
		{
			mvaddstr(26,87,"key");
			key[3]=1;
			flag[26][87]=1;
			flag[26][88]=1;
			flag[26][89]=1;
			key_num++;
			keyNum();
			return true;
		}
	}
	else if(y==7&&x>=18&&x<=21)
	{
		mvaddstr(8,19,"key");
		key[1]=1;
		flag[8][18]=1;
		flag[8][19]=1;
		flag[8][21]=1;
		key_num++;
		keyNum();
		return true;
	}
	else if(y==11||y==12 )
	{
		if(x>=89&&x<=92)
		{
			mvaddstr(12, 90, "key");
			key[2]=1;
			flag[12][90]=1;
			flag[12][91]=1;
			flag[12][92]=1;
			key_num++;
			keyNum();
			return true;
		}
	}
	return 0;
}


void Tools::touch(int y, int x)
{
	//touch me
	if(y==2 && x==44 )
	{
		touch_me=1;
		//mvaddstr(28,2,"test");	
		mvaddstr(27,1," 你拿到了一張退選單  ");
	}
	else if(y==16 && x==56)//CX_Shen
	{
		if(touch_me==1)
		{
			IDcard=1;
			message(" 你拿到了學生證      ");
		}
		else
			message(" 你的退選單呢????????");
	}
	else if(y==2 && x==17)//TH_Lei
	{
		if(IDcard==1)
		{
			money=1;		
			message(" 錢給你，去買鬆餅    ");
		}
		else
			message(" 說好的學生證在哪?   ");

	}
	else if(y==22 && x+1==55)//waffle
	{
		if(money==1)
		{
			waffle=1;
			message(" 87號的鬆餅好了 <3   ");
		}
		else
			message(" 付錢才有鬆餅吃喔*ˊˇˋ");
	}
	else if(y==8 && x==57)//bird
	{
		mvaddstr(y, x-4, "BIRD");
		if(waffle==1)
		{
			bird=1;
			message("去找YZ_Lin 他會知道的");
			move(y,x);
		}
		else
			message(" 有鬆餅才告訴你下一步");
	}
	else if(y==10 && x==81)//YZ_Lin
	{
		if(bird==1)
		{
			clear();
			jokerGame();
			//refresh();
			clear();
			ifstream newf;
			string news;
			newf.open("map_1key.txt");
			while(	getline(newf, news, '\n'))
				printw("%s\n", news.c_str());
		//	mvaddstr(19,23," ");
		//	mvaddstr(20,23," ");
			flag[19][23]=0;
			flag[20][23]=0;
		}
		else
			message(" 你有問題? 我不要幫你");
	}
	else if(y==22&&x==6)	//LP_Tung
	{
		if(key_num==4)
		{
			maze();
		}
		else
			message(" 你需要 4 個 key     ");
	}
	else
		message("                     ");

}
void Tools::keyNum()
{
	switch(key_num)
	{
		case 1:
			message("You got 1st key!     ");
			break;
		case 2:
			message("You got 2nd key!     ");
			break;
		case 3:
			message("You got 3rd key!     ");
			mvaddstr(16,81,"   ");
			flag[16][81]=0;
			flag[16][82]=0;
			flag[16][83]=0;
			break;
		case 4:
			message("You got all key!     ");
			break;
	}
}

void maze()
{
	int y=1, x=1;
	int i=0, j=0;		//counter
	char ch;
	HERO me(y,x);
	string read;
	ifstream fin("maze.txt");

	clear();
	move(0,0);
	while(getline(fin, read, '\n'))
	{
		//j=y i=x
		for( i=0 ; i<read.size() ; i++ )
		{
			if(read[i]!=' ')//有字就給他1
			{
				flag[j][i]=1;
			}
			else
				flag[j][i]=0;
		}
		printw("%s\n", read.c_str());
		j++;		//計算進來的次數(y座標)
	}
	fin.close();

	me.newhero(y,x);	//設初始位置
	do
	{                              /* 以無限迴圈不斷等待輸入 */
		ch=getch();                      /* 等待自鍵盤輸入字元 */
		switch(ch)
		{                     /* 判斷輸入字元為何 */

			case 'w': --y;             /* 判斷是否"↑"鍵被按下 */
				  if(!empty(y, x))
				  {
					  y++;
					  break;
				  }
				  else if(me.check_maze(y,x))
				  {
					  y++;
					  break;
				  }
				  else
					  break;
			case 's': ++y;           /* 判斷是否"↓"鍵被按下 */
				  if(!empty(y, x))
				  {
					  y--;
					  break;
				  }
				  else if(me.check_maze(y,x))
				  {
					  y--;
					  break;
				  }
				  else
					  break;
			case 'd': ++x;          /* 判斷是否"→"鍵被按下 */
				  if(!empty(y, x))
				  {
					  x--;
					  break;
				  }
				  else if(me.check_maze(y,x))
				  {
					  x--;
					  break;
				  }
				  else
					  break;
			case 'a': --x;           /* 判斷是否"←"鍵被按下 */
				  if(!empty(y, x))
				  {
					  x++;
					  break;
				  }
				  else if(me.check_maze(y,x))
				  {
					  x++;
					  break;
				  }
				  else
					  break;
		}
		if(dra2==1)
			break;
		me.newhero(y,x);
		//if()
	} while (1);
}

bool Tools::check_maze(int y,int x)
{
	
	if(y==12)
	{
		if( x<=3 && x>=1 )
		{
			mvaddstr(12, 1, "key");
			for(int i=1;i<=3;i++)
				flag[12][i]=1;
			message("      TRUE KEY       ");
			mvaddstr(20,72,"  ");
			flag[20][72]=0;
			flag[20][73]=0;
			return 1;
		}
	}
	if(y==20&&x>=72&&x<=74)//撞到LP
	{
		clear();
		ruby();
		clear();
		dra2=drama2();
	}
	return 0;
}


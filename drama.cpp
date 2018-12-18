#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ncurses.h>
using namespace std;

void initial();                       /* 自定開啟 curses 函式 */

void drama()
{
	setlocale(LC_CTYPE, "");
	initial();
	int y=14;
	int x=19;
	int i;
	int mes_num = 10;//message的數量
	string mes[mes_num];//message
	string file;
	ifstream fin;
	fin.open("LP.txt");

	mes[0]="你好，勇者，我是 coding 之神的使徒";
	mes[1]="非常高興你做了退選的決定";
	mes[2]="但是可惜地，上天決定先苦其心志、勞其筋骨";
	mes[3]="唯有通過了層層關卡，跟沈政賢、雷宗翰、林昱澤和交大怪鳥交涉後";
	mes[4]="................................";
	mes[5]="臥槽是詞窮了嗎，到底想講什麼(´・ω・`)  ←(你內心OS)";
	mes[6]="咳咳，剛剛助教們要我匿名，好我再講一次";
	mes[7]="你必須跟三人一鳥交涉，並接受他們提出的挑戰";
	mes[8]="唯有挑戰成功，並收集到四把鑰匙才能進到電資大樓，找到最終大魔王";
	///	mes[9]="===============LP==================痛";
	mes[9]="並走完迷宮解完謎才能退選OOP喔 <3";


	mvaddstr(y, x , mes[0].c_str());
	mvaddstr(y+5,65, "press any key to continue...");

	for(i = 1; getch() && i<mes_num+1 ;i++ )
	{
		clear();
		if(i==9)
		{
			move(0,0);
			while(getline(fin, file, '\n'))						
			{
				printw("%s\n",file.c_str());
			}
			fin.close();
		}
		else if(i==10)
		{
			mvaddstr(y, x , mes[9].c_str());
		}
		else
		{
			mvaddstr(y, x , mes[i].c_str());
		}
		mvaddstr(y+5,65, "press any key to continue...");
	}		
}
int drama2()
{
	int y=14;
	int x=19;
	int i;
	int mes_num = 10;//message的數量
	string mes[mes_num];//message
	string file;
	ifstream fin;
	fin.open("LP.txt");

	mes[0]="恭喜過關      おめでとうございま──す！";
	mes[1]="你成功地找到了LP痛，把退選單交給他了";
	mes[2]="但是.................................";
	mes[3]="嗯?什麼?? ←(你內心OS)";
	mes[4]="你好像忘記了一件事情了唷 <3";
	mes[5]="|дﾟ)なに? ←(你內心OS)";
	mes[6]="你看看今天幾號 已經過了退選時間了唷(´◉◞౪◟◉)";
	mes[7]="唷呵呵呵呵呵呵呵呵呵呵呵呵呵呵呵呵呵呵呵呵呵呵呵";
	mes[8]="不過不用擔心 LP痛不會當人的('ω')ノ";
	mes[9]="所以就這樣啦 拜拜~~~~(飄走) ";


	mvaddstr(y, x , mes[0].c_str());
	mvaddstr(y+5,65, "press any key to continue...");

	for(i = 1; getch() && i<mes_num+1 ;i++ )
	{
		clear();
		if(i==9)
		{
			move(0,0);
			while(getline(fin, file, '\n'))						
			{
				printw("%s\n",file.c_str());
			}
			fin.close();
		}
		else if(i==10)
		{
			mvaddstr(y, x , mes[9].c_str());
		}
		else
		{
			mvaddstr(y, x , mes[i].c_str());
		}
		mvaddstr(y+5,65, "press any key to continue...");
	}		
	return 1;
}


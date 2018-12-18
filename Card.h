#ifndef Card_H
#define Card_H
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<ncurses.h>
#include<unistd.h>
using namespace std;
enum Suit{club,diamond,heart,spade,joker};
class Player;
class Card {
public:
	Card();
	~Card();
	void printCard();         
	Card setCard(Suit,int);   
	friend void resetCard(Card[]);
	friend void shuffle(Card[]);
	friend void deal(Card[],Player,Player);
	friend void deal(Card[],Player,Player,Player);
	friend void deal(Card[],Player,Player,Player,Player);
	friend void throwCard(Player);
	friend void pickCard(Player,Player);
	friend void sort_Card(Player);
	friend void judgement_And_Turn(Player player[]);
	friend int pickCard_Turn(Player player[]);
	friend void sort_Player(Player[]);
	friend void print_Position(Player);
	friend WINDOW *create_newwin(int height, int width, int starty, int startx);
	friend void print_Other_Position(Player player);
	friend void destroy_Card(Player player);
	friend Player;
private:
	Suit suit;
	int face;
};
void shuffle(Card[]);   //將牌重設為全新牌組(限54張)
void resetCard(Card card[]);   //洗牌(限54張)

class Player {
public:
	Player();
	~Player();
	void setID(int);
	friend void deal(Card[],Player,Player);
	friend void deal(Card[],Player,Player,Player);
	friend void deal(Card[],Player,Player,Player,Player);
	friend void throwCard(Player);
	friend void pickCard(Player,Player);
	friend void sort_Card(Player);
	friend void judgement_And_Turn(Player player[]);
	friend void judgement(Player[]);
	friend int pickCard_Turn(Player player[]);
	friend void sort_Player(Player[]);
	friend void print_Position(Player);
	friend void destroy_win(WINDOW *local_win);
	friend WINDOW *create_newwin(int height, int width, int starty, int startx);
	friend void print_Other_Position(Player player);
	friend void destroy_Card(Player player);
	int chooseX(int i);
	int chooseY(int i);
	int getLength();
	int getID();
	void setLength();
	void moveChoose(int choose);
	void setPosition(int y[],int x[]);
	void showHand();
	void showID();
private:
	Card *hand;
	WINDOW *win[15];
	int ID;
	int length;
	int card_X_Position[15];
	int card_Y_Position[15];
};
void deal(Card[],Player,Player);   
void deal(Card[],Player,Player,Player); 
void deal(Card[],Player,Player,Player,Player);  

#endif

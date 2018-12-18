#ifndef CARD_UI_H
#define CARD_UI_H
#include"Card.h"
#include<curses.h>
#include<cstdlib>
void destroy_win(WINDOW *local_win);
void initial();
void print_Position(Player);
WINDOW *create_newwin(int height, int width, int starty, int startx);
void printBox(int height,int width,int y,int x);
void destroy_Card(Player player);

#endif

#ifndef JOKER_H
#define JOKER_H
#include"Card.h"
#include"card_UI.h"

void jokerGame();
void throwCard(Player);
void pickCard(Player p1,Player p2);
int pickCard_Turn(Player[]);
void sort_Card(Player);
void judgement_And_Turn(Player[]);
void sort_Player(Player[]);

#endif

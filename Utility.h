#pragma once
#include "struct.h"

int mainMenu();
void displayStatus(bool);
//true == win
//false == lose
void getPlayerInfo(player&);
void readLeaderBoard();
void writeLeaderBoard(player);
void getBG(char[][41]);
void displayBG(char[][41], int, int);
void getfullBG(char[][41]);

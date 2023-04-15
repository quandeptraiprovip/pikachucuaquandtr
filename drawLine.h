#pragma once
#include "struct.h"
#include <ncurses.h>

//X: horizontal
//Y: vertical
void drawIX(int, int, int);
void drawIY(int, int, int);
void drawZ(position ,position ,int, int type);
//type 1 ZX
//type 2 ZY
void drawI(position ,position);
void drawU(position ,position ,int , int type);
//type 1 UX
//type 2 UY 
void drawL(position, position, int type);
//type 1 right
//type 2 left
void delIX(int, int, int);
void delIY(int, int, int);
void delZ(position ,position ,int, int type);
void delI(position ,position);
void delU(position ,position ,int , int type);
void delL(position, position, int type);

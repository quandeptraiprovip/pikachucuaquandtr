#pragma once
#include "struct.h"

//X: horizontal
//Y: vertical

//check line x from y1 to y2
int checkLineX(Box1**, int y1, int y2, int x);
//check column y from x1 to x2
int checkLineY(Box1**, int x1, int x2, int y);
int checkZX(Box1**, int x1, int y1, int x2, int y2);
int checkZY(Box1**, int x1, int y1, int x2, int y2);
//type == 1 u right
//type == -1 u left
int checkUX(Box1**, position p1, position p2, int type);
//type == 1 up
//type == -1 down
int checkUY(Box1**, position p1, position p2, int type);
//type == 1 right
//typw == - 1 left
int checkL(Box1**, position p1, position p2);
int allcheck(Box1**, position p1, position p2);
bool checkValidPairs(Box1**);
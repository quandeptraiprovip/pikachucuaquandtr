#pragma once
#include "struct.h"

//check line x from y1 to y2
bool checkLineX(Box1**, int y1, int y2, int x);
//check column y from x1 to x2
bool checkLineY(Box1**, int x1, int x2, int y);
bool checkZX(Box1**, int x1, int y1, int x2, int y2);
bool checkZY(Box1**, int x1, int y1, int x2, int y2);
//type == 1 u right
//type == -1 u left
bool checkUX(Box1**, position p1, position p2, int type);
//type == 1 up
//type == -1 down
bool checkUY(Box1**, position p1, position p2, int type);
//type == 1 right
//typw == - 1 left
bool checkL(Box1**, position p1, position p2);
bool allcheck(Box1**, position p1, position p2);
bool checkValidPairs(Box1**);
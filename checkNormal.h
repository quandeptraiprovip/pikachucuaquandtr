#pragma once
#include "struct.h"

//check line x from y1 to y2
bool checkLineX(Box1**, int y1, int y2, int x);
//check column y from x1 to x2
bool checkLineY(Box1**, int x1, int x2, int y);
bool checkZX(Box1**, int p1, int p2, int q1, int q2);
bool checkZY(Box1**, int p1, int p2, int q1, int q2);
bool checkUX(Box1**, int p1, int p2, int q1, int q2);
bool checkUY(Box1**, int p1, int p2, int q1, int q2);
bool allcheck(Box1**, int x1, int y1, int x2, int y2);
bool checkValidPairs(Box1**);
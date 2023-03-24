#pragma once
#include "struct.h"

bool checkLineX(Box1**, int p1, int p2, int q1, int q2);
bool checkLineY(Box1**, int p1, int p2, int q1, int q2);
bool checkZX(Box1**, int p1, int p2, int q1, int q2);
bool checkZY(Box1**, int p1, int p2, int q1, int q2);
bool checkUX(Box1**, int p1, int p2, int q1, int q2);
bool checkUY(Box1**, int p1, int p2, int q1, int q2);
bool allcheck(Box1**, int p1, int p2, int q1, int q2);
bool checkValidPairs(Box1**);
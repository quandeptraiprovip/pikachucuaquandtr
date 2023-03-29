#pragma once


#include "struct.h"
#include "Utility.h"

Box2* findTheNode(Box2**, int, int);
bool Icheck(Box2** , position, position);
bool Lcheck(Box2**, position, position);
//mode 1 check up
//mode -1 check down
bool UYcheck(Box2**, position, position, int mode);
//check u right
bool UXcheck(Box2**, position, position);
bool Zcheck(Box2**, position, position);
bool allCheck(Box2**, position, position);
void delNode(Box2**, int, int);
void del(Box2**, position, position);
bool checkValidPairs(Box2**);

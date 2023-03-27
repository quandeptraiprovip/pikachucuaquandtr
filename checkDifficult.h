#pragma once


#include "struct.h"
#include "Utility.h"

Box2* findTheNode(Box2**, int, int);
bool Icheck(Box2** , position, position);
bool Lcheck(Box2**, position, position);
bool UandZcheck(Box2**, position, position);
bool allCheck(Box2**, position, position);
void deleteNode(Box2**, int, int, char [][41]);
void DifMode(Box2**, position, position, char [][41]);
bool checkValidPairs(Box2**);

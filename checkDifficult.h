#pragma once


#include "struct.h"
#include "Utility.h"

Box2* findTheNode(Box2**, int, int);
bool Icheck(Box2** , position, position);
bool Lcheck(Box2**, position, position);
bool UandZcheck(Box2**, position, position);
bool allCheck(Box2**, position, position);
void delHead(Box2**, int x);
void delTail(Box2**, int x);
void delAt(Box2**, int x, int k);
void deleteNode(Box2**, int, int);
void del(Box2**, position, position);
bool checkValidPairs(Box2**);

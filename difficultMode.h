#pragma once
#include "Utility.h"

void addTail(Box2*&, Box2*);
void initList(Box2**);
void deleteList(Box2**);
void renderList(Box2**);
void move(Box2**, position&, int&, player&, position[], int&);
void difficultMode(player&);
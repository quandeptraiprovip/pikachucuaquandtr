#pragma once
#include "Utility.h"

void initBoard(Box1**);
void renderBoard(Box1**);
void deleteBoard(Box1**);
void move(Box1**, position&, int&, player&, position [], int&);
void hint(Box1**);
void draw(position, position, int); // draw match line
void del(position, position, int);// del match line
void normalMode(player&);
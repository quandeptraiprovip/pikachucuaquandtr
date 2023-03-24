#include<iostream>
#include<ncurses.h>
#include<fstream>
#include"struct.h"
#include "Utility.h"
#include "normalMode.h"
using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    clear();

    // Box1 **board = new Box1*[5];
    // for(int i = 0; i < 5; i ++) {
    //     board[i] = new Box1[8];
    // }

    Box1 a;
    a.i = 1;
    a.j = 2;
    a.c = 'a';
    a.isSelected = true;

    a.drawBox();
    
    getch();
    clear();

    refresh();


    // Clean up
    endwin();
    return 0;
}
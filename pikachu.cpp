#include<iostream>
#include<ncurses.h>
#include<fstream>
#include"struct.h"
#include "Utility.h"
#include "normalMode.h"
#include "difficultMode.h"
using namespace std;

int main() {
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    clear();

    Box2 **board = new Box2*[BOARDHEIGTH + 2];
    
    initList(board);
    renderList(board);


    getch();
    clear();

    refresh();


    // Clean up
    endwin();
    return 0;
}
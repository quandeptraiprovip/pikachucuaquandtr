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

    
    Box1 **board = new Box1 *[BOARDHEIGTH];
    initBoard(board);
    renderBoard(board);

    //deleteBoard(board);
    
    getch();
    clear();

    refresh();


    // Clean up
    endwin();
    return 0;
}
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
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    clear();

    Box1 **board = new Box1 *[BOARDHEIGTH];
    initBoard(board);
    renderBoard(board);
    board[0][0].isSelected = true;
    board[0][0].drawBox(1);
    
    getch();
    clear();

    refresh();


    // Clean up
    endwin();
    return 0;
}
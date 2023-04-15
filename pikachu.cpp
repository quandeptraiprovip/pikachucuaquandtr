#include<iostream>
#include<ncurses.h>
#include<fstream>
#include"struct.h"
#include "Utility.h"
#include "normalMode.h"
#include "difficultMode.h"
#include "checkDifficult.h"
#include "drawLine.h"
using namespace std;

int main() {
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    curs_set(0);
    clear();

    int status;
    player p;

    while ((status = mainMenu()) != 3) {
        switch (status)
        {
        case 0:
            getPlayerInfo(p);
            normalMode(p);
            break;
        case 1:
            readLeaderBoard();
            break;
        default:
            break;
        }
    }

    refresh();

    getch();
    clear();



    // Clean up
    endwin();
    return 0;
}
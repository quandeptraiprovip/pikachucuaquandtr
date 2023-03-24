#include<iostream>
#include<ncurses.h>
#include<fstream>
#include"struct.h"
#include "Utility.h"
#include "normalMode.h"
using namespace std;

int main() {
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    clear();

    int status = mainMenu();
    player p;




    while (status != 3) {
        switch (status)
        {
        case 0:
            getPlayerInfo(p);
            normalMode(p);
            break;
        default:
            break;
        }
    }
    


    getch();
    clear();

    refresh();


    // Clean up
    endwin();
    return 0;
}
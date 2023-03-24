#include<iostream>
#include<ncurses.h>
#include<fstream>
#include"struct.h"
#include "Utility.h"
using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    clear();

    
    getch();
    clear();

    refresh();



    // Wait for user input
    getch();

    // Clean up
    endwin();
    return 0;
}
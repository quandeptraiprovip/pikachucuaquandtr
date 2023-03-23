#include<iostream>
#include<ncurses.h>
#include<fstream>
#include"struct.h"
using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    clear();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    char box[5][12] = {
            {" --------- "},
            {"|         |"},
            {"|         |"},
            {"|         |"},
            {" --------- "}
    };
    int x = 1;
    int y = 1;
    for(int i = 1; i <= 5; i++ ) {
        for(int j = 1; j <= 4; j ++) {
            for (int k = 0; k < 5; k++) {
                move(j * 4 + k, 10 * i - 5);
                printw(box[k]);
            }
        }
    }

    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));

    for(int i = 1; i <= 5; i++ ) {
        for(int j = 1; j <= 4; j ++) {
            for (int k = 0; k < 3; k++) {
                move(j * 4 + k + 1, 10 * i - 5 + 1);
                printw("         ");
            }
        }
    }

    move(1 * 4 + 2, 10 * 1 - 5 + 5);
    printw("A");

    attroff(COLOR_PAIR(2));
    

    
    getch();
    clear();

    refresh();



    // Wait for user input
    getch();

    // Clean up
    endwin();
    return 0;
}
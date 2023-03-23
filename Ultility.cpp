#include<iostream>
#include<ncurses.h>
using namespace std;

int mainMenu() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    clear();

    

    int choice[4] = { 0,0,0,0 }, temp, key, curChoice = 0;
    while(1) {


        start_color(); // enable color output
        init_pair(1, COLOR_BLACK, COLOR_WHITE);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        mvprintw(0, 6, " ______    __   __  ___      ___       ______  __    __   __    __");
        mvprintw(1, 6, "|   _  \\  |  | |  |/  /     /   \\     /      ||  |  |  | |  |  |  |");
        mvprintw(2, 6, "|  |_)  | |  | |  '  /     /  ^  \\   |  ,----'|  |__|  | |  |  |  |");
        mvprintw(3, 6, "|   ___/  |  | |    <     /  /_\\  \\  |  |     |   __   | |  |  |  |");
        mvprintw(4, 6, "|  |      |  | |  .  \\   /  _____  \\ |  `----.|  |  |  | |  `--'  |");
        mvprintw(5, 6, "| _|      |__| |__|\\__\\ /__/     \\__\\ \\______||__|  |__|  \\______/");


        attroff(COLOR_PAIR(2));

        choice[curChoice] = 1;

        if(choice[0]) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 3; i++) {
                mvprintw(8 + i, COLS/2 - 8, "             ");
            }

            mvprintw(9, COLS/2 - 8 + 4, "NORMAL");
            attroff(COLOR_PAIR(1));
        }else {
            mvprintw(9, COLS/2 - 8 + 4, "NORMAL");
        }

        if(choice[1]) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 3; i++) {
                mvprintw(11 + i, COLS/2 - 8, "             ");
            }

            mvprintw(12, COLS/2 - 8 + 2, "DIFFICULT");
            attroff(COLOR_PAIR(1));
        }else {
            mvprintw(12, COLS/2 - 8 + 2, "DIFFICULT");
        }

        if(choice[2]) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 3; i++) {
                mvprintw(14 + i, COLS/2 - 8, "             ");
            }

            mvprintw(15, COLS/2 - 8 + 1, "LEADERBOARD");
            attroff(COLOR_PAIR(1));
        }else {
            mvprintw(15, COLS/2 - 8 + 1, "LEADERBOARD");
        }

        if(choice[3]) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 3; i++) {
                mvprintw(17 + i, COLS/2 - 8, "             ");
            }

            mvprintw(18, COLS/2 - 8 + 5, "EXIT");
            attroff(COLOR_PAIR(1));
        }else {
            mvprintw(18, COLS/2 - 8 + 5, "EXIT");
        }

        key = getch();

        if(key == '\n') {
            clear();
            return curChoice;
        }

        switch(key) {
            case KEY_UP:
                choice[curChoice] = 0;
                if(curChoice > 0) {
                    curChoice --;
                }else {
                    curChoice = 3;
                }
                break;
            case KEY_DOWN:
                choice[curChoice] = 0;
                if(curChoice < 3) {
                    curChoice ++;
                }else {
                    curChoice = 0;
                }
                break;
            default:
                break;
        }

        clear();
    }
    


    refresh();



    // Wait for user input
    getch();

    // Clean up
    endwin();
}
#include<iostream>
#include<ncurses.h>
#include<fstream>
#include"struct.h"
#include "Utility.h"
#include "normalMode.h"
#include "difficultMode.h"
#include "checkDifficult.h"
using namespace std;

int main() {
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    clear();

    // Box2** board = new Box2*[BOARDHEIGTH + 2];
    // initList(board);

    // renderList(board);

    // position p1,p2;

    // p1.x = 2;
    // p2.y = 3;
    // p1.y = 1;
    // p2.x = 2;
    // move(1,1);
    // if(Icheck(board, p1, p2)) {
    //     printw("true");
    // }else {
    //     printw("false");
    // }

    // player p;
    // char name[30] = "yoyo";
    // strcpy(p.name, name);
    // p.point = 200;
    // normalMode(p);

    readLeaderBoard();

    // Box2** board = new Box2* [BOARDHEIGTH];
    // initList(board);
    // renderList(board);
    // findTheNode(board, 0, 4) -> deleteBox();


    getch();
    clear();

    refresh();


    // Clean up
    endwin();
    return 0;
}
#include "normalMode.h"
#include<cstdlib>
#include<ctime>

void initBoard(Box1** board) {
    for (int i = 0; i < BOARDHEIGTH; i++) { // gan vi tri cho tung o mot
        board[i] = new Box1[BOARDWIDTH];
        for (int j = 0; j < BOARDWIDTH; j++) {
            board[i][j].j = j;
            board[i][j].i = i;
        }
    }

    srand(time(NULL));

    int flagNum = (BOARDWIDTH * BOARDHEIGTH) / 2;
    while (flagNum) { // gan ky tu cho tung o mot
        int index, time = 2;
        char c = 65 + rand() % 26;
        while (time) { // gan 1 ky tu cho 2 o
            index = rand() % (BOARDWIDTH * BOARDHEIGTH);
            if (board[index / 8][index % 8].c == ' ') {
                board[index / 8][index % 8].c = c;
                time--;
            }
        }
        flagNum--;
    }
}

void renderBoard(Box1** board) {
    for (int i = 0; i < BOARDHEIGTH; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            board[i][j].drawBox();
        }
    }
}
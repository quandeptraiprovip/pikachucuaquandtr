#include "normalMode.h"
#include<cstdlib>
#include<ctime>
#include <unistd.h>

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
            if (board[index / 6][index % 6].c == ' ') {
                board[index / 6][index % 6].c = c;
                time--;
            }
        }
        flagNum--;
    }
}

void renderBoard(Box1** board) {
    for (int i = 0; i < BOARDHEIGTH; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            board[i][j].drawBox(0);
        }
    }
}

void deleteBoard(Box1** board) {
    for (int i = 0; i < BOARDHEIGTH; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            if (board[i][j].isValid) {
                board[i][j].deleteBox();
                //sleep(1);
            }
        }
    }

    for (int i = 0; i < BOARDHEIGTH; i++) {
        delete[]board[i];
    }
    delete[]board;
}

//status 0 dang choi game
//       1 het game
//       2 nguoi choi esc

void move(Box1** board, position& pos, int& status, player& p, position selectedPos[], int& couple) {
    int key;
    // if(key == 27)//key escape
    // {
    //     status = 2;
    // }else if(key = KEY_ENTER) {
        
    // }       
}
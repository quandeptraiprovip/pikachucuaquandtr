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
    if(key == 27)//key escape
    {
        status = 2;
    }else if(key == KEY_ENTER) {
        if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y)//chon trung nhau
        {
            board[selectedPos[0].y][selectedPos[0].x].drawBox(2);
            board[selectedPos[0].y][selectedPos[0].x].isSelected = false;
            couple = 2;
            selectedPos[0].x = -1;
            selectedPos[0].y = -1;
            p.life--;
            move (0,50);
            printw("Life: %d", p.life);
        }else {
            selectedPos[2 - couple].x = pos.x;
            selectedPos[2 - couple].y = pos.y;
            board[pos.y][pos.x].isSelected = 1;
            couple--;
            //to be continue
        }
    }       
}

// move(0, 2);
// printw("Name: ");
// move (0, 30);
// printw("Point: ");
// move (0,50);
// printw("Life: ");
// move (5, 63);
// printw("- Press arrow key");
// move (6, 68);
// printw("to move");
// move (8, 63);
// printw("- Press ENTER key");
// move(9, 68);
// printw("to choose");
// move (11, 63);
// printw("- Press ESC key");
// move (12, 68);
// printw("to quit");
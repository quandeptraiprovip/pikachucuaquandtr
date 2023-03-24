#include "normalMode.h"
#include "checkNormal.h"
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
    //keypad(stdscr, TRUE);
    int key;
    key = getch();
    if(key == 'q')//key escape
    {
        status = 2;
    }else if(key == '\n') {
        if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y)//chon trung nhau
        {
            board[selectedPos[0].x][selectedPos[0].y].drawBox(2);
            board[selectedPos[0].x][selectedPos[0].y].isSelected = false;
            refresh();
            napms(500);


            couple = 2;
            selectedPos[0].x = -1;
            selectedPos[0].y = -1;
            p.life--;
            move (0,50);
            printw("Life: %d", p.life);
        }else {
            selectedPos[2 - couple].x = pos.x;
            selectedPos[2 - couple].y = pos.y;
            board[pos.x][pos.y].isSelected = true;
            couple--;

            if(couple == 0) {
                if (board[selectedPos[0].x][selectedPos[0].y].c == board[selectedPos[1].x][selectedPos[1].y].c) {
                    if (allcheck(board, selectedPos[0], selectedPos[1])) {
                        p.point += 20;
                        move (0, 30);
                        printw("Point: %d", p.point);

                        board[selectedPos[0].x][selectedPos[0].y].drawBox(1);
                        board[selectedPos[1].x][selectedPos[1].y].drawBox(1);

                        refresh();
                        napms(500);

                        board[selectedPos[0].x][selectedPos[0].y].isValid = 0;
                        board[selectedPos[0].x][selectedPos[0].y].deleteBox();

                        board[selectedPos[1].x][selectedPos[1].y].isValid = 0;
                        board[selectedPos[1].x][selectedPos[1].y].deleteBox();
                    }else {
                        board[selectedPos[0].x][selectedPos[0].y].drawBox(2);
                        board[selectedPos[1].x][selectedPos[1].y].drawBox(2);

                        refresh();
                        napms(500);

                        p.life--;
                        move (0,50);
                        printw("Life: %d", p.life);
                    }
                }else {
                    board[selectedPos[0].x][selectedPos[0].y].drawBox(2);
                    board[selectedPos[1].x][selectedPos[1].y].drawBox(2);

                    refresh();
                    napms(500);

                    p.life--;
                    move (0,50);
                    printw("Life: %d", p.life);
                }

                board[selectedPos[0].x][selectedPos[0].y].isSelected = 0;
                board[selectedPos[1].x][selectedPos[1].y].isSelected = 0;
                couple = 2;
                selectedPos[0].x = 1;
                selectedPos[0].y = -1;
                selectedPos[1].x = -1;
                selectedPos[1].y = -1;

                // tim curPos moi
                for (int i = pos.x; i < BOARDHEIGTH; i++) {
                    for (int j = pos.y; j < BOARDWIDTH; j++) {
                        if (board[i][j].isValid) {
                            pos.x = i;
                            pos.y = j;
                            return;
                        }
                    }
                }

                for (int i = 0; i <= pos.x; i++) {
                    for (int j = 0; j <= pos.y; j++) {
                        if (board[i][j].isValid) {
                            pos.x = i;
                            pos.y = j;
                            return;
                        }
                    }
                }
            }
        }
    }else //neu la dau mui ten
    {
        //ktra xem o nay co dc chon k
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)){
            board[pos.x][pos.y].isSelected = 0;
        }

        switch (key)
        {
        case KEY_UP:
            for (int i = pos.x; i < BOARDWIDTH; i++) {
                for (int j = pos.x - 1; j >= 0; j--) {
                    if (board[i][j].isValid) {
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i >= 0; i--) {
                for (int j = pos.y - 1; j >= 0; j--) {
                    if (board[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < BOARDWIDTH; i++) {
                for (int j = BOARDHEIGTH - 1; j > pos.y; j--) {
                    if (board[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i >= 0; i--) {
                for (int j = BOARDHEIGTH - 1; j > pos.y; j--) {
                    if (board[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            break;
        case KEY_DOWN:
            for (int i = pos.x; i < BOARDWIDTH; i++) {
                for (int j = pos.y + 1; j < BOARDHEIGTH; j++) {
                    if (board[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i >= 0; i--) {
                for (int j = pos.y + 1; j < BOARDHEIGTH; j++) {
                    if (board[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < BOARDWIDTH; i++) {
                for (int j = 0; j < pos.y; j++) {
                    if (board[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i >= 0; i--) {
                for (int j = 0; j < pos.y; j++) {
                    if (board[j][i].isValid) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }
            break;
        case KEY_LEFT:
            for (int i = pos.y; i >= 0; i--) {
                for (int j = pos.x - 1; j >= 0; j--) {
                    if (board[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < BOARDHEIGTH; i++) {
                for (int j = pos.x - 1; j >= 0; j--) {
                    if (board[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i >= 0; i--) {
                for (int j = BOARDWIDTH - 1; j > pos.x; j--) {
                    if (board[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < BOARDHEIGTH; i++) {
                for (int j = BOARDWIDTH - 1; j > pos.x; j--) {
                    if (board[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }
            break;
        case KEY_RIGHT:
            for (int i = pos.y; i >= 0; i--) {
                for (int j = pos.x + 1; j < BOARDWIDTH; j++) {
                    if (board[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < BOARDHEIGTH; i++) {
                for (int j = pos.x + 1; j < BOARDWIDTH; j++) {
                    if (board[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i >= 0; i--) {
                for (int j = 0; j < pos.x; j++) {
                    if (board[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < BOARDHEIGTH; i++) {
                for (int j = 0; j < pos.x; j++) {
                    if (board[i][j].isValid) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }
        default:
            break;
        }
    }       
}

void normalMode(player& p) {

    Box1** board = new Box1 * [BOARDHEIGTH];
    initBoard(board);

    move(0, 2);
    printw("Name: %s", p.name);
    move (0, 30);
    printw("Point: %d", p.point);
    move (0,50);
    printw("Life: %d", p.life);

    move (5, 63);
    printw("- Press arrow key");
    move (6, 68);
    printw("to move");
    move (8, 63);
    printw("- Press ENTER key");
    move(9, 68);
    printw("to choose");
    move (11, 63);
    printw("- Press ESC key");
    move (12, 68);
    printw("to quit");

    position selectedPos[] = { {-1, -1}, {-1, -1} };
    int couple = 2;
    position curPosition;
    curPosition.x = 0;
    curPosition.y = 0;
    int status = 0; //0. dang choi game
                    //1. het game
                    //2. nguoi choi chon thoat

    while (!status && p.life) {
        board[curPosition.x][curPosition.y].isSelected = 1;

        renderBoard(board);

        move(board, curPosition, status, p, selectedPos, couple);

        if ((!checkValidPairs(board))) status = 1;
    }

    renderBoard(board);
    deleteBoard(board);
    clear();

    if (p.life && status == 1) {
        displayStatus(1);
        move(LINES/2 - 20, COLS/2);
        char c;
        printw("Do you want to continue next game? (Y/N): ");
        cin >> c;
        cin.ignore();
        system("cls");
        if (c == 'y' || c == 'Y') normalMode(p);
        //else writeLeaderBoard(p);
    }
    else if (p.life == 0) {
        displayStatus(0);
        //writeLeaderBoard(p);
    }
    clear();
}


// chua sua phan move
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
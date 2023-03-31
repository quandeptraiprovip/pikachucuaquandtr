#include "difficultMode.h"
#include "checkDifficult.h"

void addTail(Box2 *&list, Box2 *p) {
    if (list == NULL) {
        list = p;
    }
    else {
        Box2* temp = list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void initList(Box2** arr) {
    for (int i = 0; i < BOARDHEIGTH; i++) {
        arr[i] = NULL;
        for (int j = 0; j < BOARDWIDTH; j++) {
            Box2* p = new Box2;
            p->i = i;
            p->j = j;
            p->next = NULL;
            addTail(arr[i], p);
        }
    }

    int flagNum = BOARDWIDTH*BOARDHEIGTH / 2;
    while (flagNum) {
        int index, time = 2;
        char c = 65 + rand() % 26;
        while (time)
        {
            index = rand() % (BOARDWIDTH*BOARDHEIGTH);
            Box2* p = findTheNode(arr, index / BOARDWIDTH, index % BOARDWIDTH);
            if (p->c == ' ') {
                p->c = c;
                time--;
            }
        }
        flagNum--;
    }
}

void deleteList(Box2** arr) {
    for (int i = 0; i < BOARDHEIGTH; i++) {
        Box2* temp;
        while (arr[i] != NULL)
        {
            temp = arr[i];
            arr[i] = arr[i]->next;
            temp->deleteBox();
            delete temp;
        }
    }
    delete[]arr;
}

void renderList(Box2** arr) {
    for (int i = 0; i < BOARDHEIGTH; i++) {
        Box2* temp = arr[i];
        while (temp != NULL)
        {
            temp->drawBox(0);
            temp = temp->next;
        }
    }
}

void hint(Box2** board) {
    Box2* Head, * temp;
    for (int i = 0; i < BOARDHEIGTH; i++) {
        Head = board[i];
        while (Head != NULL) {
            int j = i;
            temp = Head->next;
            while (temp == NULL && j < BOARDHEIGTH - 1) {
                j++;
                temp = board[j];
            }
            while (temp != NULL) {
                if (Head->c == temp->c) {
                    position p1;
                    p1.x = Head -> i;
                    p1.y = Head -> j;
                    position p2;
                    p2.x = temp -> i;
                    p2.y = temp -> j;
                    if (allCheck(board, p1, p2)) {
                        findTheNode(board ,p1.x, p2.x) -> drawBox(3);
                        findTheNode(board, p2.x, p2.y) -> drawBox(3);
                    }
                }
                temp = temp->next;
                if ((temp == NULL) && (j < BOARDHEIGTH - 1)) {
                    j++;
                    temp = findTheNode(board, j, 0);
                }
            }
            Head = Head->next;
        }
    }
}

void move(Box2** board, position& pos, int &status, player& p, position selectedPos[], int &couple) {
    int key;
    key = getch();

    if(key == 'q')//key escape
    {
        status = 2;
    }else if(key == '\n') {
        if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y)//chon trung nhau
        {
            Box2 *temp = findTheNode(board, pos.x, pos.y);
            temp -> drawBox(2);
            temp -> isSelected = false;
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
            findTheNode(board, pos.x, pos.y) -> isSelected = true;
            couple--;

            if(couple == 0) {
                Box2 *p1 = findTheNode(board, selectedPos[0].x, selectedPos[0].y);
                Box2 *p2 = findTheNode(board, selectedPos[1].x, selectedPos[1].y);

                if (p1 -> c == p2 -> c) {
                    if (allCheck(board, selectedPos[0], selectedPos[1])) {
                        p.point += 20;
                        move (0, 30);
                        printw("Point: %d", p.point);

                        p1 -> drawBox(1);
                        p2 -> drawBox(1);

                        refresh();
                        napms(500);

                        p1 -> isSelected = false;
                        p2 -> isSelected = false;
                        del(board, selectedPos[0], selectedPos[1]);
                    }else {
                        p1 -> drawBox(2);
                        p2 -> drawBox(2);

                        refresh();
                        napms(500);

                        p.life--;
                        move (0,50);
                        printw("Life: %d", p.life);
                    }
                }else {
                    p1 -> drawBox(2);
                    p2 -> drawBox(2);

                    refresh();
                    napms(500);

                    p.life--;
                    move (0,50);
                    printw("Life: %d", p.life);
                }

                couple = 2;
                selectedPos[0].x = 1;
                selectedPos[0].y = -1;
                selectedPos[1].x = -1;
                selectedPos[1].y = -1;

                // tim curPos moi
                for (int i = pos.x; i < BOARDHEIGTH; i++) {
                    for (int j = pos.y; j < BOARDWIDTH; j++) {
                        if (findTheNode(board, i, j) != NULL) {
                            pos.x = i;
                            pos.y = j;
                            return;
                        }else {
                            break;
                        }
                    }
                }

                for (int i = 0; i <= pos.x; i++) {
                    for (int j = 0; j <= pos.y; j++) {
                        if (findTheNode(board, i, j) != NULL) {
                            pos.x = i;
                            pos.y = j;
                            return;
                        }else {
                            break;
                        }
                    }
                }
            }
        }
    }else if(key == 'h') {
        hint(board);
    }
    else //neu la dau mui ten
    {
        //ktra xem o nay co dc chon k
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)){
            findTheNode(board, pos.x, pos.y) -> isSelected = false;
        }

        switch (key)
        {
        case KEY_UP:
            for (int i = pos.y; i < BOARDWIDTH; i++) {
                for (int j = pos.x - 1; j >= 0; j--) {
                    if (findTheNode(board, j, i) != NULL) {
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }

            for (int i = pos.y - 1; i >= 0; i--) {
                for (int j = pos.x - 1; j >= 0; j--) {
                    if (findTheNode(board, j, i) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i < BOARDWIDTH; i++) {
                for (int j = BOARDHEIGTH - 1; j > pos.x; j--) {
                    if (findTheNode(board, j, i) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i >= 0; i--) {
                for (int j = BOARDHEIGTH - 1; j > pos.x; j--) {
                    if (findTheNode(board, j, i) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            break;
        case KEY_DOWN:
            for (int i = pos.y; i < BOARDWIDTH; i++) {
                for (int j = pos.x + 1; j < BOARDHEIGTH; j++) {
                    if (findTheNode(board, j, i) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y - 1; i >= 0; i--) {
                for (int j = pos.x + 1; j < BOARDHEIGTH; j++) {
                    if (findTheNode(board, j, i) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i < BOARDWIDTH; i++) {
                for (int j = 0; j < pos.x; j++) {
                    if (findTheNode(board, j, i) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y - 1; i >= 0; i--) {
                for (int j = 0; j < pos.x; j++) {
                    if (findTheNode(board, j, i) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }
            break;
        case KEY_LEFT:
            for (int i = pos.x; i >= 0; i--) {
                for (int j = pos.y - 1; j >= 0; j--) {
                    if (findTheNode(board, i, j) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x + 1; i < BOARDHEIGTH; i++) {
                for (int j = pos.y - 1; j >= 0; j--) {
                    if (findTheNode(board, i, j) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i >= 0; i--) {
                for (int j = BOARDWIDTH - 1; j > pos.y; j--) {
                    if (findTheNode(board, i, j) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x + 1; i < BOARDHEIGTH; i++) {
                for (int j = BOARDWIDTH - 1; j > pos.y; j--) {
                    if (findTheNode(board, i, j) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }
            break;
        case KEY_RIGHT:
            for (int i = pos.x; i >= 0; i--) {
                for (int j = pos.y + 1; j < BOARDWIDTH; j++) {
                    if (findTheNode(board, i, j) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x + 1; i < BOARDHEIGTH; i++) {
                for (int j = pos.y + 1; j < BOARDWIDTH; j++) {
                    if (findTheNode(board, i, j) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i >= 0; i--) {
                for (int j = 0; j < pos.y; j++) {
                    if (findTheNode(board, i, j) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x + 1; i < BOARDHEIGTH; i++) {
                for (int j = 0; j < pos.y; j++) {
                    if (findTheNode(board, i, j) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }
        default:
            break;
        }
    }
}


void difficultMode(player& p) {

    Box2** board = new Box2 * [BOARDHEIGTH + 2];
    initList(board);

    move(0, 2);
    printw("Name: %s", p.name);
    move (0, 30);
    printw("Point: %d", p.point);
    move (0,COLS - 25);
    printw("Life: %d", p.life);

    move (5, COLS - 17);
    printw("- Press arrow key");
    move (6, 68);
    printw("to move");
    move (8, COLS - 17);
    printw("- Press ENTER key");
    move(9, 68);
    printw("to choose");
    move (11, COLS - 17);
    printw("- Press ESC key");
    move (12, 68);
    printw("to quit");
    move(14, COLS - 17);
    printw("-   Press H ");
    move(15, 66);
    printw("to get hint");

    position selectedPos[] = { {-1, -1}, {-1, -1} };
    int couple = 2;
    position curPosition;
    curPosition.x = 0;
    curPosition.y = 0;
    int status = 0; //0. dang choi game
                    //1. het game
                    //2. nguoi choi chon thoat

    while (!status && p.life) {
        findTheNode(board, curPosition.x, curPosition.y) -> isSelected = true;

        renderList(board);
        move(board, curPosition, status, p, selectedPos, couple);

        if((!checkValidPairs(board))) status = 1;
    }

    renderList(board);
    deleteList(board);
    clear();

//     if (p.life || status == 1) {
//         displayStatus(1);
//         refresh();
//         napms(5000);
//         move(LINES/2 - 20, COLS/2);
//         char c;
//         printw("Do you want to continue next game? (Y/N): ");
//         cin >> c;
//         cin.ignore();
//         system("cls");
//         if (c == 'y' || c == 'Y') difficultMode(p);
//         //else writeLeaderBoard(p);
//     }
//     else if (p.life == 0) {
//         displayStatus(0);
//         //writeLeaderBoard(p);
//     }
//     clear();
    }

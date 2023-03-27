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
    for (int i = 1; i < BOARDHEIGTH + 2; i++) {
        arr[i] = NULL;
        for (int j = 1; j < BOARDWIDTH + 2; j++) {
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
            Box2* p = findTheNode(arr, index / BOARDWIDTH + 1, index % BOARDWIDTH + 1);
            if (p->c == ' ') {
                p->c = c;
                time--;
            }
        }
        flagNum--;
    }
}

void deleteList(Box2** arr) {
    for (int i = 1; i < BOARDHEIGTH + 1; i++) {
        Box2* temp;
        while (arr[i] != NULL)
        {
            temp = arr[i];
            arr[i] = arr[i]->next;
            temp->deleteBox();
            //if (temp->j < 4) displayBackground(BG, temp->j, i);
            delete temp;
        }
    }
    delete[]arr;
}

void renderList(Box2** arr) {
    for (int i = 1; i < BOARDHEIGTH + 1; i++) {
        Box2* temp = arr[i];
        while (temp -> next != NULL)
        {
            temp->drawBox(0);
            temp = temp->next;
        }
    }
}
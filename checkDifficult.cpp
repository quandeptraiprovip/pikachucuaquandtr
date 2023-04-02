#include "checkDifficult.h"

Box2* findTheNode(Box2** arr, int x, int y) {
    if (x < 0 || x >= BOARDHEIGTH || y < 0 || y >= BOARDWIDTH) return NULL;

    Box2* temp = arr[x];
    while (temp != NULL) {
        if (temp->j == y) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

bool Icheck(Box2 **board, position p1, position p2) {
    if(p1.x == p2.x) {
        if(p1.x == 0 || p1.x == BOARDHEIGTH - 1) {
            return true;
        }

        int minY = min(p1.y, p2.y);
        int maxY = max(p1.y, p2.y);
        int i = 1;

        while(minY + i < maxY && findTheNode(board, p1.x, minY + i) == NULL) {
            i ++;
        }

        if(i == maxY - minY) {
            return true;
        }else {
            return false;
        }

    }else if(p1.y == p2.y) {
        if(p1.y == 0) {
            return true;
        }

        int maxX = max(p2.x, p1.x);
        int minX = min(p2.x, p1.x);

        int i = 1;
        while(minX + i < maxX && findTheNode(board, minX + i, p1.y) == NULL) {
            i++;
        }

        if(i == maxX - minX) {
            return true;
        }else {
            return false;
        }
    }

    return false;
}

bool Lcheck(Box2** board, position p1, position p2) {
    position p;
    p.x = p1.x;
    p.y = p2.y;
    if(Icheck(board, p1, p) && Icheck(board, p, p2) && findTheNode(board, p1.x, p2.y) == NULL) {
        return true;
    }

    p.x = p2.x;
    p.y = p1.y;
    if(Icheck(board, p1, p) && Icheck(board, p2, p) && findTheNode(board, p2.x, p1.y) == NULL) {
        return true;
    }

    return false;
}

bool Zcheck(Box2** board, position p1, position p2) {
    position minP;
    position maxP;

    if(p1.x > p2.x) {
        minP = p2;
        maxP = p1;
    }else {
        minP = p1;
        maxP = p2;
    }

    for(int i = minP.x + 1; i < maxP.x; i ++) {
        position p;
        p.x = i;
        p.y = minP.y;
        position t;
        t.x = i;
        t.y = maxP.y;

        if(Icheck(board, minP, p) && Icheck(board, p, t) && Icheck(board, t, maxP) && findTheNode(board, p.x, p.y) == NULL && findTheNode(board, t.x, t.y) == NULL) {
            return true;
        }
    }

    if(p1.y > p2.y) {
        minP = p2;
        maxP = p1;
    }else {
        minP = p1;
        maxP = p2;
    }

    for(int i = maxP.x - 1; i > minP.x; i --) {
        position p;
        p.x = maxP.x;
        p.y = i;
        position t;
        t.x = minP.x;
        t.y = i;

        if(Icheck(board, maxP, p) && Icheck(board, p, t) && Icheck(board, t, minP) && findTheNode(board, p.x, p.y) == NULL && findTheNode(board, t.x, t.y) == NULL) {
            return true;
        }
    }

    return false;
}

bool UXcheck(Box2 **board, position p1, position p2) {
    position minP, maxP;

    if (p1.y > p2.y) {
        maxP = p1;
        minP = p2;
    }else {
        maxP = p2;
        minP = p1;
    }

    position p;
    p.x = minP.x;
    p.y = maxP.y;
    position t;
    t.x = maxP.x;
    t.y = maxP.y + 1;
    if(p2.y != p1.y) {
        if(Icheck(board, minP, p) && findTheNode(board, p.x, p.y) == NULL) {
            p.y ++;
            while(p.y < BOARDWIDTH + 1 && findTheNode(board, p.x, p.y) == NULL && findTheNode(board, t.x, t.y) == NULL) {
                if(Icheck(board, p, t)) {
                    return true;
                }

                p.y ++;
                t.y ++;
            }
        }
    }else {
        p.y ++;
        t.y ++;

        while(p.y < BOARDWIDTH + 1 && findTheNode(board, p.x, p.y) == NULL && findTheNode(board, t.x, t.y) == NULL) {
            if(Icheck(board, p, t)) {
                return true;
            }

            p.y ++;
            t.y ++;
        }
    }

    return false;
}

bool UYcheck(Box2** board, position p1, position p2, int mode) {
    position minP, maxP;

    if(p1.x > p2.x) {
        minP = p2;
        maxP = p1;
    }else {
        minP = p1;
        maxP = p2;
    }

    if(mode == -1) {
        position temp;
        temp = minP;
        minP = maxP;
        maxP = temp;
    }

    position p, t;
    p.x = maxP.x + mode;
    p.y = maxP.y;
    t.x = maxP.x;
    t.y = minP.y;
    if(p.x != t.x) {
        if(Icheck(board, minP, t) && findTheNode(board, t.x, t.y) ==  NULL){
            t.x += mode;
            while(t.x < BOARDHEIGTH + 1 && findTheNode(board, p.x, p.y) == NULL && findTheNode(board, t.x, t.y) == NULL) {
                if(Icheck(board, p, t)) {
                    return true;
                }
                p.x += mode;
                t.x += mode;
            }
        }
    }else {
        p.x += mode;
        t.x += mode;

        while(p.x < BOARDHEIGTH + 1 && findTheNode(board, p.x, p.y) == NULL && findTheNode(board, t.x, t.y) == NULL) {
            if(Icheck(board, p, t)) {
                return true;
            }

            p.x += mode;
            t.x += mode;
        }
    }

    return false;
}

bool allCheck(Box2** board, position p1, position p2) {
    if(p1.x == p2.x || p1.y == p2.y) {
        if(Icheck(board, p1, p2)) {
            return true;
        }
    }

    if(Lcheck(board, p1, p2)) {
        return true;
    }

    if(Zcheck(board, p1, p2)) {
        return true;
    }

    if(UXcheck(board, p1, p2)) {
        return true;
    }

    if(UYcheck(board, p1, p2, 1)) {
        return true;
    }

    if(UYcheck(board, p1, p2, -1)) {
        return true;
    }

    return false;
}

bool checkValidPairs(Box2** board) {
    Box2* Head, * temp;
    for (int i = 1; i < BOARDHEIGTH + 1; i++) {
        Head = board[i];
        while (Head != NULL) {
            int j = i;
            temp = Head->next;
            while (temp == NULL && j < BOARDHEIGTH) {
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
                        return true;
                    }
                }
                temp = temp->next;
                if ((temp == NULL) && (j < BOARDHEIGTH)) {
                    j++;
                    temp = findTheNode(board, j, 0);
                }
            }
            Head = Head->next;
        }
    }
    return false;
}

void del(Box2** board, position p1, position p2) {
    if(p1.x > p2.x) {
        delNode(board, p1.x, p1.y);
        delNode(board, p2.x, p2.y);
    }else {
        delNode(board, p2.x, p2.y);
        delNode(board, p1.x, p1.y);
    }
}

void delNode(Box2** arr, int y, int x) {
    Box2* p = findTheNode(arr, y, x);
    if (x == 0) {
        if (arr[y] -> next == NULL) {
            arr[y] -> deleteBox();
            arr[y] = NULL;
            return;
        }
        p = arr[y];
        while(p -> next) {
            p -> c = p -> next -> c;
            p = p -> next;
        }

        p -> deleteBox();
        findTheNode(arr, p -> i, p -> j - 1) -> next = NULL;
    }
    else if (p->next != NULL) {
        while (p->next->next != NULL)
        {
            p->c = p->next->c;
            p = p->next;
        }
        p->c = p->next->c;
        p->next->deleteBox();
        delete p->next;
        p->next = NULL;
    }
    else {
        p->deleteBox();
        delete p;
        p = findTheNode(arr, y, x - 1);
        p->next = NULL;
    }
}


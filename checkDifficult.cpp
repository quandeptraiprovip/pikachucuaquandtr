#include "checkDifficult.h"

Box2* findTheNode(Box2** arr, int x, int y) {
    if (x < 0 || x > BOARDHEIGTH + 1 || y < 0 || y > BOARDWIDTH + 1) return NULL;

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
        if(p1.x == 1 || p1.x == BOARDHEIGTH + 1) {
            return true;
        }

        int minY = min(p1.y, p2.y);
        int maxY = max(p1.y, p2.y);

        if(maxY != minY + 1){
            Box2 *temp = findTheNode(board, p1.x, minY + 1);

            int i = 2;
            while(temp == NULL && i < maxY - minY) {
                temp = findTheNode(board, p1.x, minY + i);
                i ++;
            }

            if(temp -> j == maxY - 1) {
                return true;
            }
        }else {
            return true;
        }

        return false;
    }else if(p1.y == p2.y) {
        if(p1.y == 1) {
            return true;
        }

        int maxX = max(p2.x, p1.x);
        int minX = min(p2.x, p1.x);

        if(maxX != minX + 1) {
            Box2* temp = findTheNode(board, minX + 1, p1.y);

            int i = 2;
            while(temp == NULL && i < maxX - minX) {
                temp = findTheNode(board, minX + i, p1.y);
            }

            if(temp -> i == maxX - 1) {
                return true;
            }
        }else {
            return true;
        }

        return true;
    }
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
    
}
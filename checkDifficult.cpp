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

    if(Icheck(board, minP, p) && findTheNode(board, p.x, p.y) == NULL) {
        p.y ++;
        while(findTheNode(board, p.x, p.y) == NULL && findTheNode(board, t.x, t.y) == NULL) {
            if(Icheck(board, p,t)) {
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
    t.x = maxP.x + mode;
    t.y = minP.y;

    while(findTheNode(board, p.x, p.y) == NULL && findTheNode(board, t.x, t.y) == NULL) {
        if(Icheck(board, p, t)) {
            return true;
        }
        p.x += mode;
        t.x += mode;
    }

    return false;
}

bool allCheck(Box2** board, position p1, position p2) {
    if(p1.x == p2.x || p1.y == p2.y) {
        if(Icheck(board, p1, p2)) {
            return true;
        }else if(Icheck(board, p1, p2)) {
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
    }else if(UYcheck(board, p1, p2, -1)) {
        return true;
    }


    return false;
}

bool checkValidPairs(Box2** board) {
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0;
        int* pos = new int[BOARDHEIGTH * BOARDWIDTH];
        for (int i = 1; i < BOARDHEIGTH + 1; i++) {
            for (int j = 1; j < BOARDWIDTH + 1; j++) {
                if (board[i][j].c == check && findTheNode(board, i, j) != NULL) {
                    pos[cnt++] = i;
                    pos[cnt++] = j;
                }
            }
        }
        for (int i = 0; i < cnt - 2; i += 2) {
            for (int j = i + 2; j < cnt; j += 2) {
                position p1;
                p1.x = pos[i];
                p1.y = pos[i + 1];
                position p2;
                p2.x = pos[j];
                p2.y = pos[j + 1];
                if (allCheck(board, p1, p2)) {
                    delete[] pos;
                    return true;
                }
            }
        }
        check++;
        delete[] pos;
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

Box2* delHead(Box2* l) {
    Box2* temp = l;
    temp = temp -> next;
    delete(l);
    return temp;
}

Box2* delTail(Box2* l) {
    Box2* temp = l;
    while(temp -> next -> next != NULL) {
        temp = temp -> next;
    }

    delete(temp -> next);
    temp -> next = NULL;
    return l;
} 

Box2* delAt(Box2* l, int k) {
    Box2 *p = l;
	for (int i = 0; i < k - 2; i++){
		p = p->next;
	}

	Box2 *temp = p->next;
	p->next = p->next->next;
	delete(temp);
	return l;
}

void delNode(Box2** board, int x, int y) {
    if(y == 1) {
        board[x] = delHead(board[x]);
    }else if(findTheNode(board, x, y) -> next == NULL) {
        board[x] = delTail(board[x]);
    }else {
        board[x] = delAt(board[x], y);
    }
}
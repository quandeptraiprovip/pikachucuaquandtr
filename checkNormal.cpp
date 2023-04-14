#include"checkNormal.h"

int checkLineX (Box1** board, int y1, int y2, int x) {

    // if(x == 1 || x == BOARDHEIGTH) return 1;
    if(y1 == y2) return 0;

    int maxY = max(y1, y2);
    int minY = min(y1, y2);

    if(maxY == minY + 1) {
        return 1;
    }

    for(int i = minY + 1; i < maxY; i++) {
        if (board[x][i].isValid == true) {
            return 0;
        }
    }
    
    return 1;
}

int checkLineY(Box1** board, int x1, int x2, int y) {

    // if(y == 1 || y == BOARDWIDTH) return 1;
    if(x1 == x2) return 0;

    int maxX = max(x1, x2);
    int minX = min(x1, x2);

    if(maxX == minX + 1) {
        return 1;
    }


    for(int i = minX + 1; i < maxX; i++) {
        if(board[i][y].isValid == 1) {
            return 0;
        }
    }

    return 1;
}

int checkL(Box1** board, position p1, position p2) {

    position min, max;

    if(p1.y < p2.y) {
        min = p1;
        max = p2;
    }else {
        min = p2;
        max = p1;
    }

    if(checkLineX(board, min.y, max.y, min.x) && checkLineY(board, min.x, max.x, max.y) && board[min.x][max.y].isValid == false) {
        return 401;
    }

    if(checkLineY(board, min.x, max.x, min.y) && checkLineX(board, min.y, max.y, max.x) && board[max.x][min.y].isValid == false) {
        return 402;
    }

    //401 L right
    //402 L left

    return 0;
}

int checkZX(Box1** board, int x1, int y1, int x2, int y2) {
    int maxY, minY;
    int xOfMax, xOfMin;

    if(y1 > y2) {
        maxY = y1;
        minY = y2;
        xOfMax = x1;
        xOfMin = x2;
    }else {
        maxY = y2;
        minY = y1;
        xOfMax = x2;
        xOfMin = x1;
    }

    int i = minY + 1;
    for(i; i <= maxY; i++) {
        if((checkLineX(board, minY, i, xOfMin) && board[xOfMin][i].isValid == false) && 
            (checkLineY(board, xOfMin, xOfMax, i) && board[xOfMax][i].isValid == false) && 
            checkLineX(board, i, maxY, xOfMax)) {
            int res = 201 + 10*i;
            return res;
        }
    }

    return 0;
}

int checkZY(Box1** board, int x1, int y1, int x2, int y2) {
    int maxX, minX;
    int yOfMax, yOfMin;

    if(x1 > x2) {
        maxX = x1;
        minX = x2;
        yOfMax = y1;
        yOfMin = y2;
    }else {
        maxX = x2;
        minX = x1;
        yOfMax = y2;
        yOfMin = y1;
    }

    int i = minX + 1; 
    for(i; i <= maxX; i++) {
        if((checkLineY(board, minX, i, yOfMin) && board[i][yOfMin].isValid == false) && 
            (checkLineX(board, yOfMin, yOfMax, i) && board[i][yOfMax].isValid == false) && 
            checkLineY(board, i, maxX, yOfMax)) {
            int res = 202 + 10*i;
            return res;
        } 
    }

    return 0;
}

int checkUX(Box1** board, position p1, position p2, int type) {
    position pMinY = p1, pMaxY = p2;
    if (p1.y > p2.y) {
        pMinY = p2;
        pMaxY = p1;
    }

    int y = pMaxY.y;
    int row = pMinY.x;

    if (type == -1) {
        y = pMinY.y;
        row = pMaxY.x;
    }

    if(p1.y != p2.y) {
        if (checkLineX(board,pMinY.y, pMaxY.y, row) && board[row][y].isValid == false) {
            y += type;
            while (board[pMinY.x][y].isValid == false && board[pMaxY.x][y].isValid == false && (y >= 0 && y <= BOARDWIDTH + 1)) {
                if (checkLineY(board, pMinY.x, pMaxY.x, y)) {
                    int res = 301 + 10*y;
                    return res;
                }

                y += type;
            }
        }
    }else {
        y += type;
        while(y >= 0 && y <= BOARDWIDTH + 1 && board[pMaxY.x][y].isValid == false && board[pMinY.x][y].isValid == false) {
            if(checkLineY (board, pMaxY.x, pMinY.x, y)) {
                int res = 301 + 10*y;
                return res;
            }
            y += type;
        }
    }


    return 0;
}

int checkUY(Box1** board, position p1, position p2, int type) {
    position pMinX = p1, pMaxX = p2;
    if (p1.x > p2.x) {
        pMinX = p2;
        pMaxX = p1;
    }
    int x = pMaxX.x;
    int col = pMinX.y;
    if (type == -1) {
        x = pMinX.x;
        col = pMaxX.y;
    }

    if(p1.x != p2.x) {
        if (checkLineY(board ,pMinX.x, pMaxX.x, col) && board[x][col].isValid == false) {
            x += type;
            while (board[x][pMinX.y].isValid == false && board[x][pMaxX.y].isValid == false && (x >= 0 && x <= BOARDHEIGTH + 1)) {
                if (checkLineX(board ,pMinX.y, pMaxX.y, x)) {
                    int res = 302 + 10*x;
                    return res;
                }

                x += type;
            }
        }
    }else {
        x += type;
        while(x >= 0 && x <= BOARDHEIGTH + 1 && board[x][pMinX.y].isValid == false && board[x][pMaxX.y].isValid == false) {
            if(checkLineX (board, pMinX.y, pMaxX.y, x)) {
                int res = 302 + 10*x;
                return res;
            }
            x += type;
        }
    }

    return 0;
}

int allcheck(Box1** board, position p1, position p2) {

    if (p1.x == p2.x) {
        if (checkLineX(board ,p1.y, p2.y, p1.x)) {
            return checkLineX(board ,p1.y, p2.y, p1.x);
        }
    }

    if (p1.y == p2.y) {
        if (checkLineY(board ,p1.x, p2.x, p1.y)) {
            return checkLineY(board ,p1.x, p2.x, p1.y);
        }
    }

    if(checkL(board, p1, p2)) {
        return checkL(board, p1, p2);
    }

    if ((checkZX(board, p1.x, p1.y, p2.x, p2.y))) {
        return checkZX(board, p1.x, p1.y, p2.x, p2.y);
    }
 
    if ((checkZY(board, p1.x, p1.y, p2.x, p2.y))) {
        return checkZY(board, p1.x, p1.y, p2.x, p2.y);
    }

    if ((checkUX(board ,p1, p2, 1))) {
        return checkUX(board ,p1, p2, 1);
    }
    
    if ((checkUX(board ,p1, p2, -1))) {
        return checkUX(board ,p1, p2, -1);
    }

    if ((checkUY(board ,p1, p2, 1))) {
        return checkUY(board ,p1, p2, 1);
    }
    
    if ((checkUY(board ,p1, p2, -1))) {
        return checkUY(board ,p1, p2, -1);
    }


    return 0;
}

bool checkValidPairs(Box1** board) {
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0;
        int* pos = new int[BOARDHEIGTH * BOARDWIDTH];
        for (int i = 1; i < BOARDHEIGTH + 1; i++) {
            for (int j = 1; j < BOARDWIDTH + 1; j++) {
                if (board[i][j].c == check && board[i][j].isValid) {
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
                if (allcheck(board, p1, p2)) {
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
#include"checkNormal.h"

bool checkLineX (Box1** board, int y1, int y2, int x) {
    if(x == 0 && x == BOARDHEIGTH - 1) {
        return true;
    }

    int maxY = max(y1, y2);
    int minY = min(y1, y2);

    if(maxY == minY) {
        return true;
    }

    for(int i = minY + 1; i < maxY; i++) {
        if (board[x][i].isValid == true) {
            return false;
        }
    }

    return true;
}

bool checkLineY(Box1** board, int x1, int x2, int y) {
    if(y == 0 && y == BOARDWIDTH - 1) {
        return true;
    }

    int maxX = max(x1, x2);
    int minX = min(x1, x2);

    if(maxX == minX) {
        return true;
    }

    for(int i = minX + 1; i < maxX; i++) {
        if(board[i][y].isValid == true) {
            return false;
        }
    }

    return true;
}

bool checkZX(Box1** board, int x1, int y1, int x2, int y2) {
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
    
    if(board[xOfMin][minY + 1].isValid == true) {
        return false;
    }

    for(int i = minY + 1; i <= maxY; i++) {
        if(checkLineX(board, minY, i, xOfMin) && checkLineY(board, xOfMin, xOfMax, i) && checkLineX(board, i, maxY, xOfMax)) {
            return true;
        }
    }

    return false;
}

bool checkZY(Box1** board, int x1, int y1, int x2, int y2) {
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

    if(board[minX + 1][yOfMin].isValid == true) {
        return false;
    }

    for(int i = minX + 1; i <= maxX; i++) {
        if(checkLineY(board, minX, i, yOfMin) && checkLineX(board, yOfMin, yOfMax, i) && checkLineY(board, i, maxX, yOfMax)) {
            return true;
        } 
    }

    return false;
}

bool checkUX(Box1** board, position p1, position p2, int type) {
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

    y+= type;

    if(y == -1 || y == BOARDWIDTH) {
        if (checkLineX(board,pMinY.y, pMaxY.y, row) && board[row][y].isValid == false){
            return true;
        }else {
            return false;
        }
    }

    if (checkLineX(board,pMinY.y, pMaxY.y, row)) {
        while (board[pMinY.x][y].isValid == false && board[pMaxY.x][y].isValid == false && (y >= 0 || y < BOARDWIDTH)) {
            if (checkLineY(board, pMinY.x, pMaxY.x, y)) {
               return true;
            }

            y += type;
        }
    }

    if(y == -1 || y == BOARDWIDTH) {
        return true;
    }

    return false;
}

bool checkUY(Box1** board, position p1, position p2, int type) {
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

    x += type;

    if(x == -1 || x == BOARDHEIGTH) {
        if (checkLineY(board ,pMinX.x, pMaxX.x, col) && board[x][col].isValid == false){
            return true;
        }else {
            return false;
        }
    }

    if (checkLineY(board ,pMinX.x, pMaxX.x, col)) {
        while (board[x][pMinX.y].isValid == false && board[x][pMaxX.x].isValid == false && (x >= 0 || x < BOARDHEIGTH)) {
            if (checkLineX(board ,pMinX.y, pMaxX.y, x)) {
                return true;
            }

            x += type;
        }
    }

    if(x == -1 || x == BOARDHEIGTH) {
        return true;
    }

    return false;
}

bool allcheck(Box1** board, position p1, position p2) {
    if (p1.x == p2.x) {
        if (checkLineX(board ,p1.y, p2.y, p1.x)) {
            return true;
        }
    }

    if (p1.y == p2.y) {
        if (checkLineY(board ,p1.x, p2.x, p1.y)) {
            return true;
        }
    }

    if ((checkZX(board, p1.x, p1.y, p2.x, p2.y))) {
        return true;
    }
 
    if ((checkZY(board, p1.x, p1.y, p2.x, p2.y))) {
        return true;
    }

    if ((checkUX(board ,p1, p2, 1))) {
        return true;
    }
    
    if ((checkUX(board ,p1, p2, -1))) {
        return true;
    }

    if ((checkUY(board ,p1, p2, 1))) {
        return true;
    }
    
    if ((checkUY(board ,p1, p2, -1))) {
        return true;
    }

    return false;
}

bool checkValidPairs(Box1** board) {
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0;
        int* pos = new int[BOARDHEIGTH * BOARDWIDTH];
        for (int i = 0; i < BOARDHEIGTH; i++) {
            for (int j = 0; j < BOARDWIDTH; j++) {
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
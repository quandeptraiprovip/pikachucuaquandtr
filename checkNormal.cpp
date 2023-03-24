#include"checkNormal.h"

bool checkLineX (Box1** board, int y1, int y2, int x) {
    int maxY = max(y1, y2);
    int minY = min(y1, y2);

    for(int i = minY + 1; i < maxY; i++) {
        if (board[x][i].isValid == true) {
            return false;
        }
    }

    return true;
}

bool checkLineY(Box1** board, int x1, int x2, int y) {
    int maxX = max(x1, x2);
    int minX = min(x1, x2);

    for(int i = minX + 1; i <= maxX; i++) {
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

    for(int i = minX + 1; i <= maxX; i++) {
        if(checkLineY(board, minX, i, yOfMin) && checkLineX(board, yOfMin, yOfMax, i) && checkLineY(board, i, maxX, yOfMax)) {
            return true;
        } 
    }

    return false;
}
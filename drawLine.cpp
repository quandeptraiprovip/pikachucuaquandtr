#include "drawLine.h"
#include "Utility.h"

char ch[20][41];

void drawIX(int y1, int y2, int x) {
    int min;
    int max;

    if(y1 > y2) {
        max = y1;
        min = y2;
    }else {
        max = y2;
        min = y1;
    }

    move (x, min);
    for(int i = min; i <= max; i ++){
        printw("-");
    }
}

void drawIY(int x1, int x2, int y) {
    int min, max;
    
    if(x1 > x2) {
        max = x1;
        min = x2;
    }else {
        max = x2;
        min = x1;
    }

    for(int i = min; i <= max; i ++) {
        move (i, y);
        printw("|");
    }
}

void drawI(position p1, position p2) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    p1.x --;
    p1.y --;
    p2.x --;
    p2.y --;
    position pMax, pMin;

    if(p1.x == p2.x) {
        if(p1.y > p2.y){
            pMax = p1;
            pMin = p2;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 2, pMin.y*10 + 2 + 5 + 3); 
        printw("+");
        drawIX(pMin.y*10 + 2 + 5 + 4, pMax.y*10 + 2 + 1, p1.x*4 + 2 + 2);

        move(4*pMax.x + 2 + 2, pMax.y*10 + 2 + 2); 
        printw("+");

    }else if(p1.y == p2.y) {
        if(p1.x > p2.x) {
            pMax = p1;
            pMin = p2;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 3,pMin.y*10 + 2 + 5);
        printw("+");

        drawIY(4*pMax.x + 2, 4*pMin.x + 2 + 4, p1.y*10 + 2 + 5);

        move(4*pMax.x + 2 + 1, pMax.y*10 + 2 + 5);
        printw("+");
    }

    attroff(COLOR_PAIR(1));
}

void drawU(position p1, position p2, int x, int type) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    x--;
    p1.x --;
    p1.y --;
    p2.x --;
    p2.y --;
    position pMax, pMin;

    //if type 1 = UX
    if(type == 1) {
        if(p1.y > p2.y) {
            pMax = p1;
            pMin = p2;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 2, pMin.y*10 + 2 + 5 + 2); 
        printw("+");

        drawIX(pMin.y*10 + 2 + 5 + 3, x*10 + 2 + 5, 4*pMin.x + 2 + 2);
        drawIX(pMax.y*10 + 2 + 5 + 3, x*10 + 2 + 5, 4*pMax.x + 2 + 2);
        int min, max;
        if(pMin.x > pMax.x) {
            min = pMax.x;
            max = pMin.x;
        }else {
            min = pMin.x;
            max = pMax.x;
        }

        drawIY(min*4 + 2 + 3, max*4 + 2 + 1, x*10 + 2 + 5);

        move(4*pMax.x + 2 + 2, pMax.y*10 + 2 + 5 + 2); 
        printw("+");

    }else if (type == 2){
        if(p1.x > p2.x) {
            pMax = p1;
            pMin = p2;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 1, pMin.y*10 + 2 + 5);
        printw("+");

        drawIY(4*pMin.x + 2, x*4 + 2 + 3, pMin.y*10 + 2 + 5);
        drawIY(4*pMax.x + 2, x*4 + 2 + 3, pMax.y*10 + 2 + 5);
        int min, max;
        if(pMin.y > pMax.y) {
            min = pMax.y;
            max = pMin.y;
        }else {
            min = pMin.y;
            max = pMax.y;
        }
        drawIX(min*10 + 2 + 6, max*10 + 2 + 4, x*4 + 2 + 3);

        move(4*pMax.x + 2 + 1, pMax.y*10 + 2 + 5);
        printw("+");
    }

    attroff(COLOR_PAIR(1));
}

void drawZ(position p1, position p2, int x, int type) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    x--;
    p1.x --;
    p1.y --;
    p2.x --;
    p2.y --;

    position pMin, pMax;

    //if type 1 ZX
    if(type == 1) {

        if(p1.y > p2.y) {
            pMin = p2;
            pMax = p1;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 2, pMin.y*10 + 2 + 5 + 2); 
        printw("+");

        drawIX(pMin.y*10 + 2 + 5 + 3, x*10 + 2 + 5, 4*pMin.x + 2 + 2);
        drawIY(4*pMin.x + 2 + 2, 4*pMax.x + 2 + 2, x*10 + 2 + 5);
        drawIX(x*10 + 2 + 5, pMax.y*10 + 2 + 5 - 3, 4*pMax.x + 2 + 2);

        move(4*pMax.x + 2 + 2, pMax.y*10 + 2 + 5 - 2); 
        printw("+");
    }else if(type == 2) {
        if(p1.x > p2.x) {
            pMin = p2;
            pMax = p1;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 3, pMin.y*10 + 2 + 5);
        printw("+");

        drawIY(4*pMin.x + 2 + 4, 4*x + 2 + 2, pMin.y*10 + 2 + 5);
        drawIY(4*pMax.x + 2, 4*x + 2 + 2, pMax.y*10 + 2 + 5);
        drawIX(pMin.y*10 + 2 + 5, pMax.y*10 + 2 + 5, 4*x + 2 + 2);

        move(4*pMax.x + 2 + 1, pMax.y*10 + 2 + 5);
        printw("+");
    }

    attroff(COLOR_PAIR(1));
}

void drawL(position p1, position p2, int type) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    

    position pMax, pMin;
    if(p1.y > p2.y) {
        pMax = p1;
        pMin = p2;
    }else {
        pMax = p2;
        pMin = p1;
    }

    //if right
    if(type == 1) {

        position temp;
        temp.x = pMin.x;
        temp.y = pMax.y;

        drawI(pMin, temp);
        drawI(temp, pMax);
        attron(COLOR_PAIR(1));
        move(4*(temp.x - 1) + 2 + 2, (temp.y - 1)*10 + 2 + 5); 
        printw("0");
        move(4*(temp.x - 1) + 2 + 3,(temp.y - 1)*10 + 2 + 5);
        printw(" ");
        attroff(COLOR_PAIR(1));

    }else {
        position temp;
        temp.x = pMax.x;
        temp.y = pMin.y;

        drawI(temp, pMin);
        drawI(temp, pMax);

        attron(COLOR_PAIR(1));
        move(4*(temp.x - 1) + 2 + 2, (temp.y - 1)*10 + 2 + 5 + 1); 
        printw("0  ");
        move(4*(temp.x - 1) + 2 + 1, (temp.y - 1)*10 + 2 + 5);
        printw(" ");

        attroff(COLOR_PAIR(1));
    }

    attroff(COLOR_PAIR(1));
}

void delIX(int y1, int y2, int x) {
    getBG(ch);
    int min;
    int max;

    if(y1 > y2) {
        max = y1;
        min = y2;
    }else {
        max = y2;
        min = y1;
    }

    for(int i = min; i <= max; i ++){
        move (x, i);
        if(x >= 2  && i <= 43 && i >= 2) {
            printw("%c", ch[x - 2][i - 2]);
        }else {
            printw(" ");
        }
    }

}

void delIY(int x1, int x2, int y) {
    getBG(ch);
    int min, max;
    
    if(x1 > x2) {
        max = x1;
        min = x2;
    }else {
        max = x2;
        min = x1;
    }

    for(int i = min; i <= max; i ++) {
        move (i, y);
        if(i >= 2  && y <= 43 && y >= 2) {
            printw("%c", ch[i - 2][y - 2]);
        }else {
            printw(" ");    
        }
    }

}

void delI(position p1, position p2) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    p1.x --;
    p1.y --;
    p2.x --;
    p2.y --;
    position pMax, pMin;
    getBG(ch);

    if(p1.x == p2.x) {
        if(p1.y > p2.y){
            pMax = p1;
            pMin = p2;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 2, pMin.y*10 + 2 + 5 + 3); 
        if(pMin.y*10 + 2 + 5 + 3 <= 43) {
            printw("%c", ch[4*pMin.x + 2][pMin.y*10+ 5 + 3]);
        }else {
            printw(" ");
        }
        delIX(pMin.y*10 + 2 + 5 + 4, pMax.y*10 + 2 + 1, p1.x*4 + 2 + 2);

        move(4*pMax.x + 2 + 2, pMax.y*10 + 2 + 2);
        if(pMax.y*10 + 2 + 2 <= 43) {
            printw("%c", ch[4*pMax.x + 2][pMax.y*10 + 2]);
        } else {
            printw(" ");
        }

    }else if(p1.y == p2.y) {
        if(p1.x > p2.x) {
            pMax = p1;
            pMin = p2;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 3,pMin.y*10 + 2 + 5);
        if(pMin.y*10 + 2 + 5 <= 43) {
            printw("%c", ch[4*pMin.x + 3][pMin.y*10 + 5]);
        }else {
            printw(" ");
        }

        delIY(4*pMax.x + 2, 4*pMin.x + 2 + 4, p1.y*10 + 2 + 5);

        move(4*pMax.x + 2 + 1, pMax.y*10 + 2 + 5);
        if(pMax.y*10 + 2 + 5 <= 43) {
            printw("%c", ch[4*pMax.x + 1][pMax.y*10 + 5]);
        }else {
            printw(" ");
        }
    }

    attroff(COLOR_PAIR(1));
}

void delU(position p1, position p2, int x, int type) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    getBG(ch);
    x--;
    p1.x --;
    p1.y --;
    p2.x --;
    p2.y --;
    position pMax, pMin;

    //if type 1 = UX
    if(type == 1) {
        if(p1.y > p2.y) {
            pMax = p1;
            pMin = p2;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 2, pMin.y*10 + 2 + 5 + 2); 
        if(pMin.y*10 + 2 + 5 + 2 <= 43) {
            printw("%c", ch[4*pMin.x + 2][pMin.y*10 + 2 + 5]);
        }else {
            printw(" ");
        }

        delIX(pMin.y*10 + 2 + 5 + 3, x*10 + 2 + 5, 4*pMin.x + 2 + 2);
        delIX(pMax.y*10 + 2 + 5 + 3, x*10 + 2 + 5, 4*pMax.x + 2 + 2);
        delIY(pMin.x*4 + 2 + 3, pMax.x*4 + 2 + 1, x*10 + 2 + 5);

        move(4*pMax.x + 2 + 2, pMax.y*10 + 2 + 5 + 2); 
        if(pMax.y*10 + 2 + 5 + 2 <= 43) {
            printw("%c", ch[4*pMax.x + 2][pMax.y*10 + 2 + 5]);
        }else {
            printw(" ");
        }

    }else if (type == 2){
        if(p1.x > p2.x) {
            pMax = p1;
            pMin = p2;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 1, pMin.y*10 + 2 + 5);
        if(pMin.y*10 + 2 + 5 <= 43) {
            printw("%c", ch[4*pMin.x + 1][pMin.y*10 + 5]);
        }else {
            printw(" ");
        }

        delIY(4*pMin.x + 2, x*4 + 2 + 3, pMin.y*10 + 2 + 5);
        delIY(4*pMax.x + 2, x*4 + 2 + 3, pMax.y*10 + 2 + 5);
        int min, max;
        if(pMin.y > pMax.y) {
            min = pMax.y;
            max = pMin.y;
        }else {
            min = pMin.y;
            max = pMax.y;
        }
        delIX(min*10 + 2 + 6, max*10 + 2 + 4, x*4 + 2 + 3);

        move(4*pMax.x + 2 + 1, pMax.y*10 + 2 + 5);
        if(pMax.y*10 + 2 + 5 <= 43) {
            printw("%c", ch[4*pMax.x + 1][pMax.y*10 + 5]);
        }else {
            printw (" ");
        }
    }

    attroff(COLOR_PAIR(1));
}

void delZ(position p1, position p2, int x, int type) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    getBG(ch);
    x--;
    p1.x --;
    p1.y --;
    p2.x --;
    p2.y --;

    position pMin, pMax;

    //if type 1 ZX
    if(type == 1) {

        if(p1.y > p2.y) {
            pMin = p2;
            pMax = p1;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 2, pMin.y*10 + 2 + 5 + 2); 
        if(pMin.y*10 + 2 + 5 + 2 <= 43) {
            printw("%c", ch[4*pMin.x + 2][pMin.y*10 + 2 + 5]);
        }else {
            printw(" ");
        }

        delIX(pMin.y*10 + 2 + 5 + 3, x*10 + 2 + 5, 4*pMin.x + 2 + 2);
        delIY(4*pMin.x + 2 + 2, 4*pMax.x + 2 + 2, x*10 + 2 + 5);
        delIX(x*10 + 2 + 5, pMax.y*10 + 2 + 5 - 3, 4*pMax.x + 2 + 2);

        move(4*pMax.x + 2 + 2, pMax.y*10 + 2 + 5 - 2); 
        if(pMax.y*10 + 2 + 5 - 2 <= 43) {
            printw("%c", ch[4*pMax.x + 2][pMax.y*10 + 5 - 2]);
        }else {
            printw(" ");
        }
    }else if(type == 2) {
        if(p1.x > p2.x) {
            pMin = p2;
            pMax = p1;
        }else {
            pMax = p2;
            pMin = p1;
        }

        move(4*pMin.x + 2 + 3, pMin.y*10 + 2 + 5);
        if(pMin.y*10 + 2 + 5 <= 43) {
            printw("%c", ch[4*pMin.x + 3][pMin.y*10 + 5]);
        }else {
            printw(" ");
        }

        delIY(4*pMin.x + 2 + 4, 4*x + 2 + 2, pMin.y*10 + 2 + 5);
        delIY(4*pMax.x + 2, 4*x + 2 + 2, pMax.y*10 + 2 + 5);
        delIX(pMin.y*10 + 2 + 5, pMax.y*10 + 2 + 5, 4*x + 2 + 2);

        move(4*pMax.x + 2 + 1, pMax.y*10 + 2 + 5);
        if(pMax.y*10 + 2 + 5 <= 43){
            printw("ch", ch[4*pMax.x + 1][pMax.y*10 + 5]);
        }else {
            printw(" ");
        }
    }

    attroff(COLOR_PAIR(1));
}

void delL(position p1, position p2, int type) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    position pMax, pMin;
    if(p1.y > p2.y) {
        pMax = p1;
        pMin = p2;
    }else {
        pMax = p2;
        pMin = p1;
    }

    //if right
    if(type == 1) {

        position temp;
        temp.x = pMin.x;
        temp.y = pMax.y;

        delI(pMin, temp);
        delI(temp, pMax);
        attron(COLOR_PAIR(1));
        move(4*(temp.x - 1) + 2 + 2, (temp.y - 1)*10 + 2 + 5);
        if((temp.y - 1)*10 + 2 + 5 <= 43) {
            printw("%c", ch[4*(temp.x - 1) + 2][(temp.y - 1)*10 + 5]);
        } else {
            printw(" ");

        }
        move(4*(temp.x - 1) + 2 + 3,(temp.y - 1)*10 + 2 + 5);
        if((temp.y - 1)*10 + 2 + 5 <= 43) {
            printw("%c", ch[4*(temp.x - 1) + 3][(temp.y - 1)*10 + 5]);
        }else {
            printw(" ");
        }
        attroff(COLOR_PAIR(1));

    }else {
        position temp;
        temp.x = pMax.x;
        temp.y = pMin.y;

        delI(temp, pMin);
        delI(temp, pMax);

        attron(COLOR_PAIR(1));
        move(4*(temp.x - 1) + 2 + 2, (temp.y - 1)*10 + 2 + 5 + 1);
        if((temp.y - 1)*10 + 5 + 1 <= 43) {
            printw("%c", ch[4*(temp.x - 1) + 2][(temp.y - 1)*10 + 5 + 1]);
        } else {
            printw(" ");
        }
        move(4*(temp.x - 1) + 2 + 1, (temp.y - 1)*10 + 2 + 5);
        if((temp.y - 1)*10 + 2 + 5 <= 43) {
            printw("%c", ch[4*(temp.x - 1)+ 1][(temp.y - 1)*10 + 5]);            
        }else {
            printw(" ");
        }

        attroff(COLOR_PAIR(1));
    }

    attroff(COLOR_PAIR(1));
}
#include"struct.h"

char myBox[5][12] = {
            {" --------- "},
            {"|         |"},
            {"|         |"},
            {"|         |"},
            {" --------- "}
};
//mode 0 selected
//mode 1 match
//mode 2 unmatch
void Box1::drawBox(int mode) {

    if(!isValid) {
        return;
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    init_pair(4, COLOR_BLACK, COLOR_RED);
    attron(COLOR_PAIR(1));

    int x = i;
    int y = j;

    for (int k = 0; k < 5; k++) {
        move(4*x + k + 2, y*10 + 2);
        printw(myBox[k]);
    }

    attroff(COLOR_PAIR(1));

    if(isSelected) {
        if(mode == 1) {
            attron(COLOR_PAIR(3));
            for (int k = 0; k < 3; k++) {
                move(4*x + k + 2 + 1, y*10 + 2 + 1);
                printw("         ");
            }

            move(4*x + 2 + 2, y*10 + 2 + 5);
            printw("%c", c);

            attroff(COLOR_PAIR(3));
        }else if(mode == 2) {
            attron(COLOR_PAIR(4));
            for (int k = 0; k < 3; k++) {
                move(4*x + k + 2 + 1, y*10 + 2 + 1);
                printw("         ");
            }

            move(4*x + 2 + 2, y*10 + 2 + 5);
            printw("%c", c);

            attroff(COLOR_PAIR(4));
        }else {
            attron(COLOR_PAIR(2));
            for (int k = 0; k < 3; k++) {
                move(4*x + k + 2 + 1, y*10 + 2 + 1);
                printw("         ");
            }

            move(4*x + 2 + 2, y*10 + 2 + 5);
            printw("%c", c);

            attroff(COLOR_PAIR(2));
        }

        
    }else {
        attron(COLOR_PAIR(1));
        move(4*x + 2 + 2, y*10 + 2 + 5);
        printw("%c", c);
        attroff(COLOR_PAIR(1));
    }

}


void Box1::deleteBox() {
    int x = i, y = j;

    for (int k = 0; k < 5; k++) {
        move(4*x + k + 2, y*10 + 2);
        printw("           ");
    }

    
}

void Box2::drawBox() {

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(1));

    int x = i;
    int y = j;

    for (int k = 0; k < 5; k++) {
        move(4*x + k + 2, y*10 + 2);
        printw(myBox[k]);
    }

    attroff(COLOR_PAIR(1));

    if(isSelected) {
        attron(COLOR_PAIR(2));
        for (int k = 0; k < 3; k++) {
            move(4*x + k + 2 + 1, y*10 + 2 + 1);
            printw("         ");
        }

        move(4*x + 2 + 2, y*10 + 2 + 5);
        printw("%c", c);

        attroff(COLOR_PAIR(2));
    }else {
        attron(COLOR_PAIR(1));
        move(4*x + 2 + 2, y*10 + 2 + 5);
        printw("%c", c);
        attroff(COLOR_PAIR(1));
    }
}

void Box2::deleteBox() {
    int x = j, y = i;

    for (int k = 0; k < 5; k++) {
        move(4*x + k + 2, y*10 + 2);
        printw("           ");
    }
}

//done
#include"struct.h"

char box[5][12] = {
            {" --------- "},
            {"|         |"},
            {"|         |"},
            {"|         |"},
            {" --------- "}
};

void Box1::drawBox() {
    if(!isValid) {
        return;
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(1));

    int x = i + 1;
    int y = j + 1;

    for (int k = 0; k < 5; k++) {
        move(y * 4 + k, 10 * x - 5);
        printw(box[k]);
    }

    attroff(COLOR_PAIR(1));

    if(isSelected) {
        attron(COLOR_PAIR(2));
        for (int k = 0; k < 3; k++) {
            move(y * 4 + k + 1, 10 * x - 5 + 1);
            printw("         ");
        }

        move(j * 4 + 2, 10 * i - 5 + 5);
        printw(&c);

        attroff(COLOR_PAIR(2));
    }else {
        attron(COLOR_PAIR(1));
        move(y * 4 + 2, 10 * x - 5 + 5);
        printw(&c);
        attroff(COLOR_PAIR(1));
    }
}

void Box1::deleteBox() {
    int x = j + 1, y = i + 1;

    for (int k = 0; k < 5; k++) {
        move(y * 4 + k, 10 * x - 5);
        printw("           ");
    }
}

void Box2::drawBox() {

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(1));

    int x = i + 1;
    int y = j + 1;

    for (int k = 0; k < 5; k++) {
        move(y * 4 + k, 10 * x - 5);
        printw(box[k]);
    }

    attroff(COLOR_PAIR(1));

    if(isSelected) {
        attron(COLOR_PAIR(2));
        for (int k = 0; k < 3; k++) {
            move(y * 4 + k + 1, 10 * x - 5 + 1);
            printw("         ");
        }

        move(j * 4 + 2, 10 * i - 5 + 5);
        printw(&c);

        attroff(COLOR_PAIR(2));
    }else {
        attron(COLOR_PAIR(1));
        move(y * 4 + 2, 10 * x - 5 + 5);
        printw(&c);
        attroff(COLOR_PAIR(1));
    }
}

void Box2::deleteBox() {
    int x = j + 1, y = i + 1;

    for (int k = 0; k < 5; k++) {
        move(y * 4 + k, 10 * x - 5);
        printw("           ");
    }
}

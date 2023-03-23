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

    int x = i + 1;
    int y = j + 1;

    for (int k = 0; k < 5; k++) {
        move(j * 4 + k, 10 * i - 5);
        printw(box[k]);
    }
}
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
#include <ncurses.h>

int main() {
    // Initialize curses
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    // Clear the screen
    clear();

    // Define symbols for "YOU LOSE"
    char symbols[] = {'@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '~', '/', '|', '\\'};

    // Print "YOU LOSE" in symbols
    int y = 10;
    int x = 20;
    char message[] = "YOU LOSE";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 17; k++) {
                mvaddch(y, x, symbols[k]);
                napms(50);
            }
            x += 3;
            y += 1;
        }
    }

    // Clean up curses
    getch();
    nocbreak();
    endwin();
    return 0;
}
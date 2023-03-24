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
    char box[5][12] = {
            {" --------- "},
            {"|         |"},
            {"|         |"},
            {"|         |"},
            {" --------- "}
    };

    printw(box[2]);

    // Clean up curses
    getch();
    nocbreak();
    endwin();
    return 0;
}
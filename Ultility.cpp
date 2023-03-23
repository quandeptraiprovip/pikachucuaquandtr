#include<iostream>
#include<ncurses.h>
#include<fstream>
#include<string>
#include"struct.h"
using namespace std;

int mainMenu() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    clear();

    

    int choice[4] = { 0,0,0,0 }, temp, key, curChoice = 0;
    while(1) {


        start_color(); // enable color output
        init_pair(1, COLOR_BLACK, COLOR_WHITE);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        mvprintw(0, 6, " ______    __   __  ___      ___       ______  __    __   __    __");
        mvprintw(1, 6, "|   _  \\  |  | |  |/  /     /   \\     /      ||  |  |  | |  |  |  |");
        mvprintw(2, 6, "|  |_)  | |  | |  '  /     /  ^  \\   |  ,----'|  |__|  | |  |  |  |");
        mvprintw(3, 6, "|   ___/  |  | |    <     /  /_\\  \\  |  |     |   __   | |  |  |  |");
        mvprintw(4, 6, "|  |      |  | |  .  \\   /  _____  \\ |  `----.|  |  |  | |  `--'  |");
        mvprintw(5, 6, "| _|      |__| |__|\\__\\ /__/     \\__\\ \\______||__|  |__|  \\______/");


        attroff(COLOR_PAIR(2));

        choice[curChoice] = 1;

        if(choice[0]) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 3; i++) {
                mvprintw(8 + i, COLS/2 - 8, "             ");
            }

            mvprintw(9, COLS/2 - 8 + 4, "NORMAL");
            attroff(COLOR_PAIR(1));
        }else {
            mvprintw(9, COLS/2 - 8 + 4, "NORMAL");
        }

        if(choice[1]) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 3; i++) {
                mvprintw(11 + i, COLS/2 - 8, "             ");
            }

            mvprintw(12, COLS/2 - 8 + 2, "DIFFICULT");
            attroff(COLOR_PAIR(1));
        }else {
            mvprintw(12, COLS/2 - 8 + 2, "DIFFICULT");
        }

        if(choice[2]) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 3; i++) {
                mvprintw(14 + i, COLS/2 - 8, "             ");
            }

            mvprintw(15, COLS/2 - 8 + 1, "LEADERBOARD");
            attroff(COLOR_PAIR(1));
        }else {
            mvprintw(15, COLS/2 - 8 + 1, "LEADERBOARD");
        }

        if(choice[3]) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 3; i++) {
                mvprintw(17 + i, COLS/2 - 8, "             ");
            }

            mvprintw(18, COLS/2 - 8 + 5, "EXIT");
            attroff(COLOR_PAIR(1));
        }else {
            mvprintw(18, COLS/2 - 8 + 5, "EXIT");
        }

        key = getch();

        if(key == '\n') {
            clear();
            return curChoice;
        }

        switch(key) {
            case KEY_UP:
                choice[curChoice] = 0;
                if(curChoice > 0) {
                    curChoice --;
                }else {
                    curChoice = 3;
                }
                break;
            case KEY_DOWN:
                choice[curChoice] = 0;
                if(curChoice < 3) {
                    curChoice ++;
                }else {
                    curChoice = 0;
                }
                break;
            default:
                break;
        }

        clear();
    }
    


    refresh();



    // Wait for user input
    getch();

    // Clean up
    endwin();
}

void readLeaderBoard() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    clear();

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    mvprintw(3, COLS/2 - 8, "LEADERBOARD");

    mvprintw(5, 5, "NAME");
    mvprintw(5, COLS - 20, "POINTS");

    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    move(6, 5);
    for(int i = 5; i < COLS - 20 + 6; i ++) {
        printw("=");
    }

    attroff(COLOR_PAIR(2));

    ifstream f("leaderboard.dat", ios::binary);
    f.seekg(0, ios::end);
    int num = f.tellg() / 34; // file size / struct size
    f.seekg(0, ios::beg);

    player *players = new player[num];

    for(int i = 0; i < num; i ++) {
        f.read(players[i].name, 30);
        f.read((char*)&players[i].point, 4);
        string str = to_string(players[i].point);
        mvprintw(7 + i, 5, players[i].name);
        mvprintw(7 + i, COLS - 20 + 6, str.c_str());
    }

    delete[] players;
    f.close();

    getch();
    clear();

    refresh();



    // Wait for user input
    getch();

    // Clean up
    endwin();
}

void writeLeaderBoard(player p) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    clear();

    ifstream fin("leaderboard.dat", ios::binary);

    player *list = new player[10];
    fin.seekg(0, ios::end);
    int numberOfPlayers = fin.tellg() / 34; // file size / struct size
    fin.seekg(0, ios::beg);

    for(int i = 0; i < numberOfPlayers; i ++) {
        fin.read(list[i].name, 30);
        fin.read((char*)&list[i].point, 4);
        string str = to_string(list[i].point);
    }

    int index = numberOfPlayers - 1;
    for(index; index >= 0; index --) {
        if(p.point <= list[index].point) {
            break;
        }
    }

    if(numberOfPlayers < 10) {
        for(int i = numberOfPlayers; i > index + 1; i--) {
            list[i] = list[i - 1];
        }
        list[index + 1] = p;
    }else {
        if(index != numberOfPlayers - 1) {
            for(int i = numberOfPlayers - 1; i > index + 1; i--) {
                list[i] = list[i - 1];
            }
            list[index + 1] = p;
        }
    }

    fin.close();

    ofstream fout("leaderboard.dat", ios::binary | ios::trunc);

    for(int i = 0; i < numberOfPlayers; i ++) {
        fout.write(list[i].name, 30);
        fout.write((char*)&list[i].point, 4);
    }

    fout.close();

    delete[] list;



    getch();
    clear();

    refresh();



    // Wait for user input
    getch();

    // Clean up
    endwin();
}

void getPlayerInfo(player& p) {
    move(LINES/2 + 4, COLS/2 - 9);
    printw("Enter your name:");
    cin.getline(p.name, 30);
    p.life = 3;
    p.point = 0;
}

void displayStatus(bool win) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    clear();
    bool win = false;
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    if (win) {
        mvprintw(7, 17, "Y   Y");
        mvprintw(8, 17, " Y Y ");
        mvprintw(9, 17, "  Y  ");
        mvprintw(10, 17, "  Y  ");
        mvprintw(11, 17, "  Y  ");

        // Print "O"
        mvprintw(7, 23, "OOOOO");
        mvprintw(8, 23, "O   O");
        mvprintw(9, 23, "O   O");
        mvprintw(10, 23, "O   O");
        mvprintw(11, 23, "OOOOO");

        // Print "U"
        mvprintw(7, 29, "U   U");
        mvprintw(8, 29, "U   U");
        mvprintw(9, 29, "U   U");
        mvprintw(10, 29, "U   U");
        mvprintw(11, 29, "UUUUU");

        // Print "W"
        mvprintw(7, 37, "W   W");
        mvprintw(8, 37, "W   W");
        mvprintw(9, 37, "W W W");
        mvprintw(10, 37, "WW WW");
        mvprintw(11, 37, "W   W");

        // Print "O"
        mvprintw(7, 43, "OOOOO");
        mvprintw(8, 43, "O   O");
        mvprintw(9, 43, "O   O");
        mvprintw(10, 43, "O   O");
        mvprintw(11, 43, "OOOOO");

        // Print "N"
        mvprintw(7, 49, "N   N");
        mvprintw(8, 49, "NN  N");
        mvprintw(9, 49, "N N N");
        mvprintw(10, 49, "N  NN");
        mvprintw(11, 49, "N   N");
    }else {
        mvprintw(7, 17, "Y   Y");
        mvprintw(8, 17, " Y Y ");
        mvprintw(9, 17, "  Y  ");
        mvprintw(10, 17, "  Y  ");
        mvprintw(11, 17, "  Y  ");

        // Print "O"
        mvprintw(7, 23, "OOOOO");
        mvprintw(8, 23, "O   O");
        mvprintw(9, 23, "O   O");
        mvprintw(10, 23, "O   O");
        mvprintw(11, 23, "OOOOO");

        // Print "U"
        mvprintw(7, 29, "U   U");
        mvprintw(8, 29, "U   U");
        mvprintw(9, 29, "U   U");
        mvprintw(10, 29, "U   U");
        mvprintw(11, 29, "UUUUU");

        mvprintw(7, 37, "L    ");
        mvprintw(8, 37, "L    ");
        mvprintw(9, 37, "L    ");
        mvprintw(10, 37, "L    ");
        mvprintw(11, 37, "LLLLL");

        // Print "O"
        mvprintw(7, 43, "OOOOO");
        mvprintw(8, 43, "O   O");
        mvprintw(9, 43, "O   O");
        mvprintw(10, 43, "O   O");
        mvprintw(11, 43, "OOOOO");

        // Print "N"
        mvprintw(7, 49, "SSSSS");
        mvprintw(8, 49, "S    ");
        mvprintw(9, 49, "SSSSS");
        mvprintw(10, 49, "    S");
        mvprintw(11, 49, "SSSSS");

        // Print "N"
        mvprintw(7, 55, "EEEEE");
        mvprintw(8, 55, "E    ");
        mvprintw(9, 55, "EEEEE");
        mvprintw(10, 55, "E    ");
        mvprintw(11, 55, "EEEEE");
    }

    attroff(COLOR_PAIR(1));

    getch();
    clear();

    refresh();



    // Wait for user input
    getch();

    // Clean up
    endwin();
}

void getBackground(char bg[][41]) {
    ifstream fin("pika.txt");
    if (fin) {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                bg[i][j] = fin.get();
            }
            fin.ignore();
        }
        fin.close();
    }
    else {
        memset(bg, ' ', sizeof(bg));
    }
}

//void displayBG
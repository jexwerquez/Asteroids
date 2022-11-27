#include "base.h"
#include "game.h"

int main (int argc, char* argv[]) {
    initscr();
    curs_set(0);
    noecho();
    start_color();
    clear();
    init_pair(5, COLOR_WHITE, COLOR_WHITE) ; // bord
    init_pair(4, COLOR_WHITE, 0);  // text, shot
    init_pair(2, COLOR_BLUE, 0);  // meteor 1
    init_pair(3, COLOR_RED, 0);  // spaceship
    init_pair(1, COLOR_CYAN, 0);  // meteor 2
    wattrset(stdscr, COLOR_PAIR(4));
    refresh();
    Settings settings;
    string filename;
    if (argc < 2)
        filename = "settings";
    else
        filename = argv[1];
    settings.parser(settings, filename);
    Field field(settings.height, settings.width);
    Start start(field, filename, settings);
    start.processing(field);
    curs_set(1);
    nocbreak();
    endwin();
    return 0;
}

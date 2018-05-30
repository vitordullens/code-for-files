#include <curses.h>

int main(){
    initscr();
//  cbreak(); to disable buffering and get one char at a time
    noecho();
    keypad(stdscr, TRUE);




    endwin();
    return 0;
}
// TODO: sound fx
// TODO: hardness will be continously
// TODO: pressing to down arrow button will increase speed
// TODO: add instruction option to startmenu
// TODO: prepare instruction screen
// TODO: credits screen
// TODO: define macro for "[X]","   ","oOo",

#include "../include/GLOBALS.h"

int main(){

     WINDOW* win = initscr();

     keypad(stdscr, TRUE);    // activates arrow key input
     nodelay(win, TRUE);      // no need to wait return char to accept an input
     srand (time(NULL));      // initialize random seed

     start_menu(win);
     game_loop(win);

	endwin();	//close the curses pane
     return 0;
}

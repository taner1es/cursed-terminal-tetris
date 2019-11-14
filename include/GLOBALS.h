#include <unistd.h>      /* sleep            */
#include <stdlib.h>      /* srand, rand      */
#include <time.h>        /* time             */
#include <ncurses.h>     /* drawing, input   */
#include "Tetromine.h"

#define COLUMNS 10
#define ROWS 30
#define INITIAL_SPEED 10
#define SCORE_ADDITION 10

// GLOBAL VARIABLES
// ----------------
extern bool playground[ROWS][COLUMNS];
extern bool buffer_pane[8][8];
extern bool run;
extern bool can_act;
extern bool idle;
extern bool is_game_over;
extern bool shapes[32][4];

extern int speed;
extern int timer;
extern int act_counter;
extern double score;

extern Tetromine* curtet; //current tetromine
extern Tetromine* buftet; //buffered tetromine
// ----------------

// GLOBAL FUNCTIONS
// ----------------
// User Input
extern void input(WINDOW* _win);
// User Actions
extern void left();
extern void right();
extern void rotate();
extern void drop();
extern void increase_speed(int& speed);
// Game Actions/Controllers
extern void game_loop(WINDOW*& _win);
extern bool down();
extern void stack();
extern void draw_tetro(const bool& set);
extern void remove_lines_if_any_filled();
extern void draw_playground(int remove_fx_line_number = -1);
extern void reset_playground();
// Menu Actions
extern void start_menu(WINDOW*& _win);
extern void pause_menu(WINDOW*& _win);
extern void highscore_menu(WINDOW*& _win);
extern void credits(WINDOW*& _win);
extern void game_over(WINDOW*& _win);
// ----------------

#include "../include/GLOBALS.h"

// Define global variables those declared in "GLOBALS.h"

bool playground[ROWS][COLUMNS];
bool buffer_pane[8][8];
bool run = false;
bool can_act;
bool idle;
bool is_game_over = false;
int speed = INITIAL_SPEED;
int timer = 0;
int act_counter;
double score = 0;
bool shapes[32][4] =
{
     {0, 0, 1, 0}, //shape 'I', 0-3
     {0, 0, 1, 0},
     {0, 0, 1, 0},
     {0, 0, 1, 0}
     ,
     {0, 1, 0, 0}, //shape 'L', 4-7
     {0, 1, 0, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}
     ,
     {0, 0, 0, 0}, //shape 'box', 12-15
     {0, 1, 1, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}
     ,
     {0, 0, 1, 0}, //shape 'reverse L', 16-19
     {0, 0, 1, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}
     ,
     {0, 0, 0, 0}, //shape 'T', 20-23
     {1, 1, 1, 0},
     {0, 1, 0, 0},
     {0, 0, 0, 0}
     ,
     {0, 0, 0, 0}, //shape 'Z', 24-27
     {1, 1, 0, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}
     ,
     {0, 0, 0, 0}, //shape 'S', 28-31
     {0, 1, 1, 0},
     {1, 1, 0, 0},
     {0, 0, 0, 0}
};

Tetromine* curtet = nullptr; //current tetromine
Tetromine* buftet = nullptr; //buffered tetromine

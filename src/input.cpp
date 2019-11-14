#include "../include/GLOBALS.h"

void input(WINDOW* _win){
     if(act_counter >= 3) can_act = false;

     int in = getch();
     //Key Handling : PAUSE MENU
     if(in == (int)'p' || in == (int)'P'){
          pause_menu(_win);
     }
     //ACTION RESTRICTION
     else if(!can_act){
          down();
          act_counter = 0;
          can_act = true;
     }
     //Key Handling : DROP EVENT
     else if((in == (int)'x' || in == (int)'X') && can_act && idle){
          drop();
          act_counter = 0;
          can_act = true;
     }
     //Key Handling : ROTATE EVENT
     else if((in == (int)'z' || in == (int)'Z') && can_act && idle){
          idle = false;
          rotate();
          act_counter++;
     }
     //Key Handling : LEFT EVENT
     else if(in == KEY_LEFT && can_act && idle){
          idle = false;
          left();
          act_counter++;
     }
     //Key Handling : RIGHT EVENT
     else if(in == KEY_RIGHT && can_act && idle){
          idle = false;
          right();
          act_counter++;
     }
     //NO KEY PRESSED EVENT
     else if(idle){
          down();
          act_counter = 0;
          can_act = true;
     }
}

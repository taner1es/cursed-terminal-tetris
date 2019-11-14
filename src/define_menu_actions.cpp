#include "../include/GLOBALS.h"

void start_menu(WINDOW*& _win){
     int selection = 0;
     int selection_input;

     nodelay(_win, FALSE);

     clear();
     refresh();

     while(true){

          //menu dra_wing
          printw(  "[X][X][X][X][X][X][X][X][X]");
          printw("\n[X]                     [X]");
          printw("\n[X]      -TETRIS-       [X]");
          printw("\n[X]                     [X]");

          if(selection == 0)
               printw("\n[X]  -->START           [X]");
          else
               printw("\n[X]  START              [X]");

          printw("\n[X]                     [X]");

          if(selection == 1)
               printw("\n[X]  -->HIGHSCORES      [X]");
          else
               printw("\n[X]  HIGHSCORES         [X]");

          printw("\n[X]                     [X]");

          if(selection == 2)
               printw("\n[X]  -->CREDITS         [X]");
          else
               printw("\n[X]  CREDITS            [X]");

          printw("\n[X]                     [X]");

          if(selection == 3)
               printw("\n[X]  -->EXIT            [X]");
          else
               printw("\n[X]  EXIT               [X]");

          printw("\n[X]                     [X]");


          printw("\n[X][X][X][X][X][X][X][X][X]");


          //menu selection
          selection_input = wgetch(_win);
          if(selection_input == KEY_UP) selection--;
          else if(selection_input == KEY_DOWN) selection++;
          else if(selection_input == KEY_RIGHT){

               switch (selection){
                    case 0: //START
                         if(curtet != nullptr) {
                              delete curtet;
                              curtet = new Tetromine();
                         }


                         reset_playground();
                         timer = 0;
                         run = true;
                         is_game_over = false;
                         nodelay(_win, TRUE);
                    break;

                    case 1: //HIGHSCORES
                         highscore_menu(_win);
                         run = false;
                    break;

                    case 2: //CREDITS
                         run = false;
                    break;

                    case 3: //EXIT
                         clear();
                         printw("\nClosed now, no problem, you are already fun.");
                         refresh();

                         nodelay(_win, FALSE);
                         getch();

                         run = false;
                    break;

                    default:
                         printw("\nAn error caused to close the tetris, this is not good.");
                         run = false;
                    break;
               }

               return;
          };

          if(selection < 0 ) selection = 3;
          else if(selection > 3) selection = 0;

          refresh();
          clear();
     }
}

void pause_menu(WINDOW*& _win){

     //pause game (resume, restart, quit)

     int selection = 0;
     int selection_input;

     nodelay(_win, FALSE);
     while(true){

          printw(  "[X][X][X][X][X][X][X][X][X]");
          printw("\n[X]                     [X]");
          printw("\n[X]      -PAUSED-       [X]");
          printw("\n[X]                     [X]");

          if(selection == 0)
          printw("\n[X]  -->RESUME          [X]");
          else
          printw("\n[X]  RESUME             [X]");

          printw("\n[X]                     [X]");

          if(selection == 1)
          printw("\n[X]  -->RESTART         [X]");
          else
          printw("\n[X]  RESTART            [X]");

          printw("\n[X]                     [X]");

          if(selection == 2)
          printw("\n[X]  -->BACK            [X]");
          else
          printw("\n[X]  BACK               [X]");

          printw("\n[X]                     [X]");

          printw("\n[X][X][X][X][X][X][X][X][X]");


          //input
          selection_input = wgetch(_win);
          if(selection_input == KEY_UP) selection--;
          else if(selection_input == KEY_DOWN) selection++;
          else if(selection_input == KEY_RIGHT){

               switch (selection){
                    case 0: //RESUME
                         nodelay(_win, TRUE);
                         return;
                    break;

                    case 1: //RESTART
                         delete curtet;
                         curtet = new Tetromine();
                         reset_playground();
                         nodelay(_win, TRUE);
                         score = 0;
                         return;
                    break;

                    case 2: //BACK
                         start_menu(_win);
                    break;

                    default:
                         return;
                    break;

               }

               return;
          }

          if(selection < 0 ) selection = 2;
          else if(selection > 2) selection = 0;

          clear();
          refresh();
     }
}

void highscore_menu(WINDOW*& _win){

     int selection_input;
     nodelay(_win, FALSE);

     while(true){
          clear();
          refresh();
          printw(  "[X][X][X][X][X][X][X][X][X]");
          printw("\n[X]                     [X]");
          printw("\n[X]    -HIGHSCORES-     [X]");
          printw("\n[X]   (Coming soon)     [X]");
          printw("\n[X]                     [X]");
          printw("\n[X]  BEST 10            [X]");
          printw("\n[X]  -------            [X]");
          printw("\n[X]   1)..              [X]");
          printw("\n[X]   2)..              [X]");
          printw("\n[X]   3)..              [X]");
          printw("\n[X]   4)..              [X]");
          printw("\n[X]   5)..              [X]");
          printw("\n[X]   6)..              [X]");
          printw("\n[X]   7)..              [X]");
          printw("\n[X]   8)..              [X]");
          printw("\n[X]   9)..              [X]");
          printw("\n[X]  10)..              [X]");
          printw("\n[X]                     [X]");
          printw("\n[X]  -->BACK            [X]");
          printw("\n[X]                     [X]");
          printw("\n[X][X][X][X][X][X][X][X][X]");


          //input
          selection_input = wgetch(_win);
          if(selection_input == KEY_RIGHT) break;
     }
     start_menu(_win);
}

void game_over(WINDOW*& _win){
     clear();
     nodelay(_win, FALSE);

     printw(  "[X][X][X][X][X][X][X][X][X]");
     printw("\n[X]                     [X]");
     printw("\n[X]     -GAME OVER-     [X]");
     printw("\n[X]                     [X]");
     printw("\n[X]  -->Take a Menu     [X]");
     printw("\n[X]                     [X]");
     printw("\n[X][X][X][X][X][X][X][X][X]");

     refresh();
     wgetch(_win);
     start_menu(_win);
}

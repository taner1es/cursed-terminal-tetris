#include "../include/GLOBALS.h"

void game_loop(WINDOW*& _win){

     if(curtet != nullptr) delete curtet;
     if(buftet != nullptr) delete buftet;

     curtet = new Tetromine();
     buftet = new Tetromine();

     while(run){

          if(is_game_over){
               game_over(_win);
          }else{
               //if there is no active tetromine
               if(curtet == nullptr){
                    curtet = buftet;
                    buftet = new Tetromine();
               }else{

                    input(_win);

                    if(!run) break;

                    draw_playground(-1); //-1 is the default value, hardcoded to avoid of function overload

                    flushinp();
                    refresh();
                    clear();

                    usleep(1000 * (1000 * 1/speed));
               }
          }
     }
}

bool down(){
     // check for next line is available for each block
     for(int i = 0 ; i < 4; i++){
          for(int j = 0; j < 4; j++){
               //is there any block exists and it is not part of itself
               if(curtet->tetro[i][j]){

                    //detect collision to playground bottom line
                    if(i+curtet->offset_up+1 >= ROWS-1){
                         can_act = false;
                         stack();
                         return false;
                    }

                    //detect collision to other tetromines
                    if(playground[i+curtet->offset_up+1][j+curtet->offset_left]){
                         //detect itself or not
                         if(!curtet->tetro[i+1][j]){ can_act = false;
                         stack();
                         return false;
                         }
                    }
               }
          }
     }

     draw_tetro(false);
     curtet->offset_up++;
     draw_tetro(true);

     return true;
}

void stack(){
     // embed tetromine to playground
     for(int i = 0; i < 4; i++){
          for(int j = 0; j < 4; j++){
               if(curtet->tetro[i][j]){
                    playground[i+curtet->offset_up][j+curtet->offset_left] = true;
               }
          }
     }

     // looking for game over
     for(int i= 0; i < COLUMNS ;i++ ){
          if(playground[0][i]){
               is_game_over = true;
               delete curtet;
               curtet = nullptr;
          }
     }


     remove_lines_if_any_filled();
     delete curtet;
     curtet = buftet;
     buftet = new Tetromine();
}

void draw_tetro(const bool& set){
     for(int i = 0; i < 4; i++){
          for(int j = 0; j < 4; j++){
               if(curtet->tetro[i][j]) playground[i+curtet->offset_up][j+curtet->offset_left] = set;
          }
     }
     if(set) idle = true;
}

void remove_lines_if_any_filled(){
     int count_filled;
     int score_multiplier = 0;
     for(int i = 0; i < ROWS-1; i++){
          count_filled = 0;
          //check line has filled enough
          for(int j = 1; j < COLUMNS-1; j++)
               if(playground[i][j]) count_filled++;

          //remove line if filled enough
          if(count_filled >=  COLUMNS-2){
               score_multiplier++;
               //remove line and present some vfx
               for(int j = 1; j < COLUMNS-1; j++){
                     playground[i][j] = false;
                     draw_playground(i); //drawing externally for removing line vfx

                     refresh();
                     usleep(1000 * (1000 * 1/speed/8));
               }


               //get aboved line to down
               for(int row = i-1; row >= 0; row--){
                    for(int j = 1; j < COLUMNS-1; j++){
                         if(playground[row][j]){
                              playground[row][j] = false;
                              playground[row+1][j] = true;
                         }
                    }
               }
          }
     }

     score += score_multiplier * speed * SCORE_ADDITION + (SCORE_ADDITION * score_multiplier);
}

void draw_playground(int remove_fx_line_number){
     clear();

     for(int i = 0; i < ROWS; i++){
          if(i == ROWS-1) printw("[");
          for(int j = 0; j < COLUMNS; j++){
               if(i == ROWS-1){
                    if(j == COLUMNS-1)
                         printw("===]");
                    else
                         printw("===");
               }

               else if(j == 0 || j == COLUMNS-1){
                    printw("[||]");
                    if(j == COLUMNS -1){
                         // draw buffer pane
                         if(buftet != nullptr){
                              if(i >= 2 &&  i < 10){
                                   printw("   ");
                                   for(int b_j = 0; b_j < 8; b_j++){
                                        //draw bufferpane borders
                                        if(  i == 2 ||
                                             i == 9 ||
                                             b_j == 0 ||
                                             b_j == 7) printw("[O]");
                                        //draw buffered tetromine into bufferpane
                                        else if((i >= 4 && i < 8) && (b_j >= 2 && b_j < 6)){
                                             if(buftet->tetro[i-4][b_j-2])
                                                  printw("[X]");
                                             else
                                                  printw("   ");
                                        }else{
                                             printw("   ");
                                        }

                                   }
                              }
                         }

                         // draw score pane
                         if(i == ROWS -8 && j == COLUMNS-1)
                              printw("%18s","SCORE");
                         if(i >= ROWS-6 &&  i < ROWS){
                              printw("   ");
                              for(int b_j = 0; b_j < 8; b_j++){
                                   //draw scorepane borders
                                   if(  i == ROWS-6 ||
                                        i == ROWS-2 ||
                                        b_j == 0    ||
                                        b_j == 7    ) printw("[O]");
                                   //draw calculated score into scorepane
                                   else if(i == ROWS-4 && b_j == 1) printw("   %12.0f   ", score);
                                   else if(i == ROWS-4 && (b_j > 1 && b_j < 7))
                                        continue;
                                   else
                                        printw("   ");

                              }
                         }
                    }
               }
               else if(playground[i][j]){
                    if(remove_fx_line_number != -1 && i == remove_fx_line_number)
                    printw("oOo");
                    else
                    printw("[X]");
               }
               else
                    printw("   ");
          }
          printw("\n");
     }
}

void reset_playground(){
     for(int i = 0; i < ROWS; i++)
     for(int j = 0; j < COLUMNS; j++)
     playground[i][j]=false;
}

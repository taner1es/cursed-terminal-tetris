#include "../include/GLOBALS.h"

void left(){
     //check for next column is available for each block
     for(int i = 0 ; i < 4; i++){
          for(int j = 0; j < 4; j++){
               //is there any block exists and it is not part of itself
               if(curtet->tetro[i][j]){

                    //detect collision to playground left line
                    if(j+curtet->offset_left-1 <= 0){
                         can_act = false;
                         return;
                    }

                    //detect collision to other tetromines
                    if(playground[i+curtet->offset_up][j+curtet->offset_left-1]){
                         if(!curtet->tetro[i][j-1]){
                              can_act = false;
                              return;
                         }
                    }
               }
          }

     }

     draw_tetro(false);
     curtet->offset_left--;
     draw_tetro(true);
}

void right(){
     //check for next column is available for each block
     for(int i = 0 ; i < 4; i++){
          for(int j = 0; j < 4; j++){
               //is there any block exists and it is not part of itself
               if(curtet->tetro[i][j]){

                    //detect collision to playground right line
                    if(j+curtet->offset_left+2 >= COLUMNS){
                         can_act = false;
                         return;
                    }

                    //detect collision to other tetromines
                    if(playground[i+curtet->offset_up][j+curtet->offset_left+1]){
                         if(!curtet->tetro[i][j+1]){
                              can_act = false;
                              return;
                         }
                    }
               }
          }
     }
     draw_tetro(false);
     curtet->offset_left++;
     draw_tetro(true);
     return;
}

void rotate(){
     bool temp[4][4];    // (x,y) -> (x-3,y) to translate the matrices
     bool temp2[4][4];   // (x,y) -> (y,x) to swap the matrices

     bool collided = false;

     // (x,y) -> (x-3,y) to translate the matrices
     int k;
     for(int i = 0 ; i < 4; i++){
          k = i-3;
          for(int j = 0; j < 4; j++){
               if(k < 0) k *= (-1);
               temp[i][j] = curtet->tetro[k][j];
          }
     }

     // (x,y) -> (y,x) to swap the matrices
     for(int i = 0 ; i < 4; i++){
          for(int j = 0; j < 4; j++){
               temp2[i][j] = temp[j][i];
          }
     }

     //detect collision
     draw_tetro(false);

     int offset_left_orginal = curtet->offset_left;
     int offset_up_orginal = curtet->offset_up;

     bool test_up_done = false;              //if the tetromine stuck and it is not rotatable,
     bool test_down_done = false;            //so try to figure out to each side 1/-1 flexibility
     bool test_right_done = false;           //to give a last chance to player to rotate.
     bool test_left_done = false;            //if still it is not rotatable, so, don't rotate
     bool test_upleft_done = false;
     bool test_upright_done = false;
     bool test_downleft_done = false;
     bool test_downright_done = false;

     while(true){
          collided = false;
          for(int i = 0 ; i < 4; i++){
               if(collided) break;
               for(int j = 0; j < 4; j++){
                    if(temp2[i][j]){
                         //detect collision to right, left, bottom lines of playgrounds
                         if(  j+curtet->offset_left >= COLUMNS-1  ||
                              j+curtet->offset_left <= 0          ||
                              i+curtet->offset_up >= ROWS-1){

                              collided = true;
                              break;
                         }
                    }
                    ///detect collision to other tetromines
                    if(playground[i+curtet->offset_up][j+curtet->offset_left]){
                         if(temp2[i][j]){
                              collided = true;
                              break;
                         }
                    }
               }
          }

          if(!collided) break;
          else{
               if(!test_up_done){
                    curtet->offset_up = offset_up_orginal-1;
                    test_up_done = true;
               }
               else if(!test_down_done){
                    curtet->offset_up = offset_up_orginal+1;
                    test_down_done = true;
               }
               else if(!test_left_done){
                    curtet->offset_left = offset_left_orginal-1;
                    test_left_done = true;
               }
               else if(!test_right_done){
                    curtet->offset_left = offset_left_orginal+1;
                    test_right_done = true;
               }else if(!test_upleft_done){
                    curtet->offset_up = offset_up_orginal-1;
                    curtet->offset_left = offset_left_orginal-1;
                    test_upleft_done = true;
               }else if(!test_upright_done){
                    curtet->offset_up = offset_up_orginal-1;
                    curtet->offset_left = offset_left_orginal+1;
                    test_upright_done = true;
               }else if(!test_downleft_done){
                    curtet->offset_up = offset_up_orginal+1;
                    curtet->offset_left = offset_left_orginal-1;
                    test_downleft_done = true;
               }else if(!test_downright_done){
                    curtet->offset_up = offset_up_orginal+1;
                    curtet->offset_left = offset_left_orginal+1;
                    test_downright_done = true;
               }else{
                    curtet->offset_up = offset_up_orginal;
                    curtet->offset_left = offset_left_orginal;
                    can_act = false;
                    draw_tetro(true);
                    return;
               }
          }
     }


     //relocate
     draw_tetro(false);
     for(int i = 0 ; i < 4; i++){
          for(int j = 0; j < 4; j++){
               curtet->tetro[i][j] = temp2[i][j];
          }
     }
     draw_tetro(true);
}

void drop(){
     while(down()){}
}

void increase_speed(int& speed){
     int max_speed = speed *2;
     if(speed < max_speed)
          speed += 0.5;
}

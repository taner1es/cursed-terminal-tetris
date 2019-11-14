#include "../include/GLOBALS.h"

Tetromine::Tetromine(){
     can_act = true;
     idle = true;
     act_counter = 0;
     reset_offset();

     //randomize some type and init
     //...
     int random_index = (rand() % 7) * 4;
     for(int i = random_index; i < random_index + 4; i++)
          for(int j = 0; j < 4; j++)
               tetro[i%4][j] = shapes[i][j];
}

Tetromine::~Tetromine(){
     reset_offset();
}

Tetromine::Tetromine(Tetromine& _t){
     for(int i = 0; i < 4; i++){
          for(int j = 0; j < 4; j++){
               tetro[i][j] = _t.tetro[i][j];
          }
     }
     offset_left = _t.offset_left;
     offset_up = _t.offset_up;
}

void Tetromine::reset_offset(){
     offset_left = COLUMNS / 2 - 2;
     offset_up = 0;
}

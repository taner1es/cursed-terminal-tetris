class Tetromine{
public:
     bool tetro[4][4];
     int offset_left;
     int offset_up;

     Tetromine(); // initialize
     ~Tetromine(); // delete
     Tetromine(Tetromine& _t); // copy
     void reset_offset();
};

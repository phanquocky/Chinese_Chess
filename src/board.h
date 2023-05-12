#pragma once
#include"pieceSet.h"

class Board{
public:
    int _board[8][8] = {
        -1,-2,-3,-4,-5,-3,-2,-1,
        -6,-6,-6,-6,-6,-6,-6,-6,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        6, 6, 6, 6, 6, 6, 6, 6,
        1, 2, 3, 4, 5, 3, 2, 1};
public:
    Board();
    void reset();
    int checkWin();
};
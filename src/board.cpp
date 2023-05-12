
#include"board.h"

int board[8][8] = {
        -1,-2,-3,-4,-5,-3,-2,-1,
        -6,-6,-6,-6,-6,-6,-6,-6,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        6, 6, 6, 6, 6, 6, 6, 6,
        1, 2, 3, 4, 5, 3, 2, 1};

Board::Board(){

}

// kiểm tra có win không trắng win 1, đen win -1, else 0
int Board::checkWin(){
    bool black = 0 ; 
    bool white = 0;
    
    for(int i = 0 ; i < 8 ; i ++){
        for(int j = 0 ; j < 8 ; j ++){
            if(_board[i][j] == 5) white = 1;
            if(_board[i][j] == -5) black = 1;
        }
    }
    
    if(black == 0) return -1;
    if(white == 0) return 1;

    return 0;
}

// reset lại bàn cờ
void Board::reset(){
    for(int i = 0 ; i < 8 ; i ++){
        for(int j = 0 ;j < 8 ; j ++){
            _board[i][j] = board[i][j];
        }
    }
}
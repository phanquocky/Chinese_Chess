#include"pawn.h"

void Pawn::getNextMove(int x, int y, int grid[8][8]){

    int k=grid[x][y]/abs(grid[x][y]);// 1 hoac -1

    // đi đầu tiên có thể tiến 2 nước
    if((x==1 || x==6) &&grid[x - k][y]==0 && grid[x - 2*k][y]==0 && x-2*k>=0 && x-2*k<8)    IncreasePositive(x - 2*k,y);
    
    // tiến 1 nước nếu không có quân cản
    if(grid[x-k][y]==0 && x-k>=0 && x-k<8)                                                  IncreasePositive(x-k,y);
    
    // ăn chéo 1 ô
    if(grid[x-k][y+1]*grid[x][y]<0 && x-k>=0 && x-k<8 && y+1<8)                             IncreasePositive(x-k,y+1);
    if(grid[x-k][y-1]*grid[x][y]<0 && x-k>=0 && x-k<8 && y-1>=0)                            IncreasePositive(x-k,y-1);
}
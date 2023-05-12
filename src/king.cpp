#include"king.h"

void King::getNextMove(int x, int y , int grid[8][8]){

    // duyệt các nước đi của quân vua
    if((grid[x+1][y]==0||grid[x][y]*grid[x+1][y]<0) && x+1<8)                         IncreasePositive(x+1,y);
    if((grid[x-1][y]==0||grid[x][y]*grid[x-1][y]<0) && x-1>=0)                        IncreasePositive(x-1,y);
    if((grid[x+1][y+1]==0||grid[x][y]*grid[x+1][y+1]<0) && x+1<8 && y+1<8)            IncreasePositive(x+1,y+1);
    if((grid[x-1][y+1]==0||grid[x][y]*grid[x-1][y+1]<0) && x-1>=0 && y+1<8)           IncreasePositive(x-1,y+1);
    if((grid[x][y+1]==0||grid[x][y]*grid[x][y+1]<0) && y+1<8)                         IncreasePositive(x,y+1);
    if((grid[x-1][y-1]==0||grid[x][y]*grid[x-1][y-1]<0) && x-1>=0 && y-1>=0)          IncreasePositive(x-1,y-1);
    if((grid[x+1][y-1]==0||grid[x][y]*grid[x+1][y-1]<0) && y-1>=0 && x+1<8)           IncreasePositive(x+1,y-1);
    if((grid[x][y-1]==0||grid[x][y]*grid[x][y-1]<0) && y-1>=0)                        IncreasePositive(x,y-1);
}
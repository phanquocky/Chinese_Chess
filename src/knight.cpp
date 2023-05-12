#include"knight.h"

void Knight::getNextMove(int x, int y , int grid[8][8]){

    // duyệt hết tất cả các trường hợp có ăn quân mã
    if((grid[x+2][y+1]==0||grid[x][y]*grid[x+2][y+1]<0) && x+2<8 && y+1<8)            IncreasePositive(x+2,y+1);
    if((grid[x+2][y-1]==0||grid[x][y]*grid[x+2][y-1]<0) && y-1>=0 && x+2<8)           IncreasePositive(x+2,y-1);
    if((grid[x-2][y+1]==0||grid[x][y]*grid[x-2][y+1]<0) && x-2>=0 && y+1<8)           IncreasePositive(x-2,y+1);
    if((grid[x-2][y-1]==0||grid[x][y]*grid[x-2][y-1]<0) && x-2>=0 && y-1>=0)          IncreasePositive(x-2,y-1);
    if((grid[x+1][y+2]==0||grid[x][y]*grid[x+1][y+2]<0) && x+1<8 && y+2<8)            IncreasePositive(x+1,y+2);
    if((grid[x-1][y+2]==0||grid[x][y]*grid[x-1][y+2]<0) && x-1>=0 && y+2<8)           IncreasePositive(x-1,y+2);
    if((grid[x+1][y-2]==0||grid[x][y]*grid[x+1][y-2]<0) && y-2>=0&& x+1<8)            IncreasePositive(x+1,y-2);
    if((grid[x-1][y-2]==0||grid[x][y]*grid[x-1][y-2]<0) && x-1>=0 && y-2>=0)          IncreasePositive(x-1,y-2);
}
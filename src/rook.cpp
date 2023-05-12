#include"rook.h"

void Rook::getNextMove(int x , int y , int grid[8][8]){

    // xử lý cột tại vị trí của quân xe trở lên
    for(int i= x + 1;i<8;i++){
        if(grid[i][y]!=0) {
            if(grid[i][y]*grid[x][y]<0)  IncreasePositive(i,y); 
            break;
        }
        IncreasePositive(i,y); 
    }

    // xử lý cột tại vị trí của quân xe trở xuống 
    for(int i=x-1;i>=0;i--){
        if(grid[i][y]!=0) {
            if(grid[i][y]*grid[x][y]<0)  IncreasePositive(i,y); 
            break;
        }
        IncreasePositive(i,y); 
    }

    // xử lý hàng từ vị trí quân xe sang phải
    for(int j=y+1;j<8;j++){
        if(grid[x][j]!=0) {
            if(grid[x][j]*grid[x][y]<0)  IncreasePositive(x,j);
            break;
        }
        IncreasePositive(x,j);
    }

    // xử lý hàng từ vị trí quân xe sang trái
    for(int j=y-1;j>=0;j--){
        if(grid[x][j]!=0) {
            if(grid[x][j]*grid[x][y]<0)  IncreasePositive(x,j);
            break;
        }
        IncreasePositive(x,j);
    }
}

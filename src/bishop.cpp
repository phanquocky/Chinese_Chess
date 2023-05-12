#include"bishoop.h"

void Bishoop::getNextMove(int x, int y , int grid[8][8]){
    for(int i=x+1,j=y+1;(i<8&&j<8);i++,j++)
    {
           if(grid[i][j]!=0)   
           {
                  if(grid[i][j]*grid[x][y]<0)       IncreasePositive(i,j);
                  break;
           }
           IncreasePositive(i,j);
    }
    for(int i=x+1,j=y-1;(i<8&&j>=0);i++,j--)
    {
           if(grid[i][j]!=0)  
           {
                  if(grid[i][j]*grid[x][y]<0)       IncreasePositive(i,j);
                  break;
           }
           IncreasePositive(i,j);
    }
    for(int i=x-1,j=y+1;(i>=0&&j<8);i--,j++)
    {
           if(grid[i][j]!=0)  
           {
                  if(grid[i][j]*grid[x][y]<0)       IncreasePositive(i,j);
                  break;
           }
           IncreasePositive(i,j);
    }
    for(int i=x-1,j=y-1;(i>=0 && j>=0);i--,j--)
    {
           if(grid[i][j]!=0)  
           {
                  if(grid[i][j]*grid[x][y]<0)       IncreasePositive(i,j);
                  break;
           }
           IncreasePositive(i,j);
    }
}
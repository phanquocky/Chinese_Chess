#include"queen.h"

// tổ hợp của quân xe và tượng
void Queen::getNextMove(int x , int y , int grid[8][8]){
    
    for(int i= x + 1;i<8;i++)
    {
        if(grid[i][y]!=0) {
            if(grid[i][y]*grid[x][y]<0)  IncreasePositive(i,y); 

            break;
        }
        IncreasePositive(i,y); 

    }

    for(int i=x-1;i>=0;i--)
    {
        if(grid[i][y]!=0) {
            if(grid[i][y]*grid[x][y]<0)  IncreasePositive(i,y); 
            break;
        }
        IncreasePositive(i,y); 
    }
    
    for(int j=y+1;j<8;j++)
    {
        if(grid[x][j]!=0) {
            if(grid[x][j]*grid[x][y]<0)  IncreasePositive(x,j);
            break;
        }
        IncreasePositive(x,j);
    }
   
    for(int j=y-1;j>=0;j--)
    {
        if(grid[x][j]!=0) {
            if(grid[x][j]*grid[x][y]<0)  IncreasePositive(x,j);
            break;
        }
        IncreasePositive(x,j);
    }

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
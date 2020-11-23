#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

char board[ROW][COLUMN];

void print_board(char board[ROW][COLUMN])   // 보드판 출력 
{
   
   int i, j;
   printf("  %d %d %d %d %d %d\n",0, 1, 2, 3, 4, 5, 6);
   
   for(i=0; i<ROW; i++)
   {
      printf(" -------------\n");
      printf("%d", i);
      for (j=0; j<6; j++)
      {
         printf("|%c", board[i][j]);
      }
      printf("|");
      printf("\n");
      
   }
}

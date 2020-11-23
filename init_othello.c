#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

char board[ROW][COLUMN];


void initial_board(char board[ROW][COLUMN]) // 보드판 초기화 
{
   int i,j;
   for (i=0; i<ROW; i++)
   {
      for (j=0; j<COLUMN; j++)
      {
         board[i][j] = ' ';
      }
   }
   
   board[2][2] = 'W';
   board[2][3] = 'B';
   board[3][2] = 'B';
   board[3][3] = 'W';
}

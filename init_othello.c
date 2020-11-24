#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

char board[ROW][COLUMN];  // board 변수 선언 

void initial_board(char board[ROW][COLUMN]) // 보드판 초기화 
{
   int i,j;   // for 문 돌릴 변수 선언 
   for (i=0; i<ROW; i++)      // for문을 돌면서 모든 보드판 빈칸으로 초기화 
   {
      for (j=0; j<COLUMN; j++)
      {
         board[i][j] = ' ';
      }
   }
   // 보드판 정중앙 4칸에 흰색 및 검정색 알을 2개씩 대각선으로 놓는다. 
   board[2][2] = 'W';
   board[2][3] = 'B';
   board[3][2] = 'B';
   board[3][3] = 'W';
}

#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

char board[ROW][COLUMN];  // board ���� ���� 

void initial_board(char board[ROW][COLUMN]) // ������ �ʱ�ȭ 
{
   int i,j;   // for �� ���� ���� ���� 
   for (i=0; i<ROW; i++)      // for���� ���鼭 ��� ������ ��ĭ���� �ʱ�ȭ 
   {
      for (j=0; j<COLUMN; j++)
      {
         board[i][j] = ' ';
      }
   }
   // ������ ���߾� 4ĭ�� ��� �� ������ ���� 2���� �밢������ ���´�. 
   board[2][2] = 'W';
   board[2][3] = 'B';
   board[3][2] = 'B';
   board[3][3] = 'W';
}

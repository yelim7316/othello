
#define ROW 6
#define COLUMN 6

int count_num(char board[ROW][COLUMN], char c)  // �� ���� ���� �Լ� 
{
   int i, j;                       // for�� ���� ���� ���� 
   int count=0;                   // ���� ������ ������ ���� ���� �� �ʱ�ȭ 
   for (i=0; i<ROW; i++)          // for���� ���鼭 ���� ������ ����. 
   {
      for (j=0; j< COLUMN; j++)
      {
         if (board[i][j] == c)
            count ++;
      }
   }
   return count;
}

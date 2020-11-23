
#define ROW 6
#define COLUMN 6

int count_num(char board[ROW][COLUMN], char c)  // 알 개수 세기 
{
   int i, j;
   int count=0;
   for (i=0; i<ROW; i++)
   {
      for (j=0; j< COLUMN; j++)
      {
         if (board[i][j] == c)
            count ++;
      }
   }
   return count;
}


#define ROW 6
#define COLUMN 6

int count_num(char board[ROW][COLUMN], char c)  // 알 개수 세는 함수 
{
   int i, j;                       // for문 돌릴 변수 선언 
   int count=0;                   // 알의 개수를 저장할 변수 선언 및 초기화 
   for (i=0; i<ROW; i++)          // for문을 돌면서 알의 개수를 센다. 
   {
      for (j=0; j< COLUMN; j++)
      {
         if (board[i][j] == c)
            count ++;
      }
   }
   return count;
}

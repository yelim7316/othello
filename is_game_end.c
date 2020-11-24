#define ROW 6
#define COLUMN 6

char board[ROW][COLUMN];         // board ���� ����

int is_game_end (char _player)   // ������ �������� Ȯ���ϴ� �Լ� 
{
   int blank_check = 0;
   int i,j;
   int m,n;
   char temp_same_side = ' '; 
   for (m = 0; m < 6; m++)  // �������� �ϳ��� ������ �Ǿ��ִ��� Ȯ�� 
   {
      for (n = 0; n< 6; n++)
      {
         // 1. temp�� ���� �ִ´�. 2. temp�� board[m][n]�� ���� ���Ѵ�.  
         if(temp_same_side == ' ') 
            if(board[m][n] != ' ') // ��� ĭ�� ��ĭ�� �ƴҶ� b_check =1  
               temp_same_side = board[m][n];
         else if(temp_same_side !=  ' ')
            if (board[m][n] != ' ' && board[m][n] != temp_same_side)
            {
               m = 7;
               n = 7;
               break;
            }
      }
   }
   
   for (m = 0; m < 6; m++)  // ��� ĭ�� ä�����ִ��� Ȯ�� 
   {
      for (n = 0; n< 6; n++)
      {
         if(board[m][n] == ' ') // ��� ĭ�� ��ĭ�� �ƴҶ� blank_check = 1  
               blank_check++;
      }
   }
   if (blank_check == 0)
      return 1;


   for (i = 0; i < 6; i++)
   {
      for (j = 0; j < 6; j++)
      {
         if (board [i][j] == ' ')  // ��ĭ�϶� Ȯ���Ѵ�. 
         {
            if (valid_move(_player, i,j) == 1)  // valid_move2�� 1�� ��ȯ�� ���� �� �ְ� ������ ��� �����Ѵ�.  
            {
               return 0; // ���� ��� ���� 
            } 
            else if (i == 5 && j == 5 ) // ��� �ǿ� ���ؼ� Ȯ���Ѵ�.  
                 return 1;
                
         }
      }
   }
   
} 

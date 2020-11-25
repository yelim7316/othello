#define ROW 6
#define COLUMN 6

char board[ROW][COLUMN];         // board ���� ����

int is_game_end (char _player)   // ������ �������� Ȯ���ϴ� �Լ� 
{
   int blank_check = 0;          // ��ĭ�� check��  blank_check ���� ���� 
   int i,j;                     // for ���� ���� ���� ���� 
   int m,n;                     // for ���� ���� ���� ���� 
   char temp_same_side = ' ';   // �������� �ϳ��� ������ Ȯ���ϴ� ���� 
   
   for (m = 0; m < 6; m++)      // �������� �ϳ��� ������ �Ǿ��ִ��� Ȯ���ϱ� ���� for���� ����. 
   {
      for (n = 0; n< 6; n++)
      { 
         if(temp_same_side == ' ')
		 {
		 	if(board[m][n] != ' ') 
               temp_same_side = board[m][n];
		 }     
         else if(temp_same_side !=  ' ')
		 {
		 	if (board[m][n] != ' ' && board[m][n] != temp_same_side)
            {
               m = 7;
               n = 7;
               break;
            }
		 }
            
      }
   }
   
   for (m = 0; m < 6; m++)         // ��� ĭ�� ä�����ִ��� Ȯ���ϱ� ���� for���� ����. 
   {
      for (n = 0; n< 6; n++)
      {
         if(board[m][n] == ' ')   // ��ĭ�� �� blank_check�� 1 ���ϱ�  
               blank_check++;
      }
   }
   if (blank_check == 0)        // ��� ĭ�� ��ĭ�� �ƴ϶� ��� ä���������� blank_check �� 0�̰� 1 ��ȯ�Ѵ�.
      return 1;


   for (i = 0; i < 6; i++)     
   {
      for (j = 0; j < 6; j++)
      {
         if (board [i][j] == ' ')                // ��ĭ�϶� Ȯ���Ѵ�. 
         {
            if (valid_move(_player, i,j) == 1)  // valid_move�� 1�� ��ȯ�� ���� ���� �� �ְ� ������ ��� �����Ѵ�.  
            {
               return 0;                         // ���� ��� ���� 
            } 
            else if (i == 5 && j == 5 )         // ��� �ǿ� ���ؼ� Ȯ���Ѵ�.  
                 return 1;
                
         }
      }
   }
   
} 

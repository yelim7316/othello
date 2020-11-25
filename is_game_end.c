#define ROW 6
#define COLUMN 6

char board[ROW][COLUMN];         // board 변수 선언

int is_game_end (char _player)   // 게임이 끝났는지 확인하는 함수 
{
   int blank_check = 0;          // 빈칸을 check할  blank_check 변수 선언 
   int i,j;                     // for 문을 돌릴 변수 선언 
   int m,n;                     // for 문을 돌릴 변수 선언 
   char temp_same_side = ' ';   // 보드판이 하나의 색인지 확인하는 변수 
   
   for (m = 0; m < 6; m++)      // 보드판이 하나의 색으로 되어있는지 확인하기 위해 for문을 돈다. 
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
   
   for (m = 0; m < 6; m++)         // 모든 칸이 채워져있는지 확인하기 위해 for문을 돈다. 
   {
      for (n = 0; n< 6; n++)
      {
         if(board[m][n] == ' ')   // 빈칸일 때 blank_check에 1 더하기  
               blank_check++;
      }
   }
   if (blank_check == 0)        // 모든 칸이 빈칸이 아니라 모두 채워져있으면 blank_check 는 0이고 1 반환한다.
      return 1;


   for (i = 0; i < 6; i++)     
   {
      for (j = 0; j < 6; j++)
      {
         if (board [i][j] == ' ')                // 빈칸일때 확인한다. 
         {
            if (valid_move(_player, i,j) == 1)  // valid_move가 1을 반환시 알을 놓을 수 있고 게임은 계속 진행한다.  
            {
               return 0;                         // 게임 계속 진행 
            } 
            else if (i == 5 && j == 5 )         // 모든 판에 대해서 확인한다.  
                 return 1;
                
         }
      }
   }
   
} 

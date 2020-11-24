#define ROW 6
#define COLUMN 6

char board[ROW][COLUMN];         // board 변수 선언

int is_game_end (char _player)   // 게임이 끝났는지 확인하는 함수 
{
   int blank_check = 0;
   int i,j;
   int m,n;
   char temp_same_side = ' '; 
   for (m = 0; m < 6; m++)  // 보드판이 하나의 색으로 되어있는지 확인 
   {
      for (n = 0; n< 6; n++)
      {
         // 1. temp에 값을 넣는다. 2. temp랑 board[m][n]의 값을 비교한다.  
         if(temp_same_side == ' ') 
            if(board[m][n] != ' ') // 모든 칸이 빈칸이 아닐때 b_check =1  
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
   
   for (m = 0; m < 6; m++)  // 모든 칸이 채워져있는지 확인 
   {
      for (n = 0; n< 6; n++)
      {
         if(board[m][n] == ' ') // 모든 칸이 빈칸이 아닐때 blank_check = 1  
               blank_check++;
      }
   }
   if (blank_check == 0)
      return 1;


   for (i = 0; i < 6; i++)
   {
      for (j = 0; j < 6; j++)
      {
         if (board [i][j] == ' ')  // 빈칸일때 확인한다. 
         {
            if (valid_move(_player, i,j) == 1)  // valid_move2가 1을 반환시 놓을 수 있고 게임은 계속 진행한다.  
            {
               return 0; // 게임 계속 진행 
            } 
            else if (i == 5 && j == 5 ) // 모든 판에 대해서 확인한다.  
                 return 1;
                
         }
      }
   }
   
} 

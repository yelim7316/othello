#define ROW 6
#define COLUMN 6

char board[ROW][COLUMN];

int is_game_end (char _player)   // check the game is over 
{
   int blank_check = 0;          // the variable that check the blank 
   int i,j;                  
   int m,n;                   
   char temp_same_side = ' ';   // variable to check board is one color
   
   for (m = 0; m < 6; m++)      // check board is one color
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
   
   for (m = 0; m < 6; m++)         // check the board are filled
   {
      for (n = 0; n< 6; n++)
      {
         if(board[m][n] == ' ')  
               blank_check++;
      }
   }
   if (blank_check == 0)        // if the board are filled all, return 1
      return 1;


   for (i = 0; i < 6; i++)     
   {
      for (j = 0; j < 6; j++)
      {
         if (board [i][j] == ' ')                
         {
            if (valid_move(_player, i,j) == 1)  // if valid_move returns 1, the player can put the piece and the game is going on
            {
               return 0;      
            } 
            else if (i == 5 && j == 5 )  
                 return 1;
                
         }
      }
   }
   
} 

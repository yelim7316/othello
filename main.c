#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define ROW 6
#define COLUMN 6
#define SIZE 6

#define TRUE 1
#define FALSE 0

int now_ROW;
int now_COLUMN;
char board[ROW][COLUMN];
int directions[8] = {0,0,0,0,0,0,0,0};      // 왼쪽 위 대각, 위, 오른쪽 위 대각 
int flip_count[8] = {0,0,0,0,0,0,0,0};   //뒤집은 개수 

void initial_board(char board[ROW][COLUMN]) // 보드판 초기화 
{
   int i,j;
   for (i=0; i<ROW; i++)
   {
      for (j=0; j<COLUMN; j++)
      {
         board[i][j] = ' ';
      }
   }
   
   board[2][2] = 'W';
   board[2][3] = 'B';
   board[3][2] = 'B';
   board[3][3] = 'W';
}


void print_board(char board[ROW][COLUMN])   // 보드판 출력 
{
   
   int i, j;
   printf("  %d %d %d %d %d %d\n",0, 1, 2, 3, 4, 5, 6);
   
   for(i=0; i<ROW; i++)
   {
      printf(" -------------\n");
      printf("%d", i);
      for (j=0; j<6; j++)
      {
         printf("|%c", board[i][j]);
      }
      printf("|");
      printf("\n");
      
   }
}

void print_status(int white, int black, int counter)   // 현재 상태 나타내기 
{
   char *current_player = (counter % 2 == 0)? "Black":"White";
   printf("STATUS - WHITE: %d, BLACK: %d\n", white, black);
   printf("%d TURN: %s player's turn.\n", counter, current_player);
}


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


int valid_move(char player, int row, int column )  // 올바른 입력인지 확인   
{
   int cnt = 0;
   char othello_board2[36] = 
   { ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' '};

   int i;
   int row_, column_;
   
   for(row_ = 0; row_ < ROW; row_++ )  // 2차원 배열의 board를 1차원의 othello_board2 배열에 저장 
   {
      for ( column_ = 0; column_ < COLUMN; column_++)
      {
      
         othello_board2[cnt] = board[row_][column_];
         cnt++; 
        
      }
   } 
     
   int index = (row * 6) + column;  // row와 column을 통해 1차원의 index 변수에 저장 
   
   if ( player == 'W' )
   { 
        if ((row != 0 && column != 0) && othello_board2[index - 7] == 'B') // 왼쪽 대각선 
        {
            int f_cnt_leftup = 0;        // 왼쪽 대각선에 있는 알을 뒤집은 개수를 저장할 변수 
            int temp_index = index - 7;  // 왼쪽 대각선에 있는 알을 확인하기 위한 변수 
         	while(TRUE)
         	{
            	if (othello_board2[temp_index] == 'B') // 주변에 player 의 알이 있다면 
                	f_cnt_leftup += 1;
             	else if (othello_board2[temp_index] == ' ')
	                break;
    	        else if (othello_board2[temp_index] == 'W')
        	    {
            	    directions[0] = 1;
                	flip_count[0] = f_cnt_leftup;
                	break;
            	}  
            	
            	int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6; 

             	if (temp_row == 0 || temp_column == 0)
                	break;
             	else
             		temp_index -= 7;
         	}     
        }
      //---------------------------------------------------------------------------
      	if ( row != 0 && othello_board2[index - 6] == 'B') // 위 쪽 
       {
            int f_cnt_up = 0;
            int temp_index = index - 6;
         	while(TRUE)
         	{
            	if (othello_board2[temp_index] == 'B') // 주변에 player 의 알이 있다면
                	f_cnt_up += 1;
             	else if (othello_board2[temp_index] == ' ')
                	break;
             	else if (othello_board2[temp_index] == 'W')
            	{
               		directions[1] = 1;
                	flip_count[1] = f_cnt_up;
                	break;
            	}
            
				int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;
            	if (temp_row == 0)
                	break;
             	else
             		temp_index -= 6;
        	}      
       }   
       
	   //---------------------------------------------------------------------------
      	if ((row != 0 && column != 5) && othello_board2[index - 5] == 'B') // 오른쪽 위 
    	{
            int f_cnt_rightup = 0;
            int temp_index = index - 5;
         	while(TRUE)
         	{
	            if (othello_board2[temp_index] == 'B') // 주변에 player 의 알이 있다면
    	            f_cnt_rightup += 1;
	            else if (othello_board2[temp_index] == ' ')
		            break;
	            else if (othello_board2[temp_index] == 'W')
        	    {
            		directions[2] = 1;
                	flip_count[2] = f_cnt_rightup;
                	break;
            	}
				int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;

            	if (temp_row == 0 || temp_column == 5)
               		break;
            	else
            		temp_index -= 5;
         }      
       }   
      
      //---------------------------------------------------------------------------
      
      	if ( column != 0 && othello_board2[index - 1] == 'B') // 왼쪽 
         {
            int f_cnt_left = 0;
            int temp_index = index - 1;
        	while(TRUE)
         	{
            	if (othello_board2[temp_index] == 'B') // 주변에 player 의 알이 있다면
                	f_cnt_left += 1;
             	else if (othello_board2[temp_index] == ' ')
	                break;
    	        else if (othello_board2[temp_index] == 'W')
	            {
    	            directions[3] = 1;
        	        flip_count[3] = f_cnt_left;
            	    break;
            	}
            	
             	int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;
            	
            	if (temp_column == 0)
                	break;
             	else 
             		temp_index -= 1;
        	}      
       }
        
	 //---------------------------------------------------------------------------
      	if ( column != 5 && othello_board2[index + 1] == 'B') // 오른쪽 
        {
            int f_cnt_right = 0;
            int temp_index = index + 1;
         	while(TRUE)
         	{
            	if (othello_board2[temp_index] == 'B') // 주변에 player 의 알이 있다면
	                f_cnt_right += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'W')
	            {
	            	directions[4] = 1;
	                flip_count[4] = f_cnt_right;
	                break;
	            }
	            
                int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;
            	
             	if (temp_column == 5)
                	break;
             	else
             		temp_index += 1;
        	}      
       }
     //---------------------------------------------------------------------------
      	if ((row != 5 && column != 0) && othello_board2[index + 5] == 'B') // 왼쪽 아래 
        {
            int f_cnt_leftdown = 0;
            int temp_index = index + 5;
	        while(TRUE)
	    	{
	        	if (othello_board2[temp_index] == 'B') // 주변에 player 의 알이 있다면
	          		f_cnt_leftdown += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'W')
	            {
	            	directions[5] = 1;
	                flip_count[5] = f_cnt_leftdown;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;
            	
	            if (temp_row == 5 || temp_column == 0)
	                break;
	            else
	            	temp_index += 5;
	        }      
	    }
       //---------------------------------------------------------------------------
      	if (row != 5 && othello_board2[index + 6] == 'B') // 아래 
        {
            int f_cnt_down = 0;
            int temp_index = index + 6;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'B') // 주변에 player 의 알이 있다면
	                f_cnt_down += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'W')
	            {
	                directions[6] = 1;
	                flip_count[6] = f_cnt_down;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;
            	
	            if (temp_row == 5)
	         	   	break;
	            else 
	            	temp_index += 6;
	        }      
       }
       
      //---------------------------------------------------------------------------
      	if ((row != 5 && column != 5) && othello_board2[index + 7] == 'B') // 오른쪽 아래 
        {
            int f_cnt_rightdown = 0;
            int temp_index = index + 7;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'B') // 주변에 player 의 알이 있다면
	                f_cnt_rightdown += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'W')
	            {
	                directions[7] = 1;
	                flip_count[7] = f_cnt_rightdown;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;
				 
	            if (temp_row == 5 || temp_column == 5)
	                break;
	            else
	            	temp_index += 7;
	        }      
        }   
   }
   
   /*************************************** player 가 Black 일 때 *********************************************/
   if ( player == 'B' )
   {
      
        if ((row != 0 && column != 0) && othello_board2[index - 7] == 'W') // 왼쪽 대각선 
        {
            int f_cnt_leftup = 0;
            int temp_index = index - 7;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'W') // 주변에 player 의 알이 있다면
	                f_cnt_leftup += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'B')
	            {
	                directions[0] = 1;
	                flip_count[0] = f_cnt_leftup;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
	            int temp_column = temp_index % 6;
	            
	            if (temp_row == 0 || temp_column == 0)
	                break;
	            else
	             	temp_index -= 7;
	        }      
    	}   
      //---------------------------------------------------------------------------
      	if (row != 0 && othello_board2[index - 6] == 'W') // 위 쪽 
        {
            int f_cnt_up = 0;
            int temp_index = index - 6;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'W') // 주변에 player 의 알이 있다면
	                f_cnt_up += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'B')
	            {
	                directions[1] = 1;
	                flip_count[1] = f_cnt_up;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
	            int temp_column = temp_index % 6;
	            
	            if (temp_row == 0)
	                break;
	            else
	             	temp_index -= 6;
	        }      
        } 
	     
     //---------------------------------------------------------------------------
      	if ((row != 0 && column != 5) && othello_board2[index - 5] == 'W') // 오른쪽 위 
        {
            int f_cnt_rightup = 0;
            int temp_index = index - 5;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'W') // 주변에 player 의 알이 있다면
	                f_cnt_rightup += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'B')
	            {
	                directions[2] = 1;
	                flip_count[2] = f_cnt_rightup;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;
            	
	            if (temp_row == 0 || temp_column == 5)
	                break;
	            else
	            	temp_index -= 5;
	        }      
        }   
      
      //---------------------------------------------------------------------------
      
      	if (column != 0 && othello_board2[index - 1] == 'W') // 왼쪽 
        {
            int f_cnt_left = 0;
            int temp_index = index - 1;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'W') // 주변에 player 의 알이 있다면
	                f_cnt_left += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'B')
	            {
	                directions[3] = 1;
	                flip_count[3] = f_cnt_left;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
	            int temp_column = temp_index % 6;
	            
	            if (temp_column == 0)
	                break;
	            else
	            	temp_index -= 1;
	        }      
       }
      
      //---------------------------------------------------------------------------
      	if (column != 5 && othello_board2[index + 1] == 'W') // 오른쪽 
        {
            int f_cnt_right = 0;
            int temp_index = index + 1;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'W') // 주변에 player 의 알이 있다면
	                f_cnt_right += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'B')
	            {
	                directions[4] = 1;
	                flip_count[4] = f_cnt_right;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;    
            	
	            if (temp_column == 5)
	                break;
	            else 
	            	temp_index += 1;
	        }      
       }
       
       //--------------------------------------------------------------------------- 
      	if ((row != 5 && column != 0) && othello_board2[index + 5] == 'W') // 왼쪽 아래 
        {
            int f_cnt_leftdown = 0;
            int temp_index = index + 5;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'W') // 주변에 player 의 알이 있다면
	                f_cnt_leftdown += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'B')
	            {
	                directions[5] = 1;
	                flip_count[5] = f_cnt_leftdown;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;
            	
	            if (temp_row == 5 || temp_column == 0)
	                break;
	            else
	            	temp_index += 5;
	        }      
       	}
    //---------------------------------------------------------------------------
      	if (row != 5 && othello_board2[index + 6] == 'W') // 아래 
        {
            int f_cnt_down = 0;
            int temp_index = index + 6;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'W') // 주변에 player 의 알이 있다면
	                f_cnt_down += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'B')
	            {
	                directions[6] = 1;
	                flip_count[6] = f_cnt_down;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
            	int temp_column = temp_index % 6;  
            	
	            if (temp_row == 5)
	                break;
	            else
	            	temp_index += 6;
	        }      
        }
      //--------------------------------------------------------------------------- 
      	if ((row != 5 && column != 5) && othello_board2[index + 7] == 'W') // 오른쪽 아래 
        {
            int f_cnt_rightdown = 0;
            int temp_index = index + 7;
	        while(TRUE)
	        {
	            if (othello_board2[temp_index] == 'W') // 주변에 player 의 알이 있다면
	                f_cnt_rightdown += 1;
	            else if (othello_board2[temp_index] == ' ')
	                break;
	            else if (othello_board2[temp_index] == 'B')
	            {
	               directions[7] = 1;
	                flip_count[7] = f_cnt_rightdown;
	                break;
	            }
	            
	            int temp_row = temp_index / 6;
	            int temp_column = temp_index % 6;
	            
	            if (temp_row == 5 || temp_column == 5)
	                break;
	            else
	            	temp_index += 7;
	        }      
       }   
   }
   
   
   for (i = 0; i < 8; i++)  // directions[i]가 1인지 0인지 판단하는 반복문 , 1이면 valid move이지만 0 이면 invalid move !!!! 
   {
         if (directions[i] == 1)
    	{
            return 1;
    	}
   }
   return 0;
}



void input_value(char board[ROW][COLUMN], int counter )
{
   int row;
   int column;
   
   int player= (counter %2 == 0)? 'B':'W';
   
   while (TRUE)
   {
      printf("put a new othello(such as 4 5): ");
      scanf("%d %d", &row, &column);
      
      if (board[row][column] != ' ')  // 이미 알이 놓여져 있는 곳일 때  
      { 
         printf("Not a valid move!(already occupied)\n"); // 알을 놓지 못함을 출력 
         input_value(board, counter);
      }
         
      if (valid_move(player, row, column) == 1 ) 
         break;
      else (printf("Not a valid move!\n"));
   
    }
    
    now_ROW= row;
    now_COLUMN= column;
    board[row][column] = (counter %2 == 0)? 'B':'W';
}



 void flip_pieces(char board[ROW][COLUMN], int counter) // 알 뒤집기 
 {
     int i,j;
     char do_Flip = counter % 2 == 0 ? 'B':'W';
     char to_Flip = counter % 2 == 1 ? 'B':'W';
     for ( i = -1; i <= 1; i++)
     {
        for ( j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (board[now_ROW + i][now_COLUMN + j] == to_Flip)   // 현재 row와 column에서 8방향으로 상대편 알이 있는지 확인 
            {
            	//if (now_ROW + i >=0 && now_ROW < ROW && NOW_COLUMN +j >=0 && now_COLUMN+j < COLUMN && board[now_ROW+i][now_COLUMN+j] == to_Flip)
            	// (5,3)이고, i=1, j= -1일때 now_ROW + i = 6  
                
				int flag = FALSE;
                int x = now_ROW + i;
                int y = now_COLUMN + j;
                while (x < ROW && x >= 0 && y < COLUMN && y >= 0) // while (x < =7 && x>=0 && y<=7 && y>=0) ---5로 바꾸거나 ROW & COLUMN 매크로 쓰기 
                {
                    if (board[x][y] == do_Flip )
                    {
                        flag = TRUE;
                        break;
                    }
                    else if (board[x][y] == ' ')
                        break;
                    x += i;
                    y += j;
                }
                
                x = now_ROW + i;
                y = now_COLUMN + j;
                if (flag)
                {
                    while (board[x][y] != do_Flip )
                    {
                        board[x][y] = do_Flip;
                        x += i;
                        y += j;
                    }
                }
            }
        }
    }
    
    int m;
    printf("             ::: Flip result :::\n");  // 뒤집은 결과를 출력 
    for (m = 0; m < 8 ; m++)
    {
       switch(m)
       {
          case 0:
             printf("NW: ");
             break;
          case 1:
             printf("N: ");
             break;
          case 2:
             printf("NE: ");
             break;
          case 3:
             printf("W: ");
             break;
          case 4:
             printf("E: ");
             break;
          case 5:
             printf("SW: ");
             break;
          case 6:
             printf("S: ");
             break;
          case 7:
             printf("SE: ");
             break;
      }
    	printf("%d  ", flip_count[m]);
   }
   printf("\n");
   switch(do_Flip)
   {
      case 'B':
         printf("Black ");
         break;
      case 'W':
         printf("White ");
         break;         
   }
   printf("has flipped %d othellos!\n\n\n", flip_count[0] + flip_count[1] + flip_count[2]+ flip_count[3]+ flip_count[4]+ flip_count[5]+ flip_count[6]+ flip_count[7]);
    // directions[i]가 1인 아이들과 그 아이들을 통해서 몇개를 뒤집었는지 (flip_count[i]) 
 }



void check_result(int white, int black)   // 결과 출력 
{
   char *winner = (white > black)? "White" : "Black";
   printf("RESULT- WHITE: %d, BLACK: %d", white, black);
   printf("\nThe winner is %s player", winner);
}


int is_game_end (char _player)   // 게임이 끝났는지 확인 
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

// is_game_end가 잘 작동하는지 확인하기 위한 함수 
/*void check_board(char board[ROW][COLUMN])
{
	int i,j;
	for(i = 0; i<6; i++)
	{
		for(j = 0; j<6; j++)
		{
			if (i == 0 && j ==5)
			{
				board[i][j] = ' ';
			}
			else if (i == 5 && j == 0)
			{
				board[i][j] = 'W';
			}
			else 
			  board[i][j] = 'B';
			
		}
	}
}
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   
   int count_turn = 1; 
   int game_ing = 1;

	//check_board(board);
	initial_board(board); // 게임초기화 

   int num_white = count_num(board, 'W');
   int num_black = count_num(board, 'B');
      
      
      
   do 
   {
      // directions[8] = int{0,0,0,0,0,0,0,0};
      // flip_count[8] = int{0,0,0,0,0,0,0,0};
      int q;
      for(q = 0; q < 8; q++)
      {
         directions[q] = 0;
         flip_count[q] = 0;
      }
      
    	print_board(board);   // 보드판 출력 
    	print_status(num_white, num_black, count_turn );
      
      char temp_player;
      switch(count_turn % 2)
      {
         case 0:
            temp_player = 'B';
            break;
         case 1:
            temp_player = 'W';
            break;
      }
   
    	if ( is_game_end('B') == 1 && is_game_end('W') == 1)
		{
			printf("게임 끝\n");
		 	game_ing = 0;		 
		}
		else if (is_game_end(temp_player) == 1)
       		printf("PASS");
        else
		{
			for(q = 0; q < 8; q++)   //directions, flip_count 초기화
      		{
         		directions[q] = 0;
         		flip_count[q] = 0;
          	}
	   		input_value(board, count_turn);
       		flip_pieces(board, count_turn);
    	}
       
      	count_turn ++;
      	num_white = count_num(board, 'W');
      	num_black = count_num(board, 'B');
   } while (game_ing);
   
   
   print_board(board);
   check_result(num_white, num_black);
   
   
   return 0;
}

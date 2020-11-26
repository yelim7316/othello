#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

#define TRUE 1
#define FALSE 0

int now_ROW;
int now_COLUMN;
char board[ROW][COLUMN];
int directions[8] = {0,0,0,0,0,0,0,0};     // 왼쪽 위 대각, 위, 오른쪽 위 대각, 오른쪽, 오른쪽 아래 대각, 아래, 왼쪽 아래 대각, 왼쪽 - 8개 방향을 배열로 정의 
int flip_count[8] = {0,0,0,0,0,0,0,0};    //뒤집은 개수 

int valid_move(char player, int row, int column )  // 올바른 입력인지 확인   
{
   int cnt = 0;
   char othello_board2[36] =            // 1차원 배열 othello_board2[36] 선언   
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
     
   int index = (row * 6) + column;  // row와 column을 1차원의 index 변수에 저장 
   
    /*************************************** player 가 White 일 때 *********************************************/
   if ( player == 'W' )
   { 
        if ((row != 0 && column != 0) && othello_board2[index - 7] == 'B') // 왼쪽 대각선 
        {
            int f_cnt_leftup = 0;        // 왼쪽 대각선에 있는 알을 뒤집은 개수를 저장할 변수 
            int temp_index = index - 7;  // 왼쪽 대각선에 있는 알을 확인하기 위한 변수 
         	while(TRUE)
         	{
            	if (othello_board2[temp_index] == 'B') // 왼쪽 대각선에 상대편 알이 있다면 
                	f_cnt_leftup += 1;
             	else if (othello_board2[temp_index] == ' ')
	                break;
    	        else if (othello_board2[temp_index] == 'W')  //상대편 알의 왼쪽 대각선에 현재 player의 알(white)이 있다면
        	    {
            	    directions[0] = 1;
                	flip_count[0] = f_cnt_leftup;
                	break;
            	}  
            	
            	int temp_row = temp_index / 6;        //알의 왼쪽 대각선 위치의 row를 temp_row 라는 변수에 저장
            	int temp_column = temp_index % 6;     // 알의 왼쪽 대각선 위치의 column를 temp_column 이라는 변수에 저장

            	if (temp_row == 0 || temp_column == 0)   // 0번째 row와 column 에서 왼쪽 대각선은 없으니까 break 한다. 
                	break;
             	else                                   // 0번째 row와 column이 아니면 temp_index에서 7을 빼면서 계속 왼쪽 대각선을 확인
             		temp_index -= 7;
         	}     
        }
      //---------------------------------------------------------------------------
      	if ( row != 0 && othello_board2[index - 6] == 'B') // 위 쪽 
       {
            int f_cnt_up = 0;
            int temp_index = index - 6;
         	while(TRUE)                                    // 주변에 player의 알이 있는지 확인  
         	{
            	if (othello_board2[temp_index] == 'B') 
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
         	while(TRUE)                                       // 주변에 player의 알이 있는지 확인 
         	{
	            if (othello_board2[temp_index] == 'B')
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
        	while(TRUE)                                  // 주변에 player의 알이 있는지 확인 
         	{
            	if (othello_board2[temp_index] == 'B') 
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
         	while(TRUE)                                     // 주변에 player의 알이 있는지 확인 
         	{
            	if (othello_board2[temp_index] == 'B') 
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
	        while(TRUE)                                         // 주변에 player의 알이 있는지 확인 
	    	{
	        	if (othello_board2[temp_index] == 'B')
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
	        while(TRUE)                                         // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'B') 
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
	        while(TRUE)                                       // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'B') 
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
	        while(TRUE)                                       // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'W') 
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
	        while(TRUE)                                      // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'W') 
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
	        while(TRUE)                                          // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'W')
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
	        while(TRUE)                                        // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'W') 
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
	        while(TRUE)                                         // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'W') 
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
	        while(TRUE)                                        // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'W') 
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
	        while(TRUE)                                      // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'W') 
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
	        while(TRUE)                                      // 주변에 player의 알이 있는지 확인 
	        {
	            if (othello_board2[temp_index] == 'W') 
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
   
   
   for (i = 0; i < 8; i++)  // directions[i]가 1인지 0인지 판단하는 반복문 , 1이면 valid move이지만 0 이면 invalid move  
   {
         if (directions[i] == 1)
    	{
            return 1;
    	}
   }
   return 0;
}



void input_value(char board[ROW][COLUMN], int counter )   // 알을 놓을 위치 입력하라고 명령하는 함수 
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



 void flip_pieces(char board[ROW][COLUMN], int counter) // 알 뒤집는 함수 
 {
    int m,n;         // for문 돌기 위한 변수 
     
	char do_Flip;   // 뒤집기를 할 알의 저장 
	if (counter % 2 == 0)
	{
	 	do_Flip = 'B';
	}
	else
	{
	 	do_Flip = 'W';
	}
	
	char to_Flip;   // 뒤집힐 알 저장 
	if ( counter % 2 == 1)
	{
	 	to_Flip = 'B';
	}
	else
	{
	 	to_Flip = 'W';
	}
	 
	 
     for (m = -1; m <= 1; m++)   // 내가 놓은 알로부터 8개 방향으로 for문을 돈다.  
     {
        for (n = -1; n <= 1; n++)
        {
            if (m == 0 && n == 0)   // 내가 놓은 알의 위치  
                continue;
            if (now_ROW + m >=0 && now_ROW + m < ROW && now_COLUMN +n >=0 && now_COLUMN + n < COLUMN && board[now_ROW+m][now_COLUMN+n] == to_Flip)   // 현재 row와 column에서 8방향으로 상대편 알이 있는지 확인 
            {
                int R = now_ROW + m;       // 현재 row에서 8방향으로 돌면서 row의 위치를 R 에 저장 
                int C = now_COLUMN + n;    // 현재 column에서 8방향으로 돌면서 column의 위치를 C 에 저장 
                int flag = FALSE;
                
                while (R < ROW && R >= 0 && C < COLUMN && C >= 0) 
                {
                    if (board[R][C] == do_Flip )   // 8방향으로 돌때 현재 player의 알이 있으면 
                    {
                        flag = TRUE;
                        break;
                    }
                    else if (board[R][C] == ' ')   // 빈칸이면 break
                        break;
                    R += m;
                    C += n;
                }
                
                R = now_ROW + m;
                C = now_COLUMN + n;
                if (flag)
                {
                    while (board[R][C] != do_Flip )  // R이라는 row와 C이라는 column의 위치에 현재 player의 알이 놓여있는게 아니라면
                    {
                        board[R][C] = do_Flip;        // 현재 player의 알이 된다. 
                        R += m;
                        C += n;
                    }
                }
            }
        }
    }
    
    int i;
    printf("             ::: Flip result :::\n");  // 뒤집은 결과를 출력 
    for (i = 0; i < 8 ; i++)
    {
       switch(i)               // 8개 방향별로 몇개를 뒤집었는지 출력 
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
    	printf("%d  ", flip_count[i]);
   }
   printf("\n");
   
   switch(do_Flip)          // Black(or White) has flipped (뒤집은 개수) othellos! 를 출력  
   {
      case 'B':
         printf("Black ");
         break;
      case 'W':
         printf("White ");
         break;         
   }
   printf("has flipped %d othellos!\n\n\n", flip_count[0] + flip_count[1] + flip_count[2]+ flip_count[3]+ flip_count[4]+ flip_count[5]+ flip_count[6]+ flip_count[7]);

 }



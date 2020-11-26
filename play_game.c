#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

#define TRUE 1
#define FALSE 0

int now_ROW;
int now_COLUMN;
char board[ROW][COLUMN];
int directions[8] = {0,0,0,0,0,0,0,0};     // left up diagonal, up, right up diagonal, right, right down diagonal, down, left down diagonal, left 
int flip_count[8] = {0,0,0,0,0,0,0,0};    // count reversed pieces 

int valid_move(char player, int row, int column )  // check the input 
{
   int cnt = 0;
   char othello_board2[36] =            // declare one dimensional array, "othello_board2[36]"  
   { ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' ', 
      ' ', ' ', ' ', ' ', ' ', ' '};

   int i;
   int row_, column_;                    
   
   for(row_ = 0; row_ < ROW; row_++ )  // store boards of two dimensional array in one dimensional othello_board2
   {
      for ( column_ = 0; column_ < COLUMN; column_++)
      {
      
         othello_board2[cnt] = board[row_][column_];
         cnt++; 
        
      }
   } 
     
   int index = (row * 6) + column;  // store row and column in one dimensional index variable
   
    /*************************************** If player is White *********************************************/
   if ( player == 'W' )
   { 
        if ((row != 0 && column != 0) && othello_board2[index - 7] == 'B') // left up diagonal 
        {
            // store the number of pieces in the left up diagonal line
			int f_cnt_leftup = 0;
			// check if there are pieces in the left up diagonal line     
            int temp_index = index - 7;  
            
         	while(TRUE)
         	{
            	if (othello_board2[temp_index] == 'B')        // if there's an opposing pieces(BLACK) on the left up diagonal
                	f_cnt_leftup += 1;
             	else if (othello_board2[temp_index] == ' ')
	                break;
    	        else if (othello_board2[temp_index] == 'W')  // if there is a current player's piece(WHITE) on the left diagonal of the oppent's piece
        	    {
            	    directions[0] = 1;
                	flip_count[0] = f_cnt_leftup;
                	break;
            	}  
            	
            	int temp_row = temp_index / 6;        // store the row of the left diagonal positon of the piece in a variable "temp_row"
            	int temp_column = temp_index % 6;     // store the column of the left diagonal positon of the piece in a variable "temp_column"

            	if (temp_row == 0 || temp_column == 0)  
                	break;
             	else                                   // if the position of piece is not the 0th row and column, continue check
             		temp_index -= 7;
         	}     
        }
      //---------------------------------------------------------------------------
      	if ( row != 0 && othello_board2[index - 6] == 'B') // UP
       {
            int f_cnt_up = 0;
            int temp_index = index - 6;
         	while(TRUE)                                    // check the around pieces
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
      	if ((row != 0 && column != 5) && othello_board2[index - 5] == 'B') // Right up diagonal
    	{
            int f_cnt_rightup = 0;
            int temp_index = index - 5;
         	while(TRUE)                                       // check the around pieces
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
      
      	if ( column != 0 && othello_board2[index - 1] == 'B') // Left
         {
            int f_cnt_left = 0;
            int temp_index = index - 1;
        	while(TRUE)                                  // check the around pieces 
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
      	if ( column != 5 && othello_board2[index + 1] == 'B') // Right
        {
            int f_cnt_right = 0;
            int temp_index = index + 1;
         	while(TRUE)                                     // check the around pieces
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
      	if ((row != 5 && column != 0) && othello_board2[index + 5] == 'B') // left down diagonal
        {
            int f_cnt_leftdown = 0;
            int temp_index = index + 5;
	        while(TRUE)                                         // check the around pieces
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
      	if (row != 5 && othello_board2[index + 6] == 'B') // DOWN
        {
            int f_cnt_down = 0;
            int temp_index = index + 6;
	        while(TRUE)                                         // check the around pieces
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
      	if ((row != 5 && column != 5) && othello_board2[index + 7] == 'B') // Right down diagonal
        {
            int f_cnt_rightdown = 0;
            int temp_index = index + 7;
	        while(TRUE)                                       // check the around pieces
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
   
   /*************************************** If the player is Black *********************************************/
   if ( player == 'B' )
   {
      
        if ((row != 0 && column != 0) && othello_board2[index - 7] == 'W') //  left up diagonal
        {
            int f_cnt_leftup = 0;
            int temp_index = index - 7;
	        while(TRUE)                                       // check the around pieces
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
      	if (row != 0 && othello_board2[index - 6] == 'W') // UP
        {
            int f_cnt_up = 0;
            int temp_index = index - 6;
	        while(TRUE)                                      // check the around pieces 
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
      	if ((row != 0 && column != 5) && othello_board2[index - 5] == 'W') // Right up diagonal 
        {
            int f_cnt_rightup = 0;
            int temp_index = index - 5;
	        while(TRUE)                                          // check the around pieces
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
      
      	if (column != 0 && othello_board2[index - 1] == 'W') // Left
        {
            int f_cnt_left = 0;
            int temp_index = index - 1;
	        while(TRUE)                                        // check the around pieces
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
      	if (column != 5 && othello_board2[index + 1] == 'W') // Right
        {
            int f_cnt_right = 0;
            int temp_index = index + 1;
	        while(TRUE)                                         // check the around pieces
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
      	if ((row != 5 && column != 0) && othello_board2[index + 5] == 'W') // left down diagonal
        {
            int f_cnt_leftdown = 0;
            int temp_index = index + 5;
	        while(TRUE)                                        // check the around pieces
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
      	if (row != 5 && othello_board2[index + 6] == 'W') // Down
        {
            int f_cnt_down = 0;
            int temp_index = index + 6;
	        while(TRUE)                                      // check the around pieces 
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
      	if ((row != 5 && column != 5) && othello_board2[index + 7] == 'W') // right down diagonal
        {
            int f_cnt_rightdown = 0;
            int temp_index = index + 7;
	        while(TRUE)                                      // check the around pieces
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
   
   
   for (i = 0; i < 8; i++)  // check if directions[i] is 1 or 0. If it is 1, valid move or else invalid move 
   {
         if (directions[i] == 1)
    	{
            return 1;
    	}
   }
   return 0;
}



void input_value(char board[ROW][COLUMN], int counter )   // command where to place the pieces 
{
   int row;
   int column;
   
   int player= (counter %2 == 0)? 'B':'W';
   
   while (TRUE)
   {
      printf("put a new othello(such as 4 5): ");
      scanf("%d %d", &row, &column);
      
      if (board[row][column] != ' ') 
      { 
         printf("Not a valid move!(already occupied)\n"); 
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



 void flip_pieces(char board[ROW][COLUMN], int counter)      // reverse the pieces
 {
    int m,n;   
     
	char do_Flip;                  // the piece that reverse the pieces
	if (counter % 2 == 0)
	{
	 	do_Flip = 'B';
	}
	else
	{
	 	do_Flip = 'W';
	}
	
	char to_Flip;                   // the piece to be reversed
	if ( counter % 2 == 1)
	{
	 	to_Flip = 'B';
	}
	else
	{
	 	to_Flip = 'W';
	}
	 
	 
     for (m = -1; m <= 1; m++)   // check the eight directions from the piece  
     {
        for (n = -1; n <= 1; n++)
        {
            if (m == 0 && n == 0) 
                continue;
            if (now_ROW + m >=0 && now_ROW + m < ROW && now_COLUMN +n >=0 && now_COLUMN + n < COLUMN && board[now_ROW+m][now_COLUMN+n] == to_Flip)   // check if there is opponent's piece
            {
                int R = now_ROW + m;       // store the row that turning 8 directions from now_ROW in R
                int C = now_COLUMN + n;    // store the column that turning 8 directions from now_COLUMN in C
                int flag = FALSE;
                
                while (R < ROW && R >= 0 && C < COLUMN && C >= 0) 
                {
                    if (board[R][C] == do_Flip )   // if there is current player's piece 
                    {
                        flag = TRUE;
                        break;
                    }
                    else if (board[R][C] == ' ')   // if blank 
                        break;
                    R += m;
                    C += n;
                }
                
                R = now_ROW + m;
                C = now_COLUMN + n;
                if (flag)
                {
                    while (board[R][C] != do_Flip ) 
                    {
                        board[R][C] = do_Flip; 
                        R += m;
                        C += n;
                    }
                }
            }
        }
    }
    
    int i;
    printf("             ::: Flip result :::\n");  // print the result
    for (i = 0; i < 8 ; i++)
    {
       switch(i)               // print the number of pieces about directions
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
   
   switch(do_Flip)          // print "Black(or White) has flipped (num of pieces) othellos!" 
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



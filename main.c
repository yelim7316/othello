#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6
#define SIZE 6

#define TRUE 1
#define FALSE 0

int move[ROW][COLUMN] = {0};
int now_ROW;
int now_COLUMN;
char board[ROW][COLUMN];
int directions[8] = {0,0,0,0,0,0,0,0};		// 왼쪽 위 대각, 위, 오른쪽 위 대각 
int flip_count[8] = {0,0,0,0,0,0,0,0}; //뒤집은 개수 


void initial_board(char board[ROW][COLUMN])
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


void print_board(char board[ROW][COLUMN])
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

void print_status(int white, int black, int counter)
{
	char *current_player = (counter % 2 == 0)? "Black":"White";
	printf("STATUS - WHITE: %d, BLACK: %d\n", white, black);
	printf("TURN %d: %s player's turn.\n", counter, current_player);
}


int count_num(char board[ROW][COLUMN], char c)
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
// 입력하라고 명령하고 맞는 입력인지 확인하자. 

int valid_move(char board[ROW][COLUMN], int move[][SIZE], char player, int row, int column )   
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
	
	for(row_ = 0; row_ < ROW; row_++ )  // 2차원 배열의 board를 1차원의 othello_board2 변수에 저장 
	{
		for ( column_ = 0; column_ < COLUMN; column_++)
		{
		
			othello_board2[cnt] = board[row_][column_];
		//	printf("%d %c\n", cnt, othello_board2[cnt]); 
            cnt++; 
        
		}
	} 
	
/*	for ( i = 0; i < 36; i++)
   {
      if (i % 6 == 0)
      {
         printf("\n ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n|");
      }
      printf(" %c ", othello_board2[i]);
      printf("|");

   }
   printf("\n ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
*/   
   int index = (row * 6) + column;
   
   if ( player == 'W' )
   {
   	
   		if (othello_board2[index - 7] == 'B') // 왼쪽 대각선 
	   	{
	   		int f_cnt_leftup = 0;
	   		int temp_index = index - 7;
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
	    		
		    	if (temp_index == 0 || temp_index == 1 || temp_index == 2 || temp_index == 3 || temp_index == 4 || temp_index == 5
				|| temp_index == 6 || temp_index == 12 || temp_index == 18 || temp_index == 24 || temp_index == 30)
			    	break;
		    	
		    	temp_index -= 7;
			}      
       }	
	   //---------------------------------------------------------------------------
	   if (othello_board2[index - 6] == 'B') // 위 쪽 
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
	    			
		    	if (temp_index == 0 || temp_index == 1 || temp_index == 2 || temp_index == 3 || temp_index == 4 || temp_index == 5)
			    	break;
		    	
		    	temp_index -= 6;
			}      
       }	
	   
	   if (othello_board2[index - 5] == 'B') // 오른쪽 위 
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
	    			
		    	if (temp_index == 0 || temp_index == 1 || temp_index == 2 || temp_index == 3 || temp_index == 4 || temp_index == 5 ||
				    temp_index == 11 || temp_index == 17 || temp_index == 23 || temp_index == 29 || temp_index == 35 )
			    	break;
		    	
		    	temp_index -= 5;
			}      
       }	
	   
	   
	   //---------------------------------------------------------------------------
	   
	   if (othello_board2[index - 1] == 'B') // 왼쪽 
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
	    		
		    	if (temp_index == 0 || temp_index == 6 || temp_index == 12 || temp_index == 18 || temp_index == 24 || temp_index == 30)
			    	break;
		    	
		    	temp_index -= 1;
			}      
       }
	   
	   if (othello_board2[index + 1] == 'B') // 오른쪽 
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
	    			
		    	if (temp_index == 5 || temp_index == 11 || temp_index == 17 || temp_index == 23 || temp_index == 29 || temp_index == 35)
			    	break;
		    	
		    	temp_index += 1;
			}      
       }
	   
	   if (othello_board2[index + 5] == 'B') // 왼쪽 아래 
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
	    		
		    	if (temp_index == 0 || temp_index == 6 || temp_index == 12 || temp_index == 18 || temp_index == 24 || temp_index == 30 ||
				    temp_index == 31 ||temp_index == 32 ||temp_index == 33 ||temp_index == 34 ||temp_index == 35 )
			    	break;
		    	
		    	temp_index += 5;
			}      
       }
	   
	   if (othello_board2[index + 6] == 'B') // 아래 
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
	    		
		    	if ( temp_index == 30 || temp_index == 31 || temp_index == 32 || temp_index == 33 || temp_index == 34 || temp_index == 35 )
			    	break;
		    	
		    	temp_index += 6;
			}      
       }
	   
	   if (othello_board2[index + 7] == 'B') // 오른쪽 아래 
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
	    			
		    	if (temp_index == 5 || temp_index == 11 || temp_index == 17 || temp_index == 23 || temp_index == 29 || temp_index == 30 ||
				    temp_index == 31 ||temp_index == 32 ||temp_index == 33 ||temp_index == 34 ||temp_index == 35 )
			    	break;
		    	
		    	temp_index += 7;
			}      
       }	
   }
   
   if ( player == 'B' )
   {
   	
   		if (othello_board2[index - 7] == 'W') // 왼쪽 대각선 
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
	    		
		    	if (temp_index == 0 || temp_index == 1 || temp_index == 2 || temp_index == 3 || temp_index == 4 || temp_index == 5
				|| temp_index == 6 || temp_index == 12 || temp_index == 18 || temp_index == 24 || temp_index == 30)
			    	break;
		    	
		    	temp_index -= 7;
			}      
       }	
	   //---------------------------------------------------------------------------
	   if (othello_board2[index - 6] == 'W') // 위 쪽 
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
	    			
		    	if (temp_index == 0 || temp_index == 1 || temp_index == 2 || temp_index == 3 || temp_index == 4 || temp_index == 5)
			    	break;
		    	
		    	temp_index -= 6;
			}      
       }	
	   
	   if (othello_board2[index - 5] == 'W') // 오른쪽 위 
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
	    			
		    	if (temp_index == 0 || temp_index == 1 || temp_index == 2 || temp_index == 3 || temp_index == 4 || temp_index == 5 ||
				    temp_index == 11 || temp_index == 17 || temp_index == 23 || temp_index == 29 || temp_index == 35 )
			    	break;
		    	
		    	temp_index -= 5;
			}      
       }	
	   
	   
	   //---------------------------------------------------------------------------
	   
	   if (othello_board2[index - 1] == 'W') // 왼쪽 
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
	    		
		    	if (temp_index == 0 || temp_index == 6 || temp_index == 12 || temp_index == 18 || temp_index == 24 || temp_index == 30)
			    	break;
		    	
		    	temp_index -= 1;
			}      
       }
	   
	   if (othello_board2[index + 1] == 'W') // 오른쪽 
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
	    			
		    	if (temp_index == 5 || temp_index == 11 || temp_index == 17 || temp_index == 23 || temp_index == 29 || temp_index == 35)
			    	break;
		    	
		    	temp_index += 1;
			}      
       }
	   
	   if (othello_board2[index + 5] == 'W') // 왼쪽 아래 
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
	    		
		    	if (temp_index == 0 || temp_index == 6 || temp_index == 12 || temp_index == 18 || temp_index == 24 || temp_index == 30 ||
				    temp_index == 31 ||temp_index == 32 ||temp_index == 33 ||temp_index == 34 ||temp_index == 35 )
			    	break;
		    	
		    	temp_index += 5;
			}      
       }
	   
	   if (othello_board2[index + 6] == 'W') // 아래 
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
	    			
		    	if ( temp_index == 30 || temp_index == 31 || temp_index == 32 || temp_index == 33 || temp_index == 34 || temp_index == 35 )
			    	break;
		    	
		    	temp_index += 6;
			}      
       }
	   
	   if (othello_board2[index + 7] == 'W') // 오른쪽 아래 
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
	    			
		    	if (temp_index == 5 || temp_index == 11 || temp_index == 17 || temp_index == 23 || temp_index == 29 || temp_index == 30 ||
				    temp_index == 31 ||temp_index == 32 ||temp_index == 33 ||temp_index == 34 ||temp_index == 35 )
			    	break;
		    	
		    	temp_index += 7;
			}      
       }	
   }
   
   
   for (i = 0; i < 8; i++)  // directions[i]가 1인지 0인지 판단하는 반복문 
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
			
		if (valid_move(board, move , player, row, column) == 1 ) 
			break;
		else (printf("Not a valid move!\n"));
	
    }
	now_ROW= row;
    now_COLUMN= column;
    board[row][column] = (counter %2 == 0)? 'B':'W';
}



 void flip_pieces(char board[ROW][COLUMN], int counter) // Flips any of the second player's pieces that are between the first player's pieces
 {
 	int i,j;
     char border = counter % 2 == 0 ? 'B':'W';
     char to_Flip = counter % 2 == 1 ? 'B':'W';
     for ( i = -1; i <= 1; i++)
     {
        for ( j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (board[now_ROW + i][now_COLUMN + j] == to_Flip)
            {
                int flag = FALSE;
                int x = now_ROW + i;
                int y = now_COLUMN + j;
                while (x <= 7 && x >= 0 && y <= 7 && y >= 0)
                {
                    if (board[x][y] == border)
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
                    while (board[x][y] != border)
                    {
                        board[x][y] = border;
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
    			printf("W: ");
    			break;
    		case 7:
    			printf("SE: ");
    			break;
		}
    	printf("%d  ", directions[m]);
	}
	printf("\n");
	switch(border)
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



void check_result(int white, int black) 
{
	char *winner = (white > black)? "White" : "Black";
	printf("RESULT- WHITE: %d, BLACK: %d", white, black);
	printf("The winner is %s player", winner);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char board[ROW][COLUMN];
	int count_turn = 1; 
	
	int move[ROW][COLUMN] = {0};
	
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
		
		input_value(board, count_turn);
		flip_pieces(board, count_turn);
		
		
		count_turn ++;
		num_white = count_num(board, 'W');
		num_black = count_num(board, 'B');
	} while ((num_white < 17 && num_black <17 ) && (num_white<17 && num_black != 0) );
	
	
	print_board(board);
	check_result(num_white, num_black);
	return 0;
}

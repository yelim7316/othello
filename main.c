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
int directions[8] = {0,0,0,0,0,0,0,0};		// ���� �� �밢, ��, ������ �� �밢 
int flip_count[8] = {0,0,0,0,0,0,0,0}; //������ ���� 


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
// �Է��϶�� ����ϰ� �´� �Է����� Ȯ������. 

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
	
	for(row_ = 0; row_ < ROW; row_++ )  // 2���� �迭�� board�� 1������ othello_board2 ������ ���� 
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
         printf("\n �ѤѤѤѤѤѤѤѤѤѤѤ�\n|");
      }
      printf(" %c ", othello_board2[i]);
      printf("|");

   }
   printf("\n �ѤѤѤѤѤѤѤѤѤѤѤ�\n");
*/   
   int index = (row * 6) + column;
   
   if ( player == 'W' )
   {
   	
   		if (othello_board2[index - 7] == 'B') // ���� �밢�� 
	   	{
	   		int f_cnt_leftup = 0;
	   		int temp_index = index - 7;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'B') // �ֺ��� player �� ���� �ִٸ�
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
	   if (othello_board2[index - 6] == 'B') // �� �� 
	   	{
	   		int f_cnt_up = 0;
	   		int temp_index = index - 6;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'B') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index - 5] == 'B') // ������ �� 
	   	{
	   		int f_cnt_rightup = 0;
	   		int temp_index = index - 5;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'B') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index - 1] == 'B') // ���� 
	   	{
	   		int f_cnt_left = 0;
	   		int temp_index = index - 1;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'B') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index + 1] == 'B') // ������ 
	   	{
	   		int f_cnt_right = 0;
	   		int temp_index = index + 1;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'B') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index + 5] == 'B') // ���� �Ʒ� 
	   	{
	   		int f_cnt_leftdown = 0;
	   		int temp_index = index + 5;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'B') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index + 6] == 'B') // �Ʒ� 
	   	{
	   		int f_cnt_down = 0;
	   		int temp_index = index + 6;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'B') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index + 7] == 'B') // ������ �Ʒ� 
	   	{
	   		int f_cnt_rightdown = 0;
	   		int temp_index = index + 7;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'B') // �ֺ��� player �� ���� �ִٸ�
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
   	
   		if (othello_board2[index - 7] == 'W') // ���� �밢�� 
	   	{
	   		int f_cnt_leftup = 0;
	   		int temp_index = index - 7;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'W') // �ֺ��� player �� ���� �ִٸ�
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
	   if (othello_board2[index - 6] == 'W') // �� �� 
	   	{
	   		int f_cnt_up = 0;
	   		int temp_index = index - 6;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'W') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index - 5] == 'W') // ������ �� 
	   	{
	   		int f_cnt_rightup = 0;
	   		int temp_index = index - 5;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'W') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index - 1] == 'W') // ���� 
	   	{
	   		int f_cnt_left = 0;
	   		int temp_index = index - 1;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'W') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index + 1] == 'W') // ������ 
	   	{
	   		int f_cnt_right = 0;
	   		int temp_index = index + 1;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'W') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index + 5] == 'W') // ���� �Ʒ� 
	   	{
	   		int f_cnt_leftdown = 0;
	   		int temp_index = index + 5;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'W') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index + 6] == 'W') // �Ʒ� 
	   	{
	   		int f_cnt_down = 0;
	   		int temp_index = index + 6;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'W') // �ֺ��� player �� ���� �ִٸ�
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
	   
	   if (othello_board2[index + 7] == 'W') // ������ �Ʒ� 
	   	{
	   		int f_cnt_rightdown = 0;
	   		int temp_index = index + 7;
			while(TRUE)
			{
				if (othello_board2[temp_index] == 'W') // �ֺ��� player �� ���� �ִٸ�
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
   
   
   for (i = 0; i < 8; i++)  // directions[i]�� 1���� 0���� �Ǵ��ϴ� �ݺ��� 
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
		
		if (board[row][column] != ' ')  // �̹� ���� ������ �ִ� ���� ��  
		{ 
			printf("Not a valid move!(already occupied)\n"); // ���� ���� ������ ��� 
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
    printf("             ::: Flip result :::\n");  // ������ ����� ��� 
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
    // directions[i]�� 1�� ���̵�� �� ���̵��� ���ؼ� ��� ���������� (flip_count[i]) 
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
	
	initial_board(board); // �����ʱ�ȭ 

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
		
	    print_board(board);   // ������ ��� 
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

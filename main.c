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
int directions[8] = {0,0,0,0,0,0,0,0};
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
	
	for(row_ = 0; row_ < ROW; row_++ )
	{
		for ( column_ = 0; column_ < COLUMN; column_++)
		{
		
			othello_board2[cnt] = board[row_][column_];
			printf("%d %c\n", cnt, othello_board2[cnt]); 
            cnt++; 
        
		}
	} 
	
	for ( i = 0; i < 36; i++)
   {
      if (i % 6 == 0)
      {
         printf("\n ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n|");
      }
      printf(" %c ", othello_board2[i]);
      printf("|");

   }
   printf("\n ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
   
   int index = (row * 6) + column;
   
   if ( player == 'W' )
   {
   	if (othello_board2[index - 9] == 'B')
	   {
	   	int temp_index = index - 9;
	   	if (temp_index == 0 || temp_index == 1 || temp_index == 2 || temp_index == 3 || temp_index == 4 || temp_index == 5
		   || temp_index == 6 || temp_index == 12 || temp_index == 18 || temp_index == 24 || temp_index == 30)
	   	for (i = )
	   }
   		directions[0] = 1;
   }
   
   [index + ]

	
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
		
		
		if (valid_move(board, move , player, row, column) == 0 )
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
		directions[8] = {0,0,0,0,0,0,0,0};
		flip_count[8] = {0,0,0,0,0,0,0,0};
		
	    print_board(board);   // 보드판 출력 
		print_status(num_white, num_black, count_turn );
		
		input_value(board, count_turn);
		flip_pieces(board, count_turn);
		
		
		count_turn ++;
		num_white = count_num(board, 'W');
		num_black = count_num(board, 'B');
	} while ((num_white < 17 && num_black <17 ) && (num_white<17 && num_black != 0)  );
	
	
	print_board(board);
	check_result(num_white, num_black);
	return 0;
}

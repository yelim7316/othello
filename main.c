#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

#define TRUE 1
#define FALSE 0

char board[ROW][COLUMN];
extern directions[8];      // ���� �� �밢, ��, ������ �� �밢 
extern flip_count[8];   //������ ���� 

void initial_board(char board[ROW][COLUMN]); // ������ �ʱ�ȭ 
void print_board(char board[ROW][COLUMN]);   // ������ ��� 

void print_status(int white, int black, int counter);   // ���� ���� ��Ÿ���� 

int count_num(char board[ROW][COLUMN], char c);  // �� ���� ���� 


int valid_move(char player, int row, int column );  // �ùٸ� �Է����� Ȯ��   

void input_value(char board[ROW][COLUMN], int counter );

void flip_pieces(char board[ROW][COLUMN], int counter); // �� ������ 

void check_result(int white, int black);   // ��� ��� 


int is_game_end (char _player);   // ������ �������� Ȯ�� 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   
   int count_turn = 1; 
   int game_ing = 1;

	//check_board(board);
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
			printf("���� ��\n");
		 	game_ing = 0;		 
		}
		else if (is_game_end(temp_player) == 1)
       		printf("PASS");
        else
		{
			for(q = 0; q < 8; q++)   //directions, flip_count �ʱ�ȭ
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

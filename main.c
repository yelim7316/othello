#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

#define TRUE 1
#define FALSE 0

char board[ROW][COLUMN];   // ������  
extern directions[8];      // ���� �� �밢, ��, ������ �� �밢, ������, ������ �Ʒ� �밢, �Ʒ�, ���� �Ʒ� �밢, ���� - 8�� ������ �迭�� ���� 
extern flip_count[8];      //������ ���� 

extern void initial_board(char board[ROW][COLUMN]); // ������ �ʱ�ȭ 

extern void print_board(char board[ROW][COLUMN]);   // ������ ��� 

extern void print_status(int white, int black, int counter);   // ���� ���� ��Ÿ���� �Լ� 

extern int count_num(char board[ROW][COLUMN], char c);  // �� ������ ���� �Լ�  

extern int valid_move(char player, int row, int column );  // �ùٸ� �Է����� Ȯ���ϴ� �Լ�   

extern void input_value(char board[ROW][COLUMN], int counter ); // ���� ���� ��ġ �Է��϶�� ����ϴ� �Լ� 

extern void flip_pieces(char board[ROW][COLUMN], int counter); // ���� ������ �Լ� 

extern void check_result(int white, int black);  // ����� ����ϴ� �Լ� 

extern int is_game_end (char _player);   // ������ �������� Ȯ���ϴ� �Լ� 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   
   int count_turn = 1;         // ������ turn�� ���� ���� 
   int game_ing = 1;           // ������ ��� ����ǰ� ������ ��Ÿ���� ������ 1�̸� ���� ����, 0�̸� ���� ���� ��Ÿ�� 

	initial_board(board);      // ������ �ʱ�ȭ 

   int num_white = count_num(board, 'W');    // ���忡 �ִ� white �� ������ ���� num_white ������ ���� 
   int num_black = count_num(board, 'B');    // ���忡 �ִ� black �� ������ ���� num_black ������ ���� 
      
      
   do 
   {
      // directions[8] = int{0,0,0,0,0,0,0,0}; �ʱ�ȭ 
      // flip_count[8] = int{0,0,0,0,0,0,0,0}; �ʱ�ȭ 
      int q;
      for(q = 0; q < 8; q++)
      {
         directions[q] = 0;
         flip_count[q] = 0;
      }
      
    	print_board(board);                                  // ������ ��� 
    	print_status(num_white, num_black, count_turn );    // ���� ���� ��� 
      
      char temp_player;            // ���� player ���� - count_turn�� 2�� ���������� �������� 0�̸� black player �̰� 1�̸� white player �� ���� 
      switch(count_turn % 2)  
      {
         case 0:
            temp_player = 'B';
            break;
         case 1:
            temp_player = 'W';
            break;
      }
   
    	if ( is_game_end('B') == 1 && is_game_end('W') == 1)   // ������ ������ �������� Ȯ�� - �� player�� ���ؼ� ��� is_game_end �Լ��� 1�̸� ���� ����  
		{
			printf("���� ��\n");
		 	game_ing = 0;		 
		}
		else if (is_game_end(temp_player) == 1)             // �� player �� �� ���� player �� ���� ���� �� ������ �� turn�� pass 
       		printf("PASS");
        else
		{
			for(q = 0; q < 8; q++)   //directions, flip_count �ʱ�ȭ
      		{
         		directions[q] = 0;
         		flip_count[q] = 0;
          	}
	   		input_value(board, count_turn);         // ���� �Է� �޴´�. 
       		flip_pieces(board, count_turn);         // ������ �Լ��� ���� ���� �����´�.  
    	}
       
      	count_turn ++;                              // ���� turn 1 ���� 
      	num_white = count_num(board, 'W');          // white �� ������ ���� num_white�� ���� 
      	num_black = count_num(board, 'B');          // black �� ������ ���� num_black�� ���� 
   } while (game_ing);
   
   
   print_board(board);                       // ������ ��� 
   check_result(num_white, num_black);       // ��� ��� 
   
   
   return 0;
}

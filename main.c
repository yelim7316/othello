#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

#define TRUE 1
#define FALSE 0

char board[ROW][COLUMN];   // 보드판  
extern directions[8];      // 왼쪽 위 대각, 위, 오른쪽 위 대각, 오른쪽, 오른쪽 아래 대각, 아래, 왼쪽 아래 대각, 왼쪽 - 8개 방향을 배열로 정의 
extern flip_count[8];      //뒤집은 개수 

extern void initial_board(char board[ROW][COLUMN]); // 보드판 초기화 

extern void print_board(char board[ROW][COLUMN]);   // 보드판 출력 

extern void print_status(int white, int black, int counter);   // 현재 상태 나타내는 함수 

extern int count_num(char board[ROW][COLUMN], char c);  // 알 개수를 세는 함수  

extern int valid_move(char player, int row, int column );  // 올바른 입력인지 확인하는 함수   

extern void input_value(char board[ROW][COLUMN], int counter ); // 알을 놓을 위치 입력하라고 명령하는 함수 

extern void flip_pieces(char board[ROW][COLUMN], int counter); // 알을 뒤집는 함수 

extern void check_result(int white, int black);  // 결과를 출력하는 함수 

extern int is_game_end (char _player);   // 게임이 끝났는지 확인하는 함수 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   
   int count_turn = 1;         // 게임의 turn을 세는 변수 
   int game_ing = 1;           // 게임이 계속 진행되고 있음을 나타내는 변수로 1이면 게임 진행, 0이면 게임 끝을 나타냄 

	initial_board(board);      // 보드판 초기화 

   int num_white = count_num(board, 'W');    // 보드에 있는 white 알 개수를 세서 num_white 변수에 저장 
   int num_black = count_num(board, 'B');    // 보드에 있는 black 알 개수를 세서 num_black 변수에 저장 
      
      
   do 
   {
      // directions[8] = int{0,0,0,0,0,0,0,0}; 초기화 
      // flip_count[8] = int{0,0,0,0,0,0,0,0}; 초기화 
      int q;
      for(q = 0; q < 8; q++)
      {
         directions[q] = 0;
         flip_count[q] = 0;
      }
      
    	print_board(board);                                  // 보드판 출력 
    	print_status(num_white, num_black, count_turn );    // 현재 상태 출력 
      
      char temp_player;            // 현재 player 설정 - count_turn을 2로 나누었을때 나머지가 0이면 black player 이고 1이면 white player 로 설정 
      switch(count_turn % 2)  
      {
         case 0:
            temp_player = 'B';
            break;
         case 1:
            temp_player = 'W';
            break;
      }
   
    	if ( is_game_end('B') == 1 && is_game_end('W') == 1)   // 게임이 끝나는 조건인지 확인 - 두 player에 대해서 모두 is_game_end 함수가 1이면 게임 종료  
		{
			printf("게임 끝\n");
		 	game_ing = 0;		 
		}
		else if (is_game_end(temp_player) == 1)             // 두 player 중 한 명의 player 가 알을 놓을 수 없으면 그 turn은 pass 
       		printf("PASS");
        else
		{
			for(q = 0; q < 8; q++)   //directions, flip_count 초기화
      		{
         		directions[q] = 0;
         		flip_count[q] = 0;
          	}
	   		input_value(board, count_turn);         // 값을 입력 받는다. 
       		flip_pieces(board, count_turn);         // 뒤집기 함수를 통해 알을 뒤집는다.  
    	}
       
      	count_turn ++;                              // 게임 turn 1 증가 
      	num_white = count_num(board, 'W');          // white 알 개수를 세서 num_white에 저장 
      	num_black = count_num(board, 'B');          // black 알 개수를 세서 num_black에 저장 
   } while (game_ing);
   
   
   print_board(board);                       // 보드판 출력 
   check_result(num_white, num_black);       // 결과 출력 
   
   
   return 0;
}

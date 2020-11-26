#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COLUMN 6

#define TRUE 1
#define FALSE 0

char board[ROW][COLUMN];       
extern int directions[8];      // left up diagonal, up, right up diagonal, right, right down diagonal, down, left down diagonal, left  
extern int flip_count[8];      // count reversed pieces 

void initial_board(char board[ROW][COLUMN]); // inital board

void print_board(char board[ROW][COLUMN]);   // print board

void print_status(int white, int black, int counter);   // print current status 

int count_num(char board[ROW][COLUMN], char c);  // count pieces

int valid_move(char player, int row, int column );  // check that the input is correct   

void input_value(char board[ROW][COLUMN], int counter ); // command where to place the pieces

void flip_pieces(char board[ROW][COLUMN], int counter); // reverse pieces

void check_result(int white, int black);  // print the result

int is_game_end (char _player);   // check the game is over


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   
	int count_turn = 1;         // count game's turn 
	int game_ing = 1;           // indicates that the game is still in progress. 1 indicates game progress, 0 indicated game end  

	initial_board(board);      // inital board

	int num_white = count_num(board, 'W');    // count the number of white pieces and store them in num_white
	int num_black = count_num(board, 'B');    // count the number of black pieces and store them in num_black
      
      
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
      
    	print_board(board);                                  // print board
    	print_status(num_white, num_black, count_turn );    // print current status 
      
      char temp_player;            // set current player  
      switch(count_turn % 2)  
      {
         case 0:
            temp_player = 'B';
            break;
         case 1:
            temp_player = 'W';
            break;
      }
   
    	if ( is_game_end('B') == 1 && is_game_end('W') == 1)   // check that the game is ended. if is_game_end function about two players return 1, the game is over
		{
			printf("The game is over! \n");
		 	game_ing = 0;		 
		}
		else if (is_game_end(temp_player) == 1)             // if one of players can't put pieces, the game will pass 
       		printf("PASS");
        else
		{
			for(q = 0; q < 8; q++)   //directions, flip_count initialize
      		{
         		directions[q] = 0;
         		flip_count[q] = 0;
          	}
	   		input_value(board, count_turn);         // command the input
       		flip_pieces(board, count_turn);         // reverse pieces  
    	}
       
      	count_turn ++;                               
      	num_white = count_num(board, 'W');          // count white pieces
      	num_black = count_num(board, 'B');          // count black pieces 
	} while (game_ing);
   
   
   print_board(board);                       // print board
   check_result(num_white, num_black);       // print the result
   
   
   return 0;
}

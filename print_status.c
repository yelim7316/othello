#include <stdio.h>
#include <stdlib.h>

void print_status(int white, int black, int counter)   // 현재 상태 나타내는 함수 
{
   char *current_player = (counter % 2 == 0)? "Black":"White";      // 현재 player 선언 
   printf("STATUS - WHITE: %d, BLACK: %d\n", white, black);         // White, Black 알 개수 출력 
   printf("%d TURN: %s player's turn.\n", counter, current_player);  // 몇번째 TURN인지, 현재 player 알의 색 출력 
}


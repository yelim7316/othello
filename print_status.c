#include <stdio.h>
#include <stdlib.h>

void print_status(int white, int black, int counter)   // 현재 상태 나타내기 
{
   char *current_player = (counter % 2 == 0)? "Black":"White";
   printf("STATUS - WHITE: %d, BLACK: %d\n", white, black);
   printf("%d TURN: %s player's turn.\n", counter, current_player);
}


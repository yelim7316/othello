#include <stdio.h>
#include <stdlib.h>

void print_status(int white, int black, int counter)   // ���� ���� ��Ÿ���� �Լ� 
{
   char *current_player = (counter % 2 == 0)? "Black":"White";      // ���� player ���� 
   printf("STATUS - WHITE: %d, BLACK: %d\n", white, black);         // White, Black �� ���� ��� 
   printf("%d TURN: %s player's turn.\n", counter, current_player);  // ���° TURN����, ���� player ���� �� ��� 
}


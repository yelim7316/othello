#include <stdio.h>
#include <stdlib.h>

void print_status(int white, int black, int counter)   // print the current status
{
   char *current_player = (counter % 2 == 0)? "Black":"White";        // current player
   printf("STATUS - WHITE: %d, BLACK: %d\n", white, black);           // print the number of White and Black pieces
   printf("%d TURN: %s player's turn.\n", counter, current_player);   // print game's turn and current player
}


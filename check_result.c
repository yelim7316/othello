#include <stdio.h>
#include <stdlib.h>

void check_result(int white, int black)   // ��� ��� 
{
   char *winner = (white > black)? "White" : "Black";
   printf("RESULT- WHITE: %d, BLACK: %d", white, black);
   printf("\nThe winner is %s player", winner);
}

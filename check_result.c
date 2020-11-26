#include <stdio.h>
#include <stdlib.h>

void check_result(int white, int black)                    // print the result
{
   char *winner = (white > black)? "White" : "Black";     // compare the number of pieces 
   printf("RESULT- WHITE: %d, BLACK: %d", white, black);  // print the number of white, black pieces
   printf("\nThe winner is %s player", winner);           
}

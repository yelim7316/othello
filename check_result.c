#include <stdio.h>
#include <stdlib.h>

void check_result(int white, int black)                    // 결과를 출력하는 함수 
{
   char *winner = (white > black)? "White" : "Black";     // 최종 승자를 저장할 변수 선언 & 알의 개수를 비교해서 알의 개수가 더 많은 player를 winner에 저장 
   printf("RESULT- WHITE: %d, BLACK: %d", white, black);  // white, black 알의 개수를 세서 출력한다. 
   printf("\nThe winner is %s player", winner);           // 최종 승자 출력 
}

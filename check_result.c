#include <stdio.h>
#include <stdlib.h>

void check_result(int white, int black)                    // ����� ����ϴ� �Լ� 
{
   char *winner = (white > black)? "White" : "Black";     // ���� ���ڸ� ������ ���� ���� & ���� ������ ���ؼ� ���� ������ �� ���� player�� winner�� ���� 
   printf("RESULT- WHITE: %d, BLACK: %d", white, black);  // white, black ���� ������ ���� ����Ѵ�. 
   printf("\nThe winner is %s player", winner);           // ���� ���� ��� 
}

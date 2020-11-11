#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define BLACK 1
#define EMPTY 2

#define WHITE_MARK " X "
#define BLACK_MARK " O "
#define EMPTY_MARK "  "


const char *row_names = "012345";
const char *column_names = "012345";

const char board [6][6] = {0};

void print_board()
{
	
	int i, j;
	printf("  %d %d %d %d %d %d\n",0, 1, 2, 3, 4, 5, 6);
	
	for(i=0; i<6; i++)
	{
		printf(" -------------\n");
		printf("%c|", row_names[i]);
		for (j=0; j<6; j++)
		{
			if (board[i][j] == WHITE)
			{
				printf("%s",WHITE_MARK);
			} 
			else if(board[i][j] == BLACK)
			{
			   printf("%s",BLACK_MARK);	
			}
			else
			{
				printf("%s",EMPTY_MARK);
			}
			printf("|");
		}
		printf("\n");
		
	}
	printf("\n");
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	print_board();
	
	
	return 0;
}

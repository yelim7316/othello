#include <stdio.h>
#include <stdlib.h>

#define WHITE  0
#define BLACK 1


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char board [][] = {0};
	
	init_othello(); // 게임 초기화 
	
	while (isGameEnd()==0)
	{
		print_othello();
	}
	return 0;
}

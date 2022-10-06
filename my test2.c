#include "my game2.h"
void menu()
{
	printf("###############################\n");
	printf("##########  1.play  ###########\n");
	printf("##########  0.exit  ###########\n");
	printf("###############################\n");
}
void game()
{
	char board[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	inittable(board , ROWS , COLS , '0');
	inittable(show , ROWS , COLS , '#');
	
	creatbooms(board, ROW, COL);

	displaytable(show, ROW, COL);
	//displaytable(board, ROW, COL);
	
	emptytable(board,show, ROWS, COLS);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;	
	do
	{	
		menu();
		printf("please input to begin\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exited");
			break;
		default:
			printf("please chose again\n");
			break;
		}
	} while(input);

	return 0;
}
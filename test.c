#include "game.h"
void menu()
{
	printf("###################################\n");
	printf("#############  1.play  ############\n");
	printf("#############  0.exit  ############\n");
	printf("###################################\n");
}
void game()
{
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
	    ret = IsWin(board , ROW , COL);
		if (ret != 'C')
		{
			break;
		}

		ComputerMove(board, ROW , COL);
		DisplayBoard(board, ROW , COL);
        ret = IsWin(board , ROW , COL);
		if (ret != 'C')
		{
			break;
		}		
	}
	if (ret == '*')
	{
		printf("player WIN\n");		
	}
	else if (ret == '#')
	{
		printf("computer WIN\n");	
	}
	else
	{
		printf("equal\n");		
	}
	DisplayBoard(board, ROW, COL);
}
int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("please chose\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit\n");
			break;
		default:
			printf("chose agin\n");
			break;
		}
	} while (input);
	return 0;
}
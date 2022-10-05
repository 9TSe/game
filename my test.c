#include "game.h"
#include "game.c"
void menu()
{
	printf("###############################\n");
	printf("########## 1. play  ###########\n");
	printf("########## 0. end   ###########\n");
	printf("###############################\n");
}
void game()
{
	char table[hang][lie];         //��������
	initaltable(table, hang, lie); //��ʼ������
	printftable(table, hang, lie); //��ӡ����
	char ret = 0;
	while (1)
	{
		playermove(table, hang, lie);
		printftable(table, hang, lie);
		ret = IsWin(table, hang, lie); //���Ӯ����*  ,  ����Ӯ����#  ,ƽ�ַ���P  ,  �������� J	
		if (ret == 'P')
		{
			printf("equal!!!\n");
			break;
		}
		if (ret == '*')
		{
			printf("player win\n");
			break;
		}
		if (ret == '#')
		{
			printf("computer win\n");
			break;
		}


		computermove(table, hang, lie);
		printftable(table, hang, lie);
		ret = IsWin(table, hang, lie);


		if (ret == 'P')
		{
			printf("equal!!!\n");
			break;
		}
		if (ret == '*')
		{
			printf("player win\n");
			break;
		}
		if (ret == '#')
		{
			printf("computer win\n");
			break;
		}

	}
}
int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("chose one to play\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("end\n");
			break;
		default :
			printf("again\n");
			break;
		}

	} while (input);
	return 0;
}

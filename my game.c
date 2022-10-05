#include "my game.h"
void initaltable(char table[hang][lie], int Hang, int Lie)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Hang; i++)
	{
		for (j = 0; j < Lie; j++)
		{
			table[i][j] = ' ';
		}
	}
}
void printftable(char table[hang][lie],int Hang, int Lie)
{
	int i = 0;
	for (i = 0; i < Hang; i++)
	{
		for (int j = 0; j < Lie; j++)
		{
			printf(" %c ",table[i][j]);
			if (j < Lie - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < Hang - 1)
		{
			int j = 0;
			for (j = 0; j < Lie; j++)
			{
				printf("---");
				if (j < Lie - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void playermove(char table[hang][lie], int Hang, int Lie)
{
	int x = 0;
	int y = 0;
	printf("please input location\n");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= Hang && y >= 1 && y <= Lie)
		{
			if (table[y - 1][x - 1] == ' ')
			{
				table[y - 1][x - 1] = '*';
				break;
			}
			else
			{
				printf("occupied,please input again.\n");
			}
		}
		else
		{
			printf("beyond, please input again\n");
		}
	}

	
}

void computermove(char table[hang][lie], int Hang, int Lie)
{
	printf("the time of computer\n");
	
	while (1)
	{
		int x = rand() % Lie;
		int y = rand() % Hang;
		if (table[x][y] == ' ')
		{
			table[x][y] = '#';
			break;
		}
	}
}
int Fulltable(char table[hang][lie], int Hang, int Lie)
{
	int i = 0;
	for (i = 0; i < Lie; i++)
	{
		for (int j = 0; j < Hang; j++)
		{
			if (table[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char table[hang][lie], int Hang, int Lie)
{
	int i = 0;
	for (i = 0; i < Hang; i++)
	{
		if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][1] != ' ')
		{
			return table[i][1];
		}
	}
	
	for (i = 0; i < Lie; i++)
	{
		if (table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[1][i] != ' ')
		{
			return table[1][i];
		}
	}

	if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[1][1] != ' ')
	{
		return table[1][1];
	}

	if (table[2][0] == table[1][1] && table[1][1] == table[0][2] && table[1][1] != ' ')
	{
		return table[1][1];
	}

	if (Fulltable(table, Hang, Lie) == 1)
	{
		return 'P';
	}
}

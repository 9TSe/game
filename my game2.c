#include "my game2.h"
void inittable(char table[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < cols; i++)
	{
		for (j = 0; j < rows; j++)
		{
			table[i][j] = set;
		}
	}
}

void displaytable(char table[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int h = 1;
	int l = 0;
	for (l = 0; l <= row; l++)
	{
		printf("%d  ", l);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d  ", h);
		h++;
		for (j = 1; j <= col; j++)
		{
			printf("%c  ", table[i][j]);
		}
		printf("\n");
	}
}

void creatbooms(char table[ROWS][COLS], int row, int col)
{
	int count = 0;
	while (count < booms)
	{
		int x = rand() % col + 1;
		int y = rand() % row + 1;
		if (table[x][y] == '0')
		{
			table[x][y] = '1';
			count++;
		}
	}
}

int message(char table[ROWS][COLS] ,int x,int y)
{
	return table[y + 1][x + 1] +
		table[y + 1][x] +
		table[y + 1][x - 1] +
		table[y][x + 1] +
		table[y][x] +
		table[y][x - 1] +
		table[y - 1][x - 1] +
		table[y - 1][x] +
		table[y - 1][x + 1] - 8 * '0';
}

int Win(char table[ROWS][COLS],int count)
{
	if (count == ROW * COL - booms)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void emptytable(char table[ROWS][COLS],char show[ROWS][COLS] ,  int row, int col)
{
	int x = 0;
	int y = 0;	
	int count = 0;
	while (1)
	{	
		printf("please input location\n");
		scanf("%d%d", &x, &y);
		if (table[y][x] == '0')
		{
			show[y][x] = message(table, x, y);
			table[y][x] = '2';
			displaytable(show, ROW, COL);
			count++;
			if (Win(show , count) == 1)
			{
				printf("congratulate wininggg !!!\n");
				break;
			}
		}
		else if(table[y][x] == '1')
		{
			printf("waste!!\n");
			break;
		}
		else if (table[y][x] == '2')
		{
			printf("occupied,please input agin");
		}
		else
		{
			printf("beyond location please input again");
		}
	}
}
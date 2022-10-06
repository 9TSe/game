#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define booms 1

void inittable(char table[ROWS][COLS], int rows, int cols, char set);

void displaytable(char table[ROWS][COLS], int row, int col);

void creatbooms(char table[ROWS][COLS], int row, int col);

void emptytable(char table[ROWS][COLS],char show[ROWS][COLS], int row, int col);
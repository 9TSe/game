#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define hang 3
#define lie 3
#include<time.h>
#include<stdlib.h>


void  printftable(char table[hang][lie], int Hang, int Lie);

void playermove(char table[hang][lie], int Hang, int Lie);

void computermove(char table[hang][lie], int Hang, int Lie);

char IsWin(char table[hang][lie], int Hang, int Lie);
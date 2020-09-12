#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//这种写法不是很好,如果到时候要改变棋盘大小的话会很麻烦
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//打印数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//        //打印分割行
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
				
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走\n");
	printf("请输入坐标:>");
	while (1)
	{
		scanf("%d%d", &x, &y);
		//要判断玩家输入坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//用户填坐标的时候在左上角会填1，1 所以在数组上用x-1 y-1来迎合用户
			if (board[x - 1][y - 1] == ' ')

			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入:>");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	//最简单难度，电脑在有空格的地方随机走，后期可优化
	printf("电脑走\n");
	//用时间戳让电脑随机走
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
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
//����д�����Ǻܺ�,�����ʱ��Ҫ�ı����̴�С�Ļ�����鷳
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//��ӡ����
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//        //��ӡ�ָ���
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
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
	printf("�����\n");
	printf("����������:>");
	while (1)
	{
		scanf("%d%d", &x, &y);
		//Ҫ�ж������������ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�û��������ʱ�������Ͻǻ���1��1 ��������������x-1 y-1��ӭ���û�
			if (board[x - 1][y - 1] == ' ')

			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������:>");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	//����Ѷȣ��������пո�ĵط�����ߣ����ڿ��Ż�
	printf("������\n");
	//��ʱ����õ��������
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
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void menu()
{
	printf("*************************************\n");
	printf("*************    1.play    **********\n");
	printf("*************    0.exit    **********\n");
	printf("*************************************\n");
}
void game()
{
	//设计三子棋游戏
	//3*3的棋盘的数据存储用一个二维数组3*3
	char board[ROW][COL] = { 0 };//存储数据的，这个数组应该初始化为空格，这样刚开始的时候棋盘上就什么都没有
	InitBoard(board,ROW,COL);//初始化棋盘，初始化成空格
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//分析以下发现：
	//在游戏游玩的过程中
	//1.玩家赢了 2.电脑赢了 3.平局 4.游戏还没结束
	while (1)
	{
		//玩家走
		PlayerMove(board, ROW, COL);
		//分析输赢
		DisplayBoard(board, ROW, COL);

		ComputerMove(board, ROW, COL);
		//分析输赢
		DisplayBoard(board, ROW, COL);
		
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//用时间戳让电脑随机走
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
		return 0;
}
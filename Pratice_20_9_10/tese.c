#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("****************************");
	printf("****************************");
	printf("****************************");
	printf("****************************");
}
void game()
{
	//真正扫雷的过程
	//创建两个数组

	//存放布置好的雷
	char mine[ROWS][COLS] = { 0 };//放'0'
	//存放排查出来的雷的信息
	char show[ROWS][COLS] = { 0 };//放'*'
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	DisplayBoard(show, ROW, COL);
	//布置好的雷的信息不能轻易打印
	//1.布置雷
	Setmine(mine, ROW, COL);
	//2.扫雷
	FindMine(mine,show,ROW,COL);
}
int main()
{
	
	int input = 0;
	//time_t  整形
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("选择错误!\n");
			break;
		}
	} while (input);
	return 0;
}
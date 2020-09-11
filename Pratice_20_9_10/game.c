#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------------------------------\n");
	//列号的打印
	for (i = 0; i <= col; i++)
	{
		//行号的打印
		printf("%d", i);
	}
	for (i = 1; i <= row; i++)
	{
		printf("%d", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	//1.随机找坐标布置雷
	//布置多少个 10
	int count = 10;
	while (count)
	{
		//布置成功一个雷,count--
		//1.生产随机的坐标
		int x = rand()%row+1;//生成1—9
		int y = rand()%col+1;//1-9
		//2.布置
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
GetMineCount(char mine[ROWS][COLS],int x,int y)
{
	mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<ROW*COL-10)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			//判断x,y坐标处是否是雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				break;
			}
			else
			{
				//如果x,y坐标不是雷，则统计周围有几个雷
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标不合法\n");
		}
	}
	if (win == ROW*COL - 10)
	{
		printf("排雷成功\n");
	}
}
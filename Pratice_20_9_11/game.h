#define _CRT_SECURE_NO_WARNINGS 1
//如果头文件包含了#include<stdio.h>,那后面两个文件引game.h的时候也会引到stdio
#define ROW 3
#define COL 3
#include<stdio.h>
#include<time.h>

//声明函数
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
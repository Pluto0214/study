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
	//�����������Ϸ
	//3*3�����̵����ݴ洢��һ����ά����3*3
	char board[ROW][COL] = { 0 };//�洢���ݵģ��������Ӧ�ó�ʼ��Ϊ�ո������տ�ʼ��ʱ�������Ͼ�ʲô��û��
	InitBoard(board,ROW,COL);//��ʼ�����̣���ʼ���ɿո�
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//�������·��֣�
	//����Ϸ����Ĺ�����
	//1.���Ӯ�� 2.����Ӯ�� 3.ƽ�� 4.��Ϸ��û����
	while (1)
	{
		//�����
		PlayerMove(board, ROW, COL);
		//������Ӯ
		DisplayBoard(board, ROW, COL);

		ComputerMove(board, ROW, COL);
		//������Ӯ
		DisplayBoard(board, ROW, COL);
		
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//��ʱ����õ��������
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
		return 0;
}
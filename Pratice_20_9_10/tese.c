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
	//����ɨ�׵Ĺ���
	//������������

	//��Ų��úõ���
	char mine[ROWS][COLS] = { 0 };//��'0'
	//����Ų�������׵���Ϣ
	char show[ROWS][COLS] = { 0 };//��'*'
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	DisplayBoard(show, ROW, COL);
	//���úõ��׵���Ϣ�������״�ӡ
	//1.������
	Setmine(mine, ROW, COL);
	//2.ɨ��
	FindMine(mine,show,ROW,COL);
}
int main()
{
	
	int input = 0;
	//time_t  ����
	srand((unsigned int)time(NULL));//������������������
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
		default:
			printf("ѡ�����!\n");
			break;
		}
	} while (input);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1-100�м���9
//˼·���������10��������ʮλ������10���µ����������ĸ�λ��
int main()
{
	int i = 0;
	int a = 0;//aΪ9�ĸ���
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			a = a + 1;
		}
		if (i / 10 == 9)
		{
			a = a + 1;
		}
	}
	printf("%d\n", a);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1-100有几个9
//思路：这个数除10就是他的十位数，除10余下的数就是他的个位数
int main()
{
	int i = 0;
	int a = 0;//a为9的个数
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
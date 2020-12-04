#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int * p = (int *)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		perror("malloc");
		return 0;
	}
	//使用
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}
	//调整大小
	int * ptr = (int *)realloc(p, 20 * sizeof(int));
	if (ptr == NULL)
	{
		perror("realloc");
	}
	else
	{
		p = ptr;
	}
	for (i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}
	//打印出来看一看
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}
	//用完之后不想要这块空间了，free掉
	free(p);
	p = NULL;
	return 0;
}


void test()
{
	int* p = (int*)malloc(12);
	if (p == NULL)
	{
		return;
	}
	//使用空间
	if (1)
		return;

	free(p);
	p = NULL;
}
int main()
{
	test();
	return 0
}
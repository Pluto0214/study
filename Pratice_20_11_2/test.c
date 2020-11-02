#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void test()
{
	int* p = (int*)malloc(12);
	if (p == NULL)
	{
		return;
	}
	// π”√ø’º‰
	if (1)
		return;

	free(p);
	p = NULL;
}
int main()
{
	test();
	return;
}

void GetMemory(char ** p)
{
	*p = (char *)malloc(100);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
	free(str);
	str = NULL;
}


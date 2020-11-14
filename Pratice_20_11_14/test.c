#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
void Test(void)
{
	char * str = (char *)malloc(100);
	strcpy(str, "hello");
	free(str);
	str = NULL;
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();
	return 0;
}

//void GetMemory(char ** p, int num)
//{
//	*p = (char *)malloc(num);
//}
//void Test(void)
//{
//	char * str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int mian()
//{
//	Test();
//	return 0;
//}

//char * GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char * str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

// char * GetMemory(char * p)
//{
//	p = (char *)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char * str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//int main()
//{
//	int * p = (int *)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 0;
//	}
//	//使用
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		p[i] = i + 1;
//	}
//	//调整大小
//	int * ptr = (int *)realloc(p, 20 * sizeof(int));
//	if (ptr == NULL)
//	{
//		perror("realloc");
//	}
//	else
//	{
//		p = ptr;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		p[i] = i + 1;
//	}
//	//打印出来看一看
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//用完之后不想要这块空间了，free掉
//	free(p);
//	p = NULL;
//	return 0;
//}
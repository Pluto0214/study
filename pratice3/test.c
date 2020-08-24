#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//随便输入一个数字打印这个对应的乘法口诀表
void Multiplication_Tables(num);
int main()
{
	printf("请输入数字：");
	int num;
	scanf("%d", &num);
	Multiplication_Tables(num);

	system("pause");
	return 0;
}
void Multiplication_Tables(num)
{
	int i, j, multiplication;
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= num; j++)
		{
			multiplication = i*j;
			printf("%d*%d=%-2d ", i, j, multiplication);
		}
		printf("\n");
	}
}
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//void mull(int c)
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ", j, i, j*i);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n;
//	printf("请输入9或者12来生成对应乘法口诀表\n");
//	scanf("%d", &n);
//	mull(n);
//	system("pause");
//	return 0;
//}
//void swap(int*pa, int*pb)
//{
//	int t = 0;
//	t = *pa;
//	*pa = *pb;
//	*pb = t;
//
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("a=%d b=%d\n", a, b);
//	swap(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//		
//	return 0;
//}
//int is_leap_year(int i)
//{
//	if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	if (is_leap_year(i) == 1)
//	{
//		printf("是闰年\n");
//	}
//	else
//		printf("不是闰年\n");
//	return 0;
//}
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}
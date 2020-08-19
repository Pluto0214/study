#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//打印100-200的素数
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2; j <= i - 1; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1000; i < 2001; i++)
//	{
//		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
//			//同时用多个逻辑运算符时一定要注意括号的使用
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}
//求两个数的最大公约数 
//思路：先比较a b两个数的大小 将小的数赋给b，然后用辗转相除法并循环让a%b，得到的余数再给b
//当a%b==0时跳出循环即可，最后b就是结果

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int t = 0;//比较ab，把小的值赋给b
//	scanf("%d%d", &a, &b);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	while(a%b!=0)//用辗转相除法 循环a%b 并将余数赋给b，直到余数为0跳出循环
//	{
//		t = a%b;
//		a = b;
//		b = t;
//	}
//	printf("最大公约数时：%d\n", b);
//	return 0;
//}
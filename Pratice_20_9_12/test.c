#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
int main()
{
	int i = 0;
	int j = 0;
	int num = 0;
	char arr1[16] = { 0 };
	char arr2[16] = { 0 };
	scanf("%d", &num);
	for (i = 0, j = 0; i < 32; i += 2, j++)
	{
		arr1[15 - j] = (num >> i) & 1;
	}
	for (j = 0; j < 16; j++)
	{
		printf("%d", arr1[j]);
	}
	printf("\n");
	for (i = 1, j = 0; i < 32; i += 2, j++)
	{
		arr2[15 - j] = (num >> i) & 1;
	}
	for (j = 0; j < 16; j++)
	{
		printf("%d ", arr2[j]);
	}
	printf("\n");
	return 0;
}

//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//输入例子:
//1999 2299 结果 7
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 0;
//	int count = 0;
//	scanf("%d%d", &m, &n);
//	for (i = 1; i <= 32;i++)
//	{
//		if (((m >> i) & 1) != ((n >> i) & 1))
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1
//int count_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n&(n - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int n = 15;
//	int ret = count_one(n);
//	printf("%d\n", ret);
//	return 0;
//}

//不创建临时变量交换两个整数
//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("%d %d\n", a, b);
//	a = a^b;
//	b = a^b;
//	a = a^b;
//	printf("%d %d\n", a, b);
//	return 0;
//}
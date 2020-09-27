#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int killer = 0;
	for (killer = 'A'; killer < 'D'; killer++)
	//利用ASCII码连续遍历四人
	{
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		//判断条件，三个人只有一人说真话
		{
			printf("凶手是 %c\n", killer);
		}
	}
	return 0;
}


//int main() 
//{
//	int a[10][10] = { 0 };
//	for (int i = 1; i < 11; i++) 
//	{
//		for (int j = 1; j < i; j++) 
//		{
//			if (i == 1) 
//			{
//				printf("%4d\n", a[1][1] = 1);
//			}
//			else 
//			{
//				if ((j == 1) || (i == j)) 
//				{
//					printf("%4d", a[i][j] = 1);
//				}
//				else 
//				{
//					printf("%4d", a[i][j] = a[i - 1][j - 1] + a[i - 1][j]);
//				}
//			}
//		}
//		printf("\n");
//    }
//	return 0;
//}

	//void print()
	//{
	//	int a = 0;
	//	int b = 0;
	//	int c = 0;
	//	int d = 0;
	//	int e = 0;
	//	for (a = 1; a <= 5; a++)
	//	for (b = 1; b <= 5; b++)
	//	for (c = 1; c <= 5; c++)
	//	for (d = 1; d <= 5; d++)
	//	for (e = 1; e <= 5; e++)
	//	{
	//		if (((b == 2) + (a == 3) == 1 && (b == 2) + (e == 4) == 1 && (c == 1) + (d == 2) == 1 && (c == 5) + (d == 3) == 1 && (e == 4) + (a == 1) == 1) == 1)
	//		if (a * b * c * d * e == 120)//筛出重复代码
	//			{
	//				printf("a=第%d名 b =第%d名 c =第%d名 d =第%d名 e =第%d名 ", a, b, c, d, e);
	//			}
	//	}

	//}
	//int main()
	//{
	//	print();
	//	system("pause");
	//	return 0;
	//}

	//00000000000000000000000011001000
	//00000000000000000000000011001000-a
	//00000000000000000000000001100100-b
	//00000000000000000000000100101100-c=a+b
    //00000000000000000000000100101100 a+b补码
    //01111111111111111111111011010011  反码
	//01111111111111111111111011010100  原码


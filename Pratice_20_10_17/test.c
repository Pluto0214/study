//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//typedef void(*pf_t)(int);
//pf_t signal(int, pf_t);
//typedef int*pi_t;
//int main()
//{
//	int* p1, p2;
//	pi_t p3, p4;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int(*pf1)(int, int) = Add;
//	int(*pf2)(int, int) = Sub;
//	int(*pf[4])(int, int) = { Add,Sub };
//	return 0;
//}

//制作一个计算器
//（不做深入探究，实现主逻辑）
//void menu()
//{
//	printf("***************************************\n");
//	printf("*************1.add   2.sub*************\n");
//	printf("*************3.mul   4.div*************\n");
//	printf("*************   0.exit    *************\n");
//	printf("***************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择操作数：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数：");
//			scanf("%d%d",&x,&y);
//			ret=Add(x,y);
//			printf("结果是:%d\n", ret);
//			break;
//		case 2:
//			printf("请输入两个操作数：");
//			scanf("%d%d",&x,&y);
//			ret = Sub(x, y);
//			printf("结果是:%d\n", ret);
//			break;
//		case 3:
//			printf("请输入两个操作数：");
//			scanf("%d%d",&x,&y);
//			ret = Mul(x, y);
//			printf("结果是:%d\n", ret);
//			break;
//		case 4:
//			printf("请输入两个操作数：");
//			scanf("%d%d",&x,&y);
//			ret = Div(x, y);
//			printf("结果是:%d\n", ret);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("输入错误\n");
//			break;
//			
//		}
//	} while (input);
//	//这就是为什么退出为0，如果输入为0则判断为假循环跳出去
//	
//}


//用函数指针数组制作计算器
//void menu()
//{
//	printf("***************************************\n");
//	printf("*************1.add   2.sub*************\n");
//	printf("*************3.mul   4.div*************\n");
//	printf("*************   0.exit    *************\n");
//	printf("***************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	int ret = 0;
//	int(*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		menu();
//		printf("请选择:\n");
//		scanf("%d", &input);
//		if (input == 0)
//		//如果输入的是0那就会退出do while循环
//		{
//			print("退出计算器");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个数:\n");
//			scanf("%d%d", &x, &y);
//			ret = pfArr[input](x, y);
//			printf("结果是:%d\n", ret);
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define N 1024
void Gets(char str[]) 
{
	char ch;
	for (int i = 0; i < N; ++i) 
	{
		ch = getchar();
		if (ch == '\n' || i == N - 1) 
		{
			str[i] = '\0';
			break;
		}
		str[i] = ch;
	}
}
void fun(char str[], int m) 
{
	int num = strlen(str);
	for (int i = 0; i < m; ++i) 
	{
		for (char* p = str + num - 1; str < p; --p) 
		{
			*p = *p^*str;
			*str = *p^*str;
			*p = *p^*str;
		}
	}
}
void main() 
{
	char str[N];
	int m;
	printf("请输入\n");
	Gets(str);
	printf("请输入左旋几个字符:");
	scanf("%d", &m);
	fun(str, m);
	printf("左旋%后为\n%s\n", str);
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<Assert.h>
//void levo(char *pstr, int SZ, int key)
//{
//	assert(pstr != NULL);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < key; i++)
//	{
//		char tmp = pstr[0];
//		for (j = 0; j < SZ - 1; j++)
//		{
//			pstr[j] = pstr[j + 1];
//		}
//		pstr[SZ - 1] = tmp;
//	}
//}
//int main()
//{
//	char str[4] = "ABCD";
//	int key = 0;
//	int SZ = sizeof(str) / sizeof(str[0]) - 1;
//	printf("输入你要旋转字符的个数");
//	scanf("%d", &key);
//	levo(str, SZ, key);
//	printf("%s", str);
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
extern int g_val;//ÉùÃ÷Íâ²¿·ûºÅ
int main()
{
	printf("%d\n", g_val);
	return 0;
}
//void test()
//{
//	static int i = 1;
//	i++;
//	printf("%d ", i);
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;
//}
//void test()
//{
//	int i = 1;
//	i++;
//	printf("%d ", i);
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;
//}
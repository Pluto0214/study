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

//����һ��������
//����������̽����ʵ�����߼���
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
//		printf("��ѡ���������\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("������������������");
//			scanf("%d%d",&x,&y);
//			ret=Add(x,y);
//			printf("�����:%d\n", ret);
//			break;
//		case 2:
//			printf("������������������");
//			scanf("%d%d",&x,&y);
//			ret = Sub(x, y);
//			printf("�����:%d\n", ret);
//			break;
//		case 3:
//			printf("������������������");
//			scanf("%d%d",&x,&y);
//			ret = Mul(x, y);
//			printf("�����:%d\n", ret);
//			break;
//		case 4:
//			printf("������������������");
//			scanf("%d%d",&x,&y);
//			ret = Div(x, y);
//			printf("�����:%d\n", ret);
//			break;
//		case 0:
//			printf("�˳�������\n");
//			break;
//		default:
//			printf("�������\n");
//			break;
//			
//		}
//	} while (input);
//	//�����Ϊʲô�˳�Ϊ0���������Ϊ0���ж�Ϊ��ѭ������ȥ
//	
//}


//�ú���ָ����������������
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
//		printf("��ѡ��:\n");
//		scanf("%d", &input);
//		if (input == 0)
//		//����������0�Ǿͻ��˳�do whileѭ��
//		{
//			print("�˳�������");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("������������:\n");
//			scanf("%d%d", &x, &y);
//			ret = pfArr[input](x, y);
//			printf("�����:%d\n", ret);
//		}
//		else
//		{
//			printf("ѡ�����\n");
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
	printf("������\n");
	Gets(str);
	printf("���������������ַ�:");
	scanf("%d", &m);
	fun(str, m);
	printf("����%��Ϊ\n%s\n", str);
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
//	printf("������Ҫ��ת�ַ��ĸ���");
//	scanf("%d", &key);
//	levo(str, SZ, key);
//	printf("%s", str);
//	return 0;
//}

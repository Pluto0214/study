#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//1.��ͨ�������ռ�
namespace N1
{
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}

namespace N2
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N3
	{
		int c;
		int b;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

namespace bit
{
	int a = 0;
	int b = 1;
	int c = 2;
}

using bit::b;//2.�൱�ڰ�bչ������ȫ������

using namespace bit;//3.ȫ��չ��

int main()
{
	printf("%d\n", bit::a);//1.ֱ��ָ��
	return 0;
}


void Test(int a = 1)
{
	cout << a << endl;
}

int main()
{
	Test();
	Test(2);
	return 0;
}


void Test(int a, int b = 2, int c)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//ͷ�ļ���  .h
void Test(int a = 20);

//������    .c
void Test(int a = 30)
{}




#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//1.普通的命名空间
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

using bit::b;//2.相当于把b展开到了全局域中

using namespace bit;//3.全部展开

int main()
{
	printf("%d\n", bit::a);//1.直接指定
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

//头文件中  .h
void Test(int a = 20);

//定义中    .c
void Test(int a = 30)
{}




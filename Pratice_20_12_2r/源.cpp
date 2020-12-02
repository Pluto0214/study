#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void bubblesort(int arry[], int len) 
{
	int temp = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j<len - i - 1; j++)
		{
			if (arry[j] > arry[j + 1])
			{
				temp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = temp;
			}
		}
	}
}
void selectsort(int arry[], int length)
{
	int temp;
	int index;
	for (int i = 0; i < length - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arry[index] < arry[j])
			{
				index = j;
			}
		}
		temp = arry[index];
		arry[index] = arry[i];
		arry[i] = temp;
	}
}
void show(int arry[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arry[i] << "  " << endl;
	}
	cout << "----------------------------------------" << endl;
}
int main()
{
	int arry[5] = { 1,7,5,9,3 };

	bubblesort(arry, 5);
	show(arry, 5);

	selectsort(arry, 5);
	show(arry, 5);
	return 0;

}

#include<iostream>
using namespace std;
class shape
{
public:
	float S;
	virtual float  set_s() = 0;

};
class circle :public shape
{
public:

	circle(int r, float pai) :m_r(r), m_pai(pai) {}

	float set_s()
	{
		S = m_pai * m_r * m_r;
		cout << "圆的面积；" << S << endl;
		return S;
	}


private:
	int m_r;
	float m_pai;

};

class square :public shape
{
public:

	square(int l) :m_l(l) {}

	float set_s()
	{
		S = m_l*m_l;
		cout << "正方形的面积；" << S << endl;
		return S;
	}


private:
	int m_l;;

};
class rectangle :public shape
{
public:

	rectangle(int a, int b) :m_a(a), m_b(b) {}

	float set_s()
	{
		S = m_a * m_b;
		cout << "长方形的面积；" << S << endl;
		return S;
	}


private:
	int m_a;
	int m_b;

};

class trapezoid :public shape
{
public:

	trapezoid(int a, int b, int h) :m_a(a), m_b(b), m_h(h) {}

	float set_s()
	{
		S = ((m_a + m_b)*m_h) / 2;
		cout << "梯形的面积；" << S << endl;
		return S;
	}


private:
	int m_a;
	int m_b;
	int m_h;

};
class triangle :public shape
{
public:

	triangle(int a, int h) :m_a(a), m_h(h) {}

	float set_s()
	{
		S = (m_a*m_h) / 2;
		cout << "三角形的面积；" << S << endl;
		return S;
	}


private:
	int m_a;
	int m_h;

};
void test()
{
	float S = 0;
	shape* p[5] = {
		&circle(2,3.14),
		&rectangle(5,7),
		&square(4),
		&trapezoid(2,4,6),
		&triangle(2,4)
	};
	for (int i = 0; i < 5; i++)
	{
		S = p[i]->set_s() + S;

	}
	cout << "总面积为；" << S << endl;
}
int main()
{
	test();
	return 0;
}

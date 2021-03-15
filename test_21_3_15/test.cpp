#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}

	void Show()
	{
		cout << "Show()" << endl;
	}

private:
	int _a;
};

int main()
{
	A* p = nullptr;
	p->PrintA();
	p->Show();
	return 0;
}

class Date
{
public:
	Date(int year = 2021, int month = 3, int day = 15)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date()
	{
		cout << "Date()" << endl;
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	
	Date d1;
	Date d1(2021, 3, 15);
	d1.Print();
	Date d2;
	d2.Print();

	d1.Init(2021, 3, 15);
	d1.Print();
	return 0;
}



~Stack()
{
	free(_a);
	_a = nullptr;
	_size = 0;
	_capacity = 0;
}


class Date
{
public:
	Date(int year = 2021, int month = 3, int day = 15)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{

	Date d1(2021, 3, 15);
	Date d2(d1);
	return 0;
}



class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int)*capacity);
		_capacity = capacity;
		_size = 0;
	}
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_capacity = 0;
		_size = 0;
	}
private:
	int* _a;
	int _capacity;
	int _size;
};
int main()
{
	Stack st1;
	Stack st2(st1);
	return 0;
}


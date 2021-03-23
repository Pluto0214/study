#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
public:
	//获取某年某月的天数
	int GetMonthDay(int year, int month);

	void Print();

	//全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);

	//拷贝构造函数
	Date(const Date& d);

	//赋值运算符重载
	// = 
	Date& operator=(const Date& d);

	//+=
	Date& operator+=(int day);

	//+
	Date operator+(int day);


	//>
	bool operator>(const Date& d);

    //前置++
	Date& operator++();

	//后置++
	Date operator++(int);

	//==
	bool operator==(const Date& d);

	//!=
	bool operator!=(const Date& d);

	//>=
	bool operator>=(const Date& d);

	//<
	bool operator<(const Date& d);

	//<=
	bool operator<=(const Date& d);

	//日期-日期
	int operator-(const Date& d);



private:
	int _year;
	int _month;
	int _day;
};
#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
int Date::GetMonthDay(int year, int month)
{
	static int DaysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = DaysArray[month];
	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
	{
		days = 29;
	}
	return days;
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

	//���캯��
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!(year >= 0 && month > 0 && month < 13 && day>0 && day <= GetMonthDay(year, month)))
	{
		cout << "���ڷǷ�" << endl;
	}
}

//�������캯��
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//��ֵ���������
Date& Date::operator = (const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

//>
bool Date::operator > (const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if(_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if(_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}


//+=
Date& Date::operator += (int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month += 1;
		if (_month > 12)
		{
			_month = 1;
			_year += 1;
		}
	}
	return *this;
}

//+
Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;
	return ret;
}


//ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//����++
Date Date::operator++(int day)
{
	Date ret(*this);
	ret += 1;
	return ret;
}

//==
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

//!=
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

//>=
bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

//<
bool Date::operator<(const Date& d)
{
	return (*this >= d);
}

//<=
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

//����-����
int Date::operator-(const Date& d)
{
	Date max = *this, min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		min++;
		n++;
	}
	return n*flag;
}




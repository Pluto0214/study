#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
public:
	//��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);

	void Print();

	//ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);

	//�������캯��
	Date(const Date& d);

	//��ֵ���������
	// = 
	Date& operator=(const Date& d);

	//+=
	Date& operator+=(int day);

	//+
	Date operator+(int day);


	//>
	bool operator>(const Date& d);

    //ǰ��++
	Date& operator++();

	//����++
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

	//����-����
	int operator-(const Date& d);



private:
	int _year;
	int _month;
	int _day;
};
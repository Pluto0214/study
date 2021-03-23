#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

int main()
{
	Date d1(2021, 2, 3);
	d1.Print();

	Date ret = d1 + 100;
	ret.Print();

	d1 += 100;
	d1.Print();

	ret = d1 + -100;
	ret.Print();

	d1++;
	++d1;

	Date d2(2020, 2, 29);
	d2.Print();

	Date d3(2021, 13, 0);
	d3.Print();

	Date d3(2021, 2, 3);
	Date d4(2021, 8, 1);

	cout << d3 - d4 << endl;
	cout << d4 - d3 << endl;


	return 0;
}
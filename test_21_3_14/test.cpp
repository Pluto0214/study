#define _CRT_SECURE_NO_WARNINGS 1

//F.h文件
#include<iostream>
using namespace std;

inline void f(int i);

//F.cpp文件
#include"F.h"
void f(int i)
{
	cout << i << endl;
}

//main.cpp文件
#include"F.h"
int main()
{
	f(10);
	return 0;
}



void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int x = 1, y = 2;
	swap(x, y);
	return 0;
}


int a = 5;
auto b = a;

cout << typeid(b).name() << endl;

int x = 5;
auto a = &x;
auto* b = &x;
auto& c = x;

auto a = 1, b = 2;
auto c = 3, d = 4.0;

void Test(auto a)
{}

void Test()
{
	int a[] = { 1,2,3,4 };
	auto b[] = { 5,6,7,8 };
}

void Test()
{
	int array[] = { 1,2,3,4,5 };

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		array[i] *= 2;

	for (int* p = arraylp < array + sizeof(array) / sizeof(array[0]);p++)
		
}

void Test()
{
	int array[] = { 1,2,3,4,5 };
	
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
}

void Test(int array[])
{
	for (auto& e : array)
		cout << e << endl;
}
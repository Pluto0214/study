#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Stack
{
public:
	//¹¹Ôìº¯Êý
	Stack()
	{
		_a = (int*)malloc(sizeof(int) * 4);
		_size = 0;
		_capacity = 4;
	}
	Stack(int capacity)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		_size = 0;
		_capacity = capacity;
	}



private:
	int* _a;
	int _size;
	int _capacity;
};

int main()
{
	Stack st1;
	Stack st2(10);
	return 0;
}
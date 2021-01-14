#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a; //一般这里 _指的是它是成员
	int _top; //栈顶下标 （即size）
	int _capacity;
}Stack;
//当然栈也能设置成静态的
//struct Stack
//{
//	int a[N];
//	int size;
//};

//初始化和销毁
void StackInit(Stack* pst);
void StackDestory(Stack* pst);
//入栈
void StackPush(Stack* pst, STDataType x);
//出栈
void StackPop(Stack* pst);

//获取数据个数
//这里不会改变内容 所以也可以不用指针，但为了统一最好还是传指针
int StackSize(Stack* pst);

//返回1是空，返回0是非空
int StackEmpty(Stack* pst);

//获取栈顶的数据
STDataType StackTop(Stack* pst);

#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;
//结点
typedef struct SListNode
{
	SListDataType data;
	struct SListNode *next;
}SL;

//尾插尾删
void SListPushBack(SL **pphead, SListDataType x);
void SListPopBack(SL **pphead);

//头插头删
void SListPushFront(SL **pphead, SListDataType x);
void SListPopFront(SL **pphead);

void SListPrint(SL *phead);

//查找
//这个就不需要二级指针，因为它并没有改变
SL *SListFind(SL *phead, SListDataType x);

//任意位置插入
void SListInsertAfter(SL *pos, SListDataType x);

void SListEraseAfter(SL *pos, SListDataType x);



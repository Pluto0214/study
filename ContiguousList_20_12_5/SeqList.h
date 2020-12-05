#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
////静态顺序表
//typedef int SLDataType;
//#define N 10
//
//struct SeqList
//{
//	SLDataType a[N];//顺序表就是一个数组
//	int size;//数组中有效数字的个数
//};
//
//void SeqListPushBack(struct SeqList *ps, SLDataType x);
//void SeqListPopBack(struct SeqList *ps, SLDataType x);
//void SeqListPushFront(struct SeqList *ps, SLDataType x);
//void SeqListPopFront(struct SeqList *ps, SLDataType x);


//动态顺序表
typedef int SLDataType;
#define N 10

typedef struct SeqList
{
	SLDataType *a;//动态顺序表这里给的就不是一个数组了，而是数组的指针
	int size;//数组中有效数据的个数
	int capacity;//容量 空间的大小
}SL;

//对结构体进行初始化，否则里面会是一堆随机的东西
void SeqListInit(SL *ps);//另外注意 传值和传址 所以这里传的是地址

void SeqListPrint(SL *ps);//打印

void SeqListCheckCapacity(SL *ps);//插入这部的扩容

//尾插尾删和头插头删
void SeqListPushBack(SL *ps, SLDataType x);
void SeqListPopBack(SL *ps, SLDataType x);
void SeqListPushFront(SL *ps, SLDataType x);
void SeqListPopFront(SL *ps, SLDataType x);

//任意位置的插入删除
void SeqListPopFront(SL *ps, int pos, SLDataType x);
void SeqListPopErase(SL *ps, int pos);
//int pos是要插入的位置
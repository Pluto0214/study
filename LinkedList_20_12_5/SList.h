#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;
//���
typedef struct SListNode
{
	SListDataType data;
	struct SListNode *next;
}SL;

//β��βɾ
void SListPushBack(SL **pphead, SListDataType x);
void SListPopBack(SL **pphead);

//ͷ��ͷɾ
void SListPushFront(SL **pphead, SListDataType x);
void SListPopFront(SL **pphead);

void SListPrint(SL *phead);

//����
//����Ͳ���Ҫ����ָ�룬��Ϊ����û�иı�
SL *SListFind(SL *phead, SListDataType x);

//����λ�ò���
void SListInsertAfter(SL *pos, SListDataType x);

void SListEraseAfter(SL *pos, SListDataType x);



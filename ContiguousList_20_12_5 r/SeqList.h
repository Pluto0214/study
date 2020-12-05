#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
////��̬˳���
//typedef int SLDataType;
//#define N 10
//
//struct SeqList
//{
//	SLDataType a[N];//˳������һ������
//	int size;//��������Ч���ֵĸ���
//};
//
//void SeqListPushBack(struct SeqList *ps, SLDataType x);
//void SeqListPopBack(struct SeqList *ps, SLDataType x);
//void SeqListPushFront(struct SeqList *ps, SLDataType x);
//void SeqListPopFront(struct SeqList *ps, SLDataType x);


//��̬˳���
typedef int SLDataType;
#define N 10

typedef struct SeqList
{
	SLDataType *a;//��̬˳���������ľͲ���һ�������ˣ����������ָ��
	int size;//��������Ч���ݵĸ���
	int capacity;//���� �ռ�Ĵ�С
}SL;

//�Խṹ����г�ʼ���������������һ������Ķ���
void SeqListInit(SL *ps);//����ע�� ��ֵ�ʹ�ַ �������ﴫ���ǵ�ַ

void SeqListPrint(SL *ps);//��ӡ

void SeqListCheckCapacity(SL *ps);//�����ⲿ������

void SeqListDestory(SL *ps);//���٣���Ϊʹ���˶�̬�ڴ棩


//β��βɾ��ͷ��ͷɾ
void SeqListPushBack(SL *ps, SLDataType x);
void SeqListPopBack(SL *ps, SLDataType x);
void SeqListPushFront(SL *ps, SLDataType x);
void SeqListPopFront(SL *ps, SLDataType x);

//����λ�õĲ���ɾ��
void SeqListPopFront(SL *ps, int pos, SLDataType x);
void SeqListPopErase(SL *ps, int pos);
//int pos��Ҫ�����λ��

//˳������
int SeqListFind(SL *ps, SLDataType x);
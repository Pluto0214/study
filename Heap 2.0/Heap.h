#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
typedef int HPDataType;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef struct Heap
{
	//���ڶѵ�˳��ṹ�����������飬�����ǵ��������Ҫ����
	//��������������һ��ָ�������ָ��
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//����php����˼�ǣ� hp��heap����д pһ�����ָ���һ��p���Ӳ�������ν��
void HeapInit(Heap* php,HPDataType* a,int n);
//���û�������typedef�����Ҫд��struct Heap* php��
void HeapDestory(Heap* php);
void HeapPush(Heap* php,HPDataType x);
void HeapPop(Heap* php);
HPDataType HeapTop(Heap* php);




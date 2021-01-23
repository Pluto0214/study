#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
typedef int HPDataType;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef struct Heap
{
	//由于堆的顺序结构本质上是数组，但考虑到数组可能要扩容
	//所以在这里设置一个指向数组的指针
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//这里php的意思是： hp是heap的缩写 p一般就是指针加一个p，加不加无所谓的
void HeapInit(Heap* php,HPDataType* a,int n);
//如果没有上面的typedef这里就要写成struct Heap* php了
void HeapDestory(Heap* php);
void HeapPush(Heap* php,HPDataType x);
void HeapPop(Heap* php);
HPDataType HeapTop(Heap* php);




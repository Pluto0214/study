#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//对数组进行初始化
void SeqListInit(SL *ps)
{
	////这是一种初始化方式,把a直接NULL
	/*s.size = 0;
	s.a = NULL; 
	s.capacity = 0;*/
	
	//第二种初始化方式  给a一块空间
    ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

void SeqListPrint(SL *ps)//打印
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL *ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof
			(SLDataType)*ps->capacity);
		if (ps->a = NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
}


//尾插尾删和头插头删
void SeqListPushBack(SL *ps, SLDataType x)
{
	//size就是尾的下标
	assert(ps);

	//插入这步注意要判断空间够不够，如果空间不够的话进行增容
	//因为下面还有插入的步骤，它们都需要判断是否增容，所以为了方便直接用接口
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SL *ps, SLDataType x)
{
	assert(ps);
	//注意删除数据时没必要赋值0
	//直接size--就行了，当然赋值成0也没有错
	ps->size--;
}
void SeqListPushFront(SL *ps, SLDataType x)
{
	//注意插入步骤需要判断空间够不够，是否需要增容
	SeqListCheckCapacity(ps);

	int tmp = ps->a[ps->size - 1];
	while (tmp >= 0)
	{
		ps->a[tmp + 1] = ps->a[tmp];
		tmp--;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SL *ps, SLDataType x)
{
	//直接把头部需要删除的数据覆盖
	int tmp = ps->a[ps->size - 1];
	while (tmp < ps->size-1)
	{
		ps->a[tmp] = ps->a[tmp + 1];
		tmp++;
	}
	ps->size--;
}

//任意位置的插入删除
void SeqListPopFront(SL *ps, int pos, SLDataType x);
void SeqListPopErase(SL *ps, int pos);
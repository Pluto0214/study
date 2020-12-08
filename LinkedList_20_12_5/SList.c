#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

SL *CreatListNode(SListDataType x)
{
	//开辟一个新的结点准备插入
	SL *newNode = (SL*)malloc(sizeof(SL));
	if (newNode == NULL)
	{
		printf("开辟失败\n");
		exit(-1);
	}

	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

void SListPrint(SL *phead)
{
	SL *cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
		//记住！链表在物理结构上可不是连续的空间，所以这里不能写cur++
	}
}

//尾插
void SListPushBack(SL **pphead, SListDataType x)
//48min讲了为什么传的是 **pphead 传址
{
	SL *newNode = CreatListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//找尾部
		SL *tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}
}

//尾删
void SListPopBack(SL **pphead)
{
	//有3种情况
	//1.空
	//2.有一个结点
	//3.有一个以上结点
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free((*pphead)->next);
		*pphead = NULL;
	}
	else
	{
		SL *prev = NULL;
		SL *tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		//这里tail是一个局部变量，这个函数结束后tail就没了
		//所以tail赋不赋NULL都可以。
		prev->next = NULL;
	}
}

//头插
void SListPushFront(SL **pphead, SListDataType x)
{
	//假设j结点是原先链表中的第一个结点，所以这时候*pphead是j的地址
	//现在插入了一个i成为了第一个结点
	//所以这时候要把j原先的地址（也就是*pphead）还给他
	//再把新结点i的地址给*pphead
	SL *newNode = CreatListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

//头删
void SListPopFront(SL **pphead)
{
	//同样也有三种情况
	//1.空  (不删）
	//2.一个结点  
	//3.两个及以上的结点
    //在释放之前要先把原先的第二个结点的地址保存起来
	//要不然直接把第一个结点删了（第一个结点存着第二个结点的地址）就会找不到第二个结点
	//这个方法可以适用于多个结点和只有一个结点，所以可以把这两种情况合并 

	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SL *next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//单链表查找
SL *SListFind(SL *phead, SListDataType x)
{
	SL *cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	printf("没找到\n");
	return NULL;
}

//任意位置插入
void SListInsertAfter(SL *pos, SListDataType x)
{
	assert(pos);
	SL *newNode = CreatListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//任意位置删除
void SListEraseAfter(SL *pos, SListDataType x)
{
	assert(pos);
	//先判断pos之后的那个位置不是空
	if (pos->next)
	{
		SL *next = pos->next;
		SL *nextnext = next->next;
		//建立两个变量让代码看着没那么复杂
		pos->next = nextnext;
		free(next);
	}
}



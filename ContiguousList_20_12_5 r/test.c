#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//测试头插头删
void TestSeqList1()
{
	SL s;//注意 在.c文件中进行初始化
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);

	SeqListPrint(&s);

	
}

int main()
{
	TestSeqList1();

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//����ͷ��ͷɾ
void TestSeqList1()
{
	SL s;//ע�� ��.c�ļ��н��г�ʼ��
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
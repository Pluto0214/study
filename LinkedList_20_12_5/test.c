#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

int mian()
{
	SL *phead = NULL;//ͷָ��
	//SL *plist = NULL;һ�����������д��
	SListPushBack(phead, 1);
	SListPrint(phead);
	return 0;
}



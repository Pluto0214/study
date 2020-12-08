#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

int mian()
{
	SL *phead = NULL;//头指针
	//SL *plist = NULL;一般会有这两种写法
	SListPushBack(phead, 1);
	SListPrint(phead);
	return 0;
}



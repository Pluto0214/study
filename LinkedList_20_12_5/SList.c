#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

SL *CreatListNode(SListDataType x)
{
	//����һ���µĽ��׼������
	SL *newNode = (SL*)malloc(sizeof(SL));
	if (newNode == NULL)
	{
		printf("����ʧ��\n");
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
		//��ס������������ṹ�Ͽɲ��������Ŀռ䣬�������ﲻ��дcur++
	}
}

//β��
void SListPushBack(SL **pphead, SListDataType x)
//48min����Ϊʲô������ **pphead ��ַ
{
	SL *newNode = CreatListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//��β��
		SL *tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}
}

//βɾ
void SListPopBack(SL **pphead)
{
	//��3�����
	//1.��
	//2.��һ�����
	//3.��һ�����Ͻ��
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
		//����tail��һ���ֲ��������������������tail��û��
		//����tail������NULL�����ԡ�
		prev->next = NULL;
	}
}

//ͷ��
void SListPushFront(SL **pphead, SListDataType x)
{
	//����j�����ԭ�������еĵ�һ����㣬������ʱ��*pphead��j�ĵ�ַ
	//���ڲ�����һ��i��Ϊ�˵�һ�����
	//������ʱ��Ҫ��jԭ�ȵĵ�ַ��Ҳ����*pphead��������
	//�ٰ��½��i�ĵ�ַ��*pphead
	SL *newNode = CreatListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

//ͷɾ
void SListPopFront(SL **pphead)
{
	//ͬ��Ҳ���������
	//1.��  (��ɾ��
	//2.һ�����  
	//3.���������ϵĽ��
    //���ͷ�֮ǰҪ�Ȱ�ԭ�ȵĵڶ������ĵ�ַ��������
	//Ҫ��Ȼֱ�Ӱѵ�һ�����ɾ�ˣ���һ�������ŵڶ������ĵ�ַ���ͻ��Ҳ����ڶ������
	//����������������ڶ������ֻ��һ����㣬���Կ��԰�����������ϲ� 

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

//���������
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
	printf("û�ҵ�\n");
	return NULL;
}

//����λ�ò���
void SListInsertAfter(SL *pos, SListDataType x)
{
	assert(pos);
	SL *newNode = CreatListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//����λ��ɾ��
void SListEraseAfter(SL *pos, SListDataType x)
{
	assert(pos);
	//���ж�pos֮����Ǹ�λ�ò��ǿ�
	if (pos->next)
	{
		SL *next = pos->next;
		SL *nextnext = next->next;
		//�������������ô��뿴��û��ô����
		pos->next = nextnext;
		free(next);
	}
}



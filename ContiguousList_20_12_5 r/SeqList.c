#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//��������г�ʼ��
void SeqListInit(SL *ps)
{
	////����һ�ֳ�ʼ����ʽ,��aֱ��NULL
	/*s.size = 0;
	s.a = NULL; 
	s.capacity = 0;*/
	
	//�ڶ��ֳ�ʼ����ʽ  ��aһ��ռ�
    ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}
//��Ϊ�õ���malloc������Ҫ��������
//���ٵ���s���涯̬���ٵĿռ䣬�ṹ�����s����Ҫ����
//��Ϊ���Ǹ����������Դ�����ջ���Զ�����
void SeqListDestory(SL *ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SL *ps)//��ӡ
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
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}


//β��βɾ��ͷ��ͷɾ
void SeqListPushBack(SL *ps, SLDataType x)
{
	//size����β���±�
	assert(ps);

	//�����ⲽע��Ҫ�жϿռ乻����������ռ䲻���Ļ���������
	//��Ϊ���滹�в���Ĳ��裬���Ƕ���Ҫ�ж��Ƿ����ݣ�����Ϊ�˷���ֱ���ýӿ�
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SL *ps, SLDataType x)
{
	assert(ps);
	//ע��ɾ������ʱû��Ҫ��ֵ0
	//ֱ��size--�����ˣ���Ȼ��ֵ��0Ҳû�д�
	ps->size--;
}
void SeqListPushFront(SL *ps, SLDataType x)
{
	//ע����벽����Ҫ�жϿռ乻�������Ƿ���Ҫ����
	SeqListCheckCapacity(ps);

	//ע��һ���㣬size�������β�ˣ���������Ч����
	//��size-1����������Ч�����е����һλ
	int tmp = ps->size - 1;
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
	//ֱ�Ӱ�ͷ����Ҫɾ�������ݸ���
	int tmp = 0;
	while (tmp < ps->size-1)
	{
		ps->a[tmp] = ps->a[tmp + 1];
		tmp++;
	}
	ps->size--;
}

//����λ�õĲ���ɾ��
void SeqListInsert(SL *ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);

	//�ǲ��� ͬ��ҲҪ�ж�
	SeqListCheckCapacity(ps);

	int tmp = ps->size - 1;
	while (tmp >= pos)
	{
		ps->a[tmp + 1] = ps->a[tmp];
		tmp--;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL *ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);

	int tmp = pos;
	while (tmp < ps->size - 1)
	//posӦ�õ�size-2��λ�þ�ͣ���ˣ�����size-1λ����Ų�Ļ����ܻᷢ��Խ��
	{
		ps->a[tmp] = ps->a[tmp + 1];
		tmp++;
	}
	ps->size--;
}

//˳������
//�ҵ��˷����±�
int SeqListFind(SL *ps, SLDataType x)
{
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
		{
			printf("�ҵ���\n");
			return i;
		}
		i++;
	}
	return -1;
}
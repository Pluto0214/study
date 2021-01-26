#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"


//// ֱ�Ӳ�������
//void InsertSort(int* a, int n)
//{
//	assert(a);
//	//�ȼ�����Ϊ������������һ�������±���end
//	//����Ҫ�����ǰ�end�ĺ����Ǹ�λ����ǰ����
//	//���end�����������endС����end��Ҫ����Ų�ˣ����ʱ��ͻ��end+1���ǣ�����Ҫ����һ��tmp���������end+1
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//			a[end + 1] = tmp;
//		}
//	}
//}

//// ϣ������
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;//+1��Ϊ�˱�֤���һ��gapһ����1
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end = end - gap;
//				}
//				else
//					break;
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}


// ֱ�� ѡ������
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
  
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	int max, min;
	max = min = begin;
	while (begin < end)
	{
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}

		}
		swap(&a[begin], &a[min]);
		swap(&a[end], &a[max]);
		end--;
		begin++;
	}
}

//�������� ����ȡ��
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
    if(a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin]>a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else//a[begin]>a[mid]
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
}

//��������
//��ָ�뷨
//��������
int PartSort1(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	swap(&a[midIndex], &a[end]);

	int key = a[end];
	int keyindex = end;
	//key�����棬��Ҫ�������ߣ�Ҳ����begin��
	//��Ϊ�������ܱ�֤���������λ�ñ�keyҪ��
	//����ѡ�ı���key��һ��������������ı�����
	while (begin < end)
	{
		//begin�Ҵ�
		while (begin < end && begin <= key)
		{
			begin++;
		}
		
		//end��С
		while (begin < end && end >= key)
		{
			end--;
		}
		swap(&a[begin], &a[end]);
	}
	//������λ�ú�key��λ�ý���
	swap(&a[begin], &a[keyindex]);

	return begin;
}

//�ڿӷ�
int PastSort2(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	swap(&a[midIndex], &a[end]);
	//end�൱��һ��ʼ�Ŀ�
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end && begin <= key)
		{
			begin++;
		}

		//����ҵ���key��������Ŀӣ�beginλ�þ��γ����µĿ�
		a[end] = a[begin];
		
		while (begin < end && end >= key)
		{
			end--;
		}
		//�ұ��ҵ���keyС��ֵ���ߵĿӣ�endλ�þ��γ����µĿ�
		a[begin] = a[end];
	}
	a[begin] = key;

	return begin;
}


//ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int keyindex = end;

	while (cur < end)
	{
		if (a[cur] < a[keyindex] && ++prev != cur)
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}

	swap(&a[++prev], &a[keyindex]);

	return prev;
}


void QuickSort(int* a, int left, int right)
{
	assert(a);
	//�ݹ�ʲôʱ������أ�
	if (left >= right)
	{
		return;
	}
	//����ֱ�Ӹ�����һ��if(left<=right)

	int div = PartSort(a, left, right);
	//��Ϊ��������  [left,div-1],div,[div+1,right]
	QucikSort(a, left, div - 1);
	QucikSort(a, div+1, right);


}


//�ǵݹ���ʽ�Ŀ��ţ�ջģ��ʵ��
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int div = PartSort3(a, begin, end);

		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}

		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}

	StackDestory(&st);

}



// �鲢����ݹ�ʵ��
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}

	//��left��right�������ָ����������
	int mid = (left + right) / 2;
	//[left,mid][mid+1,right] ���������ֱ�Ӻϲ�����������û��������������

	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	//����[left,mid][mid+1,right] �����ˣ����й鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid+1, end2 = right;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//�ѹ鲢�õ������ٿ�����ԭ����
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int)*n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
} 


//�鲢����ǵݹ�ʵ��

void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1, right = end2;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
}


void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int)*n);
	int gap = 1;
	while (gap <= n / 2)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i,
			MergeArr(a, i, i + gap - 1, i + gap, i + 2 * gap - 1, tmp);
		}
		gap *= 2;
	}

	free(tmp);
}

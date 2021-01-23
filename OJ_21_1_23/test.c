#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			//����child+1<n���ж��Һ����Ƿ����
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
	*returnSize = k;
	if (k == 0)
	{
		return NULL;
	}

	int* retArr = (int*)malloc(sizeof(int)*k);

	for (int i = 0; i < k; i++)
	{
		retArr[i] = arr[i];
	}
	//��k����С�Ķ�
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(retArr, k, i);
	}

	for (int j = k; j < arrSize; j++)
	{
		if (arr[j] < retArr[0])
		{
			retArr[0] = arr[j];
			AdjustDown(retArr, k, 0);
		}
	}
	return retArr;

}



//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int size = 0;
//	//��������� ����һ��ȫ�ֱ�������ôÿ�εݹ�+��size�Ͳ���ͬһ���ˣ�ÿ�ζ��Ƕ�����һ���µ�size��
//	size++;
//	TreeSize(root->_left);
//	TreeSize(root->_right);
//	return size;
//}

void TreeSize(BTNode* root, int* psize)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		*psize++;
	}
	TreeSize(root->_left, psize);
	TreeSize(root->_right, psize);
}

int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + TreeSize(root->_left) + TreeSize(root->_right);
	}
}


int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}
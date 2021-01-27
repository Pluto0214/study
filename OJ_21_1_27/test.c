#define _CRT_SECURE_NO_WARNINGS 1
void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1, right = end2;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}


	while (begin1 <= end1)
		tmp[index++] = a[begin1++];


	while (begin2 <= end2)
		tmp[index++] = a[begin2++];


	// 把归并好的数据拷贝到原数组
	for (int i = left; i <= right; ++i)
		a[i] = tmp[i];
}


void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;


	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);


	// 归并[left,mid][mid+1,right]有序
	MergeArr(a, left, mid, mid + 1, right, tmp);
}


void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int)*n);


	_MergeSort(a, 0, n - 1, tmp);


	free(tmp);
}


int* sortArray(int* a, int n, int* returnSize) {
	*returnSize = n;


	MergeSort(a, n);

	return a;


}
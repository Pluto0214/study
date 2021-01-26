#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//void TestInsertSort()
//{
//	int a[] = { 5,8,9,1,6,3,7,2,4 };
//	PrintArray(a, sizeof(a) / sizeof(int));
//	InsertSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//
//}

void TestSelectSort()
{
	int a[] = { 5,8,9,1,6,3,7,2,4 };
	PrintArray(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}

int main()
{
	/*TestInsertSort();*/
	TestSelectSort();

	return 0;
}
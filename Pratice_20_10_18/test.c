#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
struct S
{
	char name[20];
	int age;
};
int cmp_str_by_name(const void* e1, const void* e2)
{
	//���ֱȴ�С
	return strcmp(((struct S*)e1)->name, ((struct S*)e2)->name);
}
void test2()
{
	struct S arr[] = { { "zhangsan",20 },{ "lisi",80 },{ "wangwu",30 } };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(0), cmp_str_by_name);
}
//struct S
//{
//	char name[20];
//	int age;
//};
//int cmp_str_by_age(const void* e1,const void* e2)
//{
//	//�ṹ��ָ����Բ��ý�����.age��Ҳ������->age
//	return((struct S*)e1)->age - ((struct S*)e2)->age;
//}
//void test2()
//{
//	struct S arr[] = { {"zhangsan",20},{"lisi",80},{"wangwu",30} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(0), cmp_str_by_age);
//}

//int main()
//{
//	
//	int i = 0;
//	int j = 0;
//	int arr[] = { 0,1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i <= sz - 1; i++)
//	{
//		for (j = 0; j <= sz - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int tmp = 0;
//				tmp = arr[j];
//			}
//		}
//	}
//	return 0;
//}
//void left_move(char arr[], int k)
//{
//	int i = 0;
//	int len = strlen(arr);
//	assert(k <= len);
//	for (i = 0; i < k; i++)
//	{
//		//��תһ���ַ�
//		char tmp = arr[0];
//		int j = 0;
//		for (j = 0; j < len;j++)
//		{
//			//��j+1�±��j�±��Ԫ�ؽ��н���
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	//����д��char*arr=".."��Ϊ����һ�������ַ��������ܸı�
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, k);
//	printf("")
//	//��Ϊ����һ���ַ��������Բ��ô��ַ����ж���Ԫ�أ���Ϊ��\0��
//	//����������ַ���֮��Ļ���Ҫ��sz�ˡ�
//	return 0;
//}
//int main()
//{
//	int *p = NULL;
//	int arr[10] = { 0 };
//	return 0;
//}
//A.p = arr;
//B.int(*ptr)[10] = &arr;
//C.p = &arr[0];
//D.p = &arr;
//
//����һ������ָ�룬ָ��ĺ���������int�ββ��ҷ���һ������ָ�룬
//���ص�ָ��ָ��һ����һ��int�β��ҷ���int�ĺ����������ĸ�����ȷ��
//A.int(*(*F)(int, int))(int)
////�Ѻ������Ͳ�������ȥ����ʣ�µľ��Ƿ���������int(*)(int)
//B.int(*F)(int, int)
//C.int(*(*F)(int, int))
//D.*(*F)(int, int)(int)
//
//
//
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int *ptr1 = (int *)(&aa + 1);
//	//��int *)��ǿ������ת����
//	int *ptr2 = (int *)(*(aa + 1));
//	//aa�Ƕ�ά�������Ԫ�صĵ�ַ�����ǵ�һ�еĵ�ַ��
//	//��һ�еĵ�ַ+1���ǵڶ��еĵ�ַ��
//	//Ȼ���ٶԵڶ��еĵ�ַ���н����ò������õ��˵ڶ���
//	//��һ�е���������aa[0]���ڶ��е���������[1]
//	//
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//��Ŀ���ݣ�
//A.1, 6
//B.10, 5
//C.10, 1
//D.1, 5
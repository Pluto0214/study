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
	//名字比大小
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
//	//结构体指针可以不用解引用.age，也可以用->age
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
//		//旋转一个字符
//		char tmp = arr[0];
//		int j = 0;
//		for (j = 0; j < len;j++)
//		{
//			//把j+1下标和j下标的元素进行交换
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	//不能写成char*arr=".."因为这是一个常量字符串，不能改变
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, k);
//	printf("")
//	//因为这是一个字符串，所以不用传字符串有多少元素，因为有\0，
//	//如果是整形字符串之类的话就要传sz了。
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
//定义一个函数指针，指向的函数有两个int形参并且返回一个函数指针，
//返回的指针指向一个有一个int形参且返回int的函数？下面哪个是正确的
//A.int(*(*F)(int, int))(int)
////把函数名和参数类型去掉，剩下的就是返回类型了int(*)(int)
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
//	//（int *)是强制类型转换，
//	int *ptr2 = (int *)(*(aa + 1));
//	//aa是二维数组的首元素的地址，就是第一行的地址。
//	//第一行的地址+1就是第二行的地址了
//	//然后再对第二行的地址进行解引用操作，得到了第二行
//	//第一行的数组名是aa[0]，第二行的数组名是[1]
//	//
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//题目内容：
//A.1, 6
//B.10, 5
//C.10, 1
//D.1, 5
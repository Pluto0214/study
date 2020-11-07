#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdio.h>
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	int num = 0;
//	int i = 0;
//	for (i = 1; i <= 5; i++)
//	{
//		num = n + 10 * num;
//		sum += num;
//	}
//	printf("%d\n", sum);
//	return 0;
//}




//写一个函数可以逆序一个字符串的内容(牛客网）
//void reverse(char * arr)
//{
//	int len = strlen(arr);
//	char * left = arr;
//	char * right = arr + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "ABCDE";
//	reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}




//求两个数二进制中不同位的个数（牛客网）
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 0;
//	int count = 0;
//	scanf("%d%d", &a, &b);
//	for (i = 0; i <= 32; i++)
//	{
//		if (((a >> i) & 1) != ((b >> i) & 1))
//			count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}




//求一个整数存储再二进制中1的个数(牛客网）
//int count_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n&(n - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int n = 4;
//	int ret = count_one(n);
//	printf("%d\n", ret);
//	return 0;
//}



//不用第三个数将两个值交换
//int main()
//{
//	int a = 3;
//	int b = 5;
//	a = a^b;
//	b = a^b;
//	a = a^b;
//	printf("%d %d\n", a, b);
//	return 0;
//}


//冒泡排序
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int n = 0;
//	for (n = 0; n < sz ; n++)
//	{
//		printf("%d", arr[n]);
//	}
//	return 0;
//}

//求第n个斐波那契数（不考虑溢出）
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while(n>2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}
//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//求n的阶乘 递归
//int Fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n*Fac(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fac(n);
//	printf("%d\n", ret);
//	return 0;
//}

//二分查找
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	scanf("%d", &k);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到");
//	}
//	else
//		printf("找到了，下标是：%d\n", ret);
//	return 0;
//}

//int main()
//{
//	double sum = 0.0;
//	int a = 1;
//	for (int i = 1; i <= 100; i++) 
//	{
//		sum += (1.0*a) / i;
//		a = -a;
//	}
//	printf("sum=%lf\n", sum);
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
//			printf("%d\n", i);
//	}
//	return 0;
//}

//模拟实现strcmp
//int my_strcmp(const char * s1, const char * s2)
//{
//	while (*s1 == *s2)
//	{
//		if (*s1=='\0')
//		{
//			return 0;
//		}
//		s1++;
//		s2++;
//	}
//	return *s1 - *s2;
//}
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = "abd";
//	printf("%d\n", my_strcmp(arr1, arr2));
//	return 0;
//}

//模拟实现strcat
//char * my_strcat(char* dest, const char* src)
//{
//	char *ret = dest;
//	//寻找目标函数的\0
//	while (*dest)
//	{
//		dest++;
//	}
//	//copy字符串
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[100] = "hello ";
//	printf("%s\n", my_strcat(arr, "world"));
//	return 0;
//}

//模拟实现strcpy
//char * my_strcpy(char dest[], const char * src)
//{
//	assert(dest);
//	assert(src);
//	char * ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char*str = "abcdef";
//	char arr[100] = "XXXXXXXXXXXX";
//	my_strcpy(arr, str);
//	printf("%s\n", arr);
//	return 0;
//}

//模拟实现strlen
//int my_strlen(char *str)
//{
//	assert(str);
//	if (*str)
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "hello";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//int my_strlen(char * str)
//{
//	assert(str);
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "hello";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//字符串左旋
//void reverse(char * left, char *right)
//{
//	assert(left);
//	assert(right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char arr[], int k)
//{
//	int len = strlen(arr);
//	reverse(arr, arr + k - 1);
//	reverse(arr + k , arr + len - 1);
//	reverse(arr, arr + len - 1);
//}
//int main()
//{
//	char arr[] = "ABCDEF";
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}

//void left_reverse(char arr[], int k)
//{
//	int len = strlen(arr);
//	int i = 0;
//	for (i = 0; i <k; i++)
//	{
//		char tmp = arr[0];
//		int j = 0;
//		for (j = 0; j < len; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "ABCDEF";
//	int k = 0;
//	scanf("%d", &k);
//	left_reverse(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}


//杨辉三角主框架
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int arr[100][100] = { 0 };
//	scanf("%d", &n);
//	for (i = 0; i <= n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i <= n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//写一个函数逆序字符串内容
//void reverse_arr(char *str)
//{
//	int len = strlen(str);
//	char *left = str;
//	char *right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		right--;
//		left++;
//	}
//}
//int main()
//{
//	char arr[] = "abcde";
//	reverse_arr(arr);
//	printf("%s\n", arr);
//	return 0;
//}
//写一个程序判断计算机是大端还是小端
//int check_sys()
//{
//	int a = 1;
//	return *(char *)&a;
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//		printf("大端\n");
//}
//int main()
//{
//	int a = 1;
//	char*p = (char*)&a;
//	if (*p == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}
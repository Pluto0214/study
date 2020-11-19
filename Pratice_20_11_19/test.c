#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<assert.h>
#include<string.h>
//判断判断一个字符串是不是另外一个字符串左旋转过来的
//again
void left_move(char * str,int n)
{
	int i = 0;
	int j = 0;
	int len = strlen(str);
	for (i = 0; i < n; i++)
	{
		char tmp = *str;
		for (j = 0; j < len - 1; j++)
		{
			*(str + j) = *(str + j + 1);
		}
		*(str + len - 1) = tmp;
	}
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int len = strlen(arr1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(arr1, 1);
		if (strcmp(arr1, arr2) == 0)
		{
			printf("yes\n");
			break;
		}
	}
	if (i == len)
	{
		printf("no\n");
	}

	return 0;
}

int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "cdefab";
	if (strlen(arr1) != strlen(arr2))
	{
		printf("no\n");
	}
	strncat(arr1, arr1, 6);
	char * ret = strstr(arr1, arr2);
	if (ret == NULL)
	{
		printf("no\n");
	}
	else
		printf("yes\n");
	return 0;
}

int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "cdefab";
	if (strlen(arr1) != strlen(arr2))
	{
		printf("no\n");
		return 0;
	}
	strncat(arr1, arr1, 6);
	char * ret = strstr(arr1, arr2);
	if (ret == NULL)
	{
		printf("no\n");
	}
	else
		printf("yes\n");
	return 0;
}

void left_move(char *str,int n)
{
	int len = strlen(str);
	int i = 0;
	int j = 0;
	for (j = 0; j < n; j++)
	{
		char  tmp = *str;
		for (i = 0; i < len-1; i++)
		{
			*(str + i) = *(str + 1 + i);
		}
		*(str + len - 1) = tmp;
	}
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int len = strlen(arr1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(arr1, 1);
		if (strcmp(arr1, arr2) ==  0)
		{
			printf("yes\n");
			break;
		}
	}
	if (i == len)
	{
		printf("no\n");
	}
	return 0;
}

//模拟实现memmove
void * my_memmove(void * dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	void * ret = dest;
	if (dest < src)
	{
		while (count--)
		{
			*(char *)dest = *(char *)src;
			dest = (char *)dest + 1;
			src = (char *)src + 1;
		}
	}
	else
		while (count--)
		{
			*((char *)dest + count) = *((char *)src + count);
		}
	return dest;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	my_memmove(arr + 2, arr, 16);
	return 0;
}

//模拟实现memcpy
void* my_memcpy(void * dest, const void * src, size_t count)
{
	assert(dest);
	assert(src);
	void * ret = dest;
	while (count--)
	{
		*(char *)dest = *(char *)src;
		dest = (char *)dest + 1;
		src = (char *)src + 1;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	return 0;
}

//模拟实现strcmp
int my_strcmp(const char * s1, const char * s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
int main()
{
	char arr1[] = "abcd";
	char arr2[] = "abcd";
	int ret = my_strcmp(arr1, arr2);
	printf("%d\n", ret);
	return 0;
}

//模拟实现strcat
char * my_strcat(char * dest, const char * src)
{
	char * ret = dest;
	assert(dest);
	assert(src);
	//第一步：先找到目标的\0
	while (*dest)
	{
		dest++;
	}
	//第二步：copy
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[20] = "hello";
	printf("%s\n", my_strcat(arr1, " world"));
	return 0;
}

//模拟实现strcpy
char * my_strcpy(char * dest, const char * src)
{
	assert(dest);
	assert(src);
	char * ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char *str = "abcdef";
	char arr[] = "XXXXXXXXXXX";
	my_strcpy(arr, str);
	printf("%s\n", arr);
	return 0;
}

//模拟实现strlen
//使用指针方式
int my_strlen(const char * str)
{
	const char * left = str;
	while (*str)
	{
		str++;
	}
	return str - left;
}

//使用递归方式
int my_strlen(const char * str)
{
	assert(str);
	if (*str)
	{
		return 1 + my_strlen(str + 1);
	}
	else
		return 0;
}

//使用临时变量
int my_strlen(char * str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char arr[] = "abcde";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}

int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *ptr1 = (int *)(&aa + 1);
	int *ptr2 = (int *)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}

int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int *p;
	p = a[0];
	printf("%d", p[0]);
	return 0;
}
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	return 0;
}
//把a强制转换成int整形，一个整数+1就是像后跳了一个字节，
//4的十六进制

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	return 0;
}
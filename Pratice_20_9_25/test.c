#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
int main()
{
	int money = 20;
	int total = money;
	int empty = money;
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", total);
	return 0;
}

//��Ŀ������һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿��

//void MoveNum(int arr[], int sz)
//{
//	int *left = arr;
//	int *right = arr + sz - 1;
//	int tmp = 0;
//	while (left < right)
//	{
//		while ((left < right) && (*left) % 2 != 0)//��֤��Խ�絫����������
//		{
//			left++;
//		}
//		while ((left < right) && (*right) % 2 == 0)//��֤��Խ�絫�����ҵ�ż��
//		{
//			right--;
//		}
//		if (left < right)//������ż������
//		{
//			tmp = *left;
//			*left = *right;
//			*right = tmp;
//		}
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	MoveNum(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//ģ��ʵ�ֿ⺯��strlen
//#include <assert.h>
//int my_strlen(const char*str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcde";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}


////ģ��ʵ��strlen
//#include <assert.h>
//char*my_strcpy(char*dest, const char*src)
//{
//	char*ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "hello word";
//	char arr2[20] = "XXXXXXXXXXXXXXXXXXXX";
//	printf("%s\n", my_strcpy(arr2, arr1));
//}


//���ͼ��
//void PrintLine(int blank_count, int start_count) {
//	int i = 0;
//	for (; i < blank_count; i++) {
//		printf(" ");  
//	}
//	for (i = 0; i < start_count; i++) {
//		printf("*");
//	}
//	printf("\n");
//}
//void  PrintLingxing(int n) {
//	int i = 1;
//	for (i = 1; i < n; i++) {
//		PrintLine(n - i, 2 * i - 1);  
//	}
//	PrintLine(0, 2 * n - 1);
//	for (i = n - 1; i>0; i--) {
//		PrintLine(n - i, 2 * i - 1);
//	}
//}
//int main() {
//	PrintLingxing(7); 
//	return 0;
//}


//���0��100000֮������С�ˮ�ɻ����������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��
//ȷ�õ��ڸ���������:153��1^3��5^3��3^3����153��һ����ˮ�ɻ�����
//int fun(int m, int n)
//{
//	if (n != 0)
//		return m * fun(m, n - 1);
//	else
//	{
//		return 1;
//	}
//}
//void main()
//{
//	int i = 0;
//	for (i = 1; i<100000; i++)
//	{
//		int tmp = i;
//		int n = 0;
//		while (tmp)
//		{
//			tmp = tmp / 10;
//			n++;
//		}
//		int sum = 0;	
//		tmp = i;
//		while (tmp)
//		{
//			int m = tmp % 10;
//			int res = fun(m, n);
//			tmp /= 10;
//			sum += res;
//		}
//		if (sum == i)
//			printf("%d��ˮ����\n", i);
//	}
//}


//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int num = a;
//	int sn = a;
//	int i = 0;
//	for (i = 1; i < 5; i++)
//	{
//		num = a + 10 * num;
//		sn = sn + num;
//	}
//
//	printf("%d", sn);
//	return 0;
//}

//дһ����������������һ���ַ���������
//void reverse(char * arr)
//{
//	char *left = arr;
//	char *right = arr + strlen(arr) - 1;
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++, right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcde";
//	reverse(arr);
//	printf("%s ", arr);
//	return 0;
//}


//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
//arr��һ������һά����
//void print(int arr[],int* pa)
//{
//	int i = 0;
//	for (i = 0; i <= 4; i++)
//	{
//		printf("%d ", (*pa + i));
//	}
//}
//int main()
//{
//	int arr[5] = { 0,1,2,3,4 };
//	int* pa = arr;
//	print(arr, pa);
//	return 0;
//}
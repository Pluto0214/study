#define _CRT_SECURE_NO_WARNINGS 1

int cmp(const void*a, const void*b) {
	char s[100], s1[100];
	sprintf(s, "%d%d", *(int *)a, *(int *)b);
	sprintf(s1, "%d%d", *(int *)b, *(int *)a);
	return strcmp(s1, s);//s1>s return>0 == 0  < <0
}
char * largestNumber(int* nums, int numsSize) {
	//用c自带排序函数排序，
	qsort(nums, numsSize, sizeof(int), cmp);//cmp<0 ab 
											//jing 
	if (nums[0] == 0) return "0";
	char *result, *p;
	result = (char*)malloc(sizeof(char) * 1000);
	p = result;//result存储着字符串的起始位置  用p去进行拼接操作
	for (int i = 0; i<numsSize; i++) {
		sprintf(p, "%d", nums[i]);
		p += strlen(p);
	}
	return result;
}


int cmp(int *a, int *b) {
	char s[100], s1[100];
	sprintf(s, "%d%d", *a, *b);
	sprintf(s1, "%d%d", *b, *a);
	return strcmp(s1, s);
}
char * largestNumber(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp);
	if (nums[0] == 0) return "0";
	char *s, *p;
	s = (char*)malloc(sizeof(char) * 1000);
	p = s;
	for (int i = 0; i<numsSize; i++) {
		sprintf(p, "%d", nums[i]);
		p += strlen(p);
	}
	return s;
}
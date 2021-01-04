#define _CRT_SECURE_NO_WARNINGS 1
int removeElement(int* nums, int numsSize, int val) {
	int count = 0;
	int *p = nums;
	for (int i = 0; i<numsSize; i++)
	{
		if (p[i] != val) 
		{
			*nums = p[i];
			nums++;
			count++;
		}
	}
	return count;
}

int removeDuplicates(int* nums, int numsSize) {
	int i = 0;
	int j = 0;
	for (i = 0; i<numsSize - 1; i++)
	{          
		if (nums[i] == nums[i + 1])
			j += 1;
		nums[i + 1 - j] = nums[i + 1]; 
	}
	numsSize = numsSize - j;
	return numsSize;
}

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	int i = ASize - 1;

	while (K != 0 && i >= 0)
	{
		A[i] += K;
		K = A[i] / 10;
		A[i] %= 10;
		i--;
	}

	if (K != 0) 
	{
		int size = 10;
		int *New = (int*)malloc(sizeof(int)*size);  
		i = size - 1;
		while (K != 0)
		{
			New[i] = K % 10;
			K /= 10;
			i--;
		}
		int usedSize = size - 1 - i;
		int *Ret = (int*)malloc(sizeof(int)*(usedSize + ASize));
		memcpy(Ret, New + i + 1, sizeof(int)*usedSize);
		memcpy(Ret + usedSize, A, sizeof(int)*ASize);
		*returnSize = usedSize + ASize;

		return Ret;
	}
	*returnSize = ASize;
	return A;
}

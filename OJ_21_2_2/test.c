#define _CRT_SECURE_NO_WARNINGS 1

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
// ����ע��˵�˸�û��˵�Ҹо���࣬����������°���C����д����̫���ˣ��ο���dodo����
int CompareByIncrease(const void* a, const void* b)
{
	return *(int*)a - *(int*)b; // ���Ź����������
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	// ����returnSize������Ϊ��ά���������±��ָ��
	// �ų�[]ʱֻ������]��ƽ̨bug
	*returnSize = 0;
	// �ų�����3���������
	if (numsSize < 3)
	{
		return NULL;
	}

	int cur = 0; // �൱���Ա�����low��high�ĺ��൱�������෴��
	int low = cur + 1;
	int high = numsSize - 1;

	// LeetCode ��realloc����,malloc���Ը÷���A(3)(numsSize)���пռ䣬���ǻ�����,��������ƽ������ʲô����취��
	int** returnArray = (int**)malloc(sizeof(int*) * (numsSize)*(numsSize));
	*returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize)); // �°����ӵĲ�������������������������ֱ���� 
																			// ����stdlib��Ŀ���������
	qsort(nums, numsSize, sizeof(int), CompareByIncrease);

	// ��һ��ѭ����������cur���ڶ���ѭ������˫ָ�����м��
	while ((nums[cur] <= 0) && (cur + 1 < numsSize - 1)) // ���෴������0ʱͣ�£�����Ķ��������ˣ��϶�������
	{
		// ÿ�θ���
		low = cur + 1;
		high = numsSize - 1;

		while (low < high)
		{
			if (0 == (nums[low] + nums[high] + nums[cur]))
			{
				returnArray[*returnSize] = (int*)malloc(sizeof(int) * 3); // ÿ���ҵ�һ�飬����ָ��ͷ��������ռ�
				(*returnColumnSizes)[*returnSize] = 3; // ��¼�������ǳ�ɧ������Ĳ���
				returnArray[*returnSize][0] = nums[cur];
				returnArray[*returnSize][1] = nums[low];
				returnArray[*returnSize][2] = nums[high];
				(*returnSize)++;

				// ȥlow��high����,�ǳ����淶��д���������ż������
				while ((nums[low] == nums[++low]) && (low < high)); // ����ȥ��
				while ((nums[high] == nums[--high]) && (low < high)); // ��ǰȥ��
			}
			else if (0 < (nums[low] + nums[high] + nums[cur]))
			{
				high--;
			}
			else
			{
				low++;
			}
		}
		// ȥcur���أ�ͬ���ǳ����淶��д���������ż������
		while ((nums[cur] == nums[++cur]) && (cur + 1 < numsSize - 1)); // ����ȥ�أ�ͬʱcur������  
	}
	return returnArray;
}

int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
	if (numsSize == 0) {
		return 0;
	}
	int **ret = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
	*returnSize = 0;
	short left = 0;
	short right = numsSize - 1;;
	int target = 0;

	*returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);
	qsort(nums, numsSize, sizeof(int), comp);
	ret[*returnSize] = malloc(sizeof(int) * 3);

	while (left + 1 < right) {
		int i = left + 1;
		int j = right;
		target = 0 - nums[left];
		while (i < j) {
			if (nums[i] + nums[j] < target) {
				i++;
			}
			else if (nums[i] + nums[j] > target) {
				j--;
			}
			else {
				ret[*returnSize][0] = nums[left];
				ret[*returnSize][1] = nums[i];
				ret[*returnSize][2] = nums[j];
				(*returnColumnSizes)[*returnSize] = 3;
				(*returnSize)++;
				ret[*returnSize] = malloc(sizeof(int) * 3);

				while (nums[i] == nums[++i] && i < j) {}
				while (nums[j] == nums[--j] && i < j) {}
			}
		}
		while (nums[left] == nums[++left] && left + 1 < right) {}
	}

	return ret;
}
#define _CRT_SECURE_NO_WARNINGS 1

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0) return false;
	//������k�������������jͳ���ظ�����
	int j = 1, k = 1;
	for (int i = 1; i<numsSize; i++) {
		if (nums[i] != nums[i - 1]) {
			nums[k++] = nums[i];
			j = 1;
		}
		else {
			j++;
			if (j == 2) {
				nums[k++] = nums[i];
			}
		}
	}
	return k;
}
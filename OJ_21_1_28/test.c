#define _CRT_SECURE_NO_WARNINGS 1
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
	int left = newInterval[0];
	int right = newInterval[1];
	bool placed = false;
	int** ans = malloc(sizeof(int*) * (intervalsSize + 1));
	*returnColumnSizes = malloc(sizeof(int*) * (intervalsSize + 1));
	for (int i = 0; i < intervalsSize; ++i) {
		int* interval = intervals[i];
		if (interval[0] > right) {
			// 在插入区间的右侧且无交集
			if (!placed) {
				int* tmp = malloc(sizeof(int) * 2);
				tmp[0] = left, tmp[1] = right;
				(*returnColumnSizes)[*returnSize] = 2;
				ans[(*returnSize)++] = tmp;
				placed = true;
			}
			int* tmp = malloc(sizeof(int) * 2);
			memcpy(tmp, interval, sizeof(int) * 2);
			(*returnColumnSizes)[*returnSize] = 2;
			ans[(*returnSize)++] = tmp;
		}
		else if (interval[1] < left) {
			// 在插入区间的左侧且无交集
			int* tmp = malloc(sizeof(int) * 2);
			memcpy(tmp, interval, sizeof(int) * 2);
			(*returnColumnSizes)[*returnSize] = 2;
			ans[(*returnSize)++] = tmp;
		}
		else {
			// 与插入区间有交集，计算它们的并集
			left = fmin(left, interval[0]);
			right = fmax(right, interval[1]);
		}
	}
	if (!placed) {
		int* tmp = malloc(sizeof(int) * 2);
		tmp[0] = left, tmp[1] = right;
		(*returnColumnSizes)[*returnSize] = 2;
		ans[(*returnSize)++] = tmp;
	}
	return ans;
}
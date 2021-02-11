#define _CRT_SECURE_NO_WARNINGS 1

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
	int box[10005];
	int keng[10005];
	int maxNum = 0;
	int l, r, cnt;
	returnSize[0] = 0;
	int **returnArr = (int**)calloc(intervalsSize, sizeof(int*));
	returnColumnSizes[0] = (int*)calloc(intervalsSize, sizeof(int));
	for (int i = 0; i < intervalsSize; ++i) {
		returnArr[i] = (int*)calloc(2, sizeof(int));
		returnColumnSizes[0][i] = 2;
	}
	memset(box, 0, sizeof(box));
	memset(keng, 0, sizeof(keng));
	for (int i = 0; i < intervalsSize; ++i) {
		if (box[intervals[i][0]] == box[intervals[i][1]]) {
			keng[intervals[i][0]] = 1;
		}
		++box[intervals[i][0]];
		--box[intervals[i][1]];
		maxNum = maxNum < intervals[i][1] ? intervals[i][1] : maxNum;
	}
	for (int i = 0; i <= maxNum; ++i) {
		if (!box[i] && keng[i] && cnt == 0) {
			returnArr[returnSize[0]][0] = i;
			returnArr[returnSize[0]++][1] = i;
		}
		if (box[i]) {
			if (cnt == 0) {
				l = i;
			}
			cnt += box[i];
			if (cnt == 0) {
				r = i;
				returnArr[returnSize[0]][0] = l;
				returnArr[returnSize[0]++][1] = r;
			}
		}
	}
	return returnArr;
}
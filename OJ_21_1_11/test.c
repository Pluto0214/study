#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int cmp(const void* _a, const void* _b) {
	int *a = *(int**)_a, *b = *(int**)_b;
	return a[0] * a[0] + a[1] * a[1] - b[0] * b[0] - b[1] * b[1];
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes) {
	qsort(points, pointsSize, sizeof(int*), cmp);
	*returnSize = K;
	*returnColumnSizes = malloc(sizeof(int) * K);
	int** ret = malloc(sizeof(int*) * K);
	for (int i = 0; i < K; i++) {
		(*returnColumnSizes)[i] = 2;
		ret[i] = malloc(sizeof(int) * 2);
		ret[i][0] = points[i][0], ret[i][1] = points[i][1];
	}
	return ret;
}

void swap(int** a, int** b) {
	int* t = *a;
	*a = *b, *b = t;
}

void random_select(int** points, int left, int right, int K) {
	int pivot_id = rand() % (right - left + 1) + left;
	int pivot = points[pivot_id][0] * points[pivot_id][0] + points[pivot_id][1] * points[pivot_id][1];
	swap(points[right], points[pivot_id]);
	int i = left - 1;
	for (int j = left; j < right; ++j) {
		int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
		if (dist <= pivot) {
			++i;
			swap(&points[i], &points[j]);
		}
	}
	++i;
	swap(&points[i], &points[right]);
	// [left, i-1] 都小于等于 pivot, [i+1, right] 都大于 pivot
	if (K < i - left + 1) {
		random_select(points, left, i - 1, K);
	}
	else if (K > i - left + 1) {
		random_select(points, i + 1, right, K - (i - left + 1));
	}
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes) {
	srand(time(0));
	random_select(points, 0, pointsSize - 1, K);
	*returnSize = K;
	*returnColumnSizes = malloc(sizeof(int) * K);
	int** ret = malloc(sizeof(int*) * K);
	for (int i = 0; i < K; i++) {
		(*returnColumnSizes)[i] = 2;
		ret[i] = malloc(sizeof(int) * 2);
		ret[i][0] = points[i][0], ret[i][1] = points[i][1];
	}
	return ret;
}
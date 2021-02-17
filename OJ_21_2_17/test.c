#define _CRT_SECURE_NO_WARNINGS 1

struct TreeNode** buildTree(int start, int end, int* returnSize) {
	if (start > end) {
		(*returnSize) = 1;
		struct TreeNode** ret = malloc(sizeof(struct TreeNode*));
		ret[0] = NULL;
		return ret;
	}
	*returnSize = 0;
	struct TreeNode** allTrees = malloc(0);
	// 枚举可行根节点
	for (int i = start; i <= end; i++) {
		// 获得所有可行的左子树集合
		int leftTreesSize;
		struct TreeNode** leftTrees = buildTree(start, i - 1, &leftTreesSize);

		// 获得所有可行的右子树集合
		int rightTreesSize;
		struct TreeNode** rightTrees = buildTree(i + 1, end, &rightTreesSize);

		// 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
		for (int left = 0; left < leftTreesSize; left++) {
			for (int right = 0; right < rightTreesSize; right++) {
				struct TreeNode* currTree = malloc(sizeof(struct TreeNode));
				currTree->val = i;
				currTree->left = leftTrees[left];
				currTree->right = rightTrees[right];

				(*returnSize)++;
				allTrees = realloc(allTrees, sizeof(struct TreeNode*) * (*returnSize));
				allTrees[(*returnSize) - 1] = currTree;
			}
		}
		free(rightTrees);
		free(leftTrees);
	}
	return allTrees;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
	if (!n) {
		(*returnSize) = 0;
		return NULL;
	}
	return buildTree(1, n, returnSize);
}
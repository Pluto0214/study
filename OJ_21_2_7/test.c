#define _CRT_SECURE_NO_WARNINGS 1

int dfs(struct TreeNode* root, int prevSum) {
	if (root == NULL) {
		return 0;
	}
	int sum = prevSum * 10 + root->val;
	if (root->left == NULL && root->right == NULL) {
		return sum;
	}
	else {
		return dfs(root->left, sum) + dfs(root->right, sum);
	}
}

int sumNumbers(struct TreeNode* root) {
	return dfs(root, 0);
}

int sumNumbers(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int sum = 0;
	struct TreeNode* nodeQueue[2000];
	int numQueue[2000];
	int leftQueue = 0, rightQueue = 0;
	nodeQueue[rightQueue] = root;
	numQueue[rightQueue++] = root->val;
	while (leftQueue < rightQueue) {
		struct TreeNode* node = nodeQueue[leftQueue];
		int num = numQueue[leftQueue++];
		struct TreeNode* left = node->left;
		struct TreeNode* right = node->right;
		if (left == NULL && right == NULL) {
			sum += num;
		}
		else {
			if (left != NULL) {
				nodeQueue[rightQueue] = left;
				numQueue[rightQueue++] = num * 10 + left->val;
			}
			if (right != NULL) {
				nodeQueue[rightQueue] = right;
				numQueue[rightQueue++] = num * 10 + right->val;
			}
		}
	}
	return sum;
}
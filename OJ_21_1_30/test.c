#define _CRT_SECURE_NO_WARNINGS 1

int height(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return fmax(height(root->left), height(root->right)) + 1;
	}
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL) {
		return true;
	}
	else {
		return fabs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
}


int height(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if (leftHeight == -1 || rightHeight == -1 || fabs(leftHeight - rightHeight) > 1) {
		return -1;
	}
	else {
		return fmax(leftHeight, rightHeight) + 1;
	}
}

bool isBalanced(struct TreeNode* root) {
	return height(root) >= 0;
}


int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	int** levelOrder = malloc(sizeof(int*) * 2001);
	*returnColumnSizes = malloc(sizeof(int) * 2001);
	*returnSize = 0;
	if (!root) {
		return levelOrder;
	}
	struct TreeNode** q = malloc(sizeof(struct TreeNode*) * 2001);
	int left = 0, right = 0;
	q[right++] = root;
	while (left < right) {
		int len = right - left;
		int* level = malloc(sizeof(int) * len);
		(*returnColumnSizes)[*returnSize] = len;
		for (int i = 0; i < len; ++i) {
			struct TreeNode* node = q[left++];
			level[i] = node->val;
			if (node->left != NULL) {
				q[right++] = node->left;
			}
			if (node->right != NULL) {
				q[right++] = node->right;
			}
		}
		levelOrder[(*returnSize)++] = level;
	}
	for (int i = 0; 2 * i < *returnSize; ++i) {
		int* tmp1 = levelOrder[i];
		levelOrder[i] = levelOrder[(*returnSize) - i - 1];
		levelOrder[(*returnSize) - i - 1] = tmp1;
		int tmp2 = (*returnColumnSizes)[i];
		(*returnColumnSizes)[i] = (*returnColumnSizes)[(*returnSize) - i - 1];
		(*returnColumnSizes)[(*returnSize) - i - 1] = tmp2;
	}
	return levelOrder;
}
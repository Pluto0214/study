#define _CRT_SECURE_NO_WARNINGS 1

int numofRoot(struct TreeNode* root)
{
	if (!root) return 0;
	return 1 + numofRoot(root->left) + numofRoot(root->right);
}

int kthSmallest(struct TreeNode* root, int k) {
	int cnt = numofRoot(root->left);

	if (k <= cnt) return kthSmallest(root->left, k);
	else if (k>cnt + 1) return kthSmallest(root->right, k - cnt - 1);
	return root->val;
}
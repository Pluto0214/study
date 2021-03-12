#define _CRT_SECURE_NO_WARNINGS 1
int isBSTUtil(struct TreeNode* node, long long min, long long max)
{
	/* 是一颗空树 */
	if (node == NULL)
		return 1;

	/* 结点的值小于等于最小值，或者大于等于最大值都是不合理的，返回false */
	if (node->val <= min || node->val >= max)
		return 0;

	/*否则递归地判断结点的左子树和右子树*/
	return
		isBSTUtil(node->left, min, node->val) &&
		isBSTUtil(node->right, node->val, max);
}

bool isValidBST(struct TreeNode* root) {
	return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

class Solution {
	bool isBSTUtil(struct TreeNode* root, long long& prev)
	{
		if (root) {
			if (!isBSTUtil(root->left, prev))
				return false;

			// 当前结点小于等于它的直接前驱顶点，返回false 
			if (root->val <= prev)
				return false;

			//初始化pre 为当前结点
			prev = root->val;

			return isBSTUtil(root->right, prev);
		}

		return true;
	}
public:
	bool isValidBST(TreeNode* root) {
		long long prev = LONG_MIN;
		return isBSTUtil(root, prev);
	}
};
#define _CRT_SECURE_NO_WARNINGS 1
int isBSTUtil(struct TreeNode* node, long long min, long long max)
{
	/* ��һ�ſ��� */
	if (node == NULL)
		return 1;

	/* ����ֵС�ڵ�����Сֵ�����ߴ��ڵ������ֵ���ǲ�����ģ�����false */
	if (node->val <= min || node->val >= max)
		return 0;

	/*����ݹ���жϽ�����������������*/
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

			// ��ǰ���С�ڵ�������ֱ��ǰ�����㣬����false 
			if (root->val <= prev)
				return false;

			//��ʼ��pre Ϊ��ǰ���
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
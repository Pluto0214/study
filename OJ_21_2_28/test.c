#define _CRT_SECURE_NO_WARNINGS 1

int minValueNode(struct TreeNode* node)
{
	struct TreeNode* current = node;

	/*��ɾ�������Һ��ӿ�ʼһֱ�����ߣ��ҵ���Сֵ*/
	while (current && current->left != NULL)
		current = current->left;

	return current->val;
}

/* ����ɾ��������������е�ֵ���Ľ��ָ�� */
int maxValueNode(struct TreeNode* node)
{
	struct TreeNode* current = node;

	/*��ɾ�������Һ��ӿ�ʼһֱ�����ߣ��ҵ���Сֵ*/
	while (current && current->right != NULL)
		current = current->right;

	return current->val;
}

bool isValidBST(struct TreeNode* root) {
	if (root == NULL) return true;
	if (root->left != NULL && maxValueNode(root->left) >= root->val) return false;
	if (root->right != NULL && minValueNode(root->right) <= root->val) return false;

	if (!isValidBST(root->left) || !isValidBST(root->right)) return false;

	return true;
}
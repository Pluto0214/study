#define _CRT_SECURE_NO_WARNINGS 1
void inorder(struct TreeNode* root, int* res, int* resSize) {
	if (!root) {
		return;
	}
	inorder(root->left, res, resSize);
	res[(*resSize)++] = root->val;
	inorder(root->right, res, resSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* res = malloc(sizeof(int) * 501);
	*returnSize = 0;
	inorder(root, res, returnSize);
	return res;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	int* res = malloc(sizeof(int) * 501);
	struct TreeNode** stk = malloc(sizeof(struct TreeNode*) * 501);
	int top = 0;
	while (root != NULL || top > 0) {
		while (root != NULL) {
			stk[top++] = root;
			root = root->left;
		}
		root = stk[--top];
		res[(*returnSize)++] = root->val;
		root = root->right;
	}
	return res;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* res = malloc(sizeof(int) * 501);
	*returnSize = 0;
	struct TreeNode* predecessor = NULL;

	while (root != NULL) {
		if (root->left != NULL) {
			// predecessor �ڵ���ǵ�ǰ root �ڵ�������һ����Ȼ��һֱ���������޷���Ϊֹ
			predecessor = root->left;
			while (predecessor->right != NULL && predecessor->right != root) {
				predecessor = predecessor->right;
			}

			// �� predecessor ����ָ��ָ�� root����������������
			if (predecessor->right == NULL) {
				predecessor->right = root;
				root = root->left;
			}
			// ˵���������Ѿ��������ˣ�������Ҫ�Ͽ�����
			else {
				res[(*returnSize)++] = root->val;
				predecessor->right = NULL;
				root = root->right;
			}
		}
		// ���û�����ӣ���ֱ�ӷ����Һ���
		else {
			res[(*returnSize)++] = root->val;
			root = root->right;
		}
	}
	return res;
}
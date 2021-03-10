#define _CRT_SECURE_NO_WARNINGS 1
int num;

void flatten(struct TreeNode* root) {
	num = 0;
	struct TreeNode** l = (struct TreeNode**)malloc(0);
	preorderTraversal(root, &l);
	for (int i = 1; i < num; i++) {
		struct TreeNode *prev = l[i - 1], *curr = l[i];
		prev->left = NULL;
		prev->right = curr;
	}
	free(l);
}

void preorderTraversal(struct TreeNode* root, struct TreeNode*** l) {
	if (root != NULL) {
		num++;
		(*l) = (struct TreeNode**)realloc((*l), sizeof(struct TreeNode*) * num);
		(*l)[num - 1] = root;
		preorderTraversal(root->left, l);
		preorderTraversal(root->right, l);
	}
}


void flatten(struct TreeNode* root) {
	struct TreeNode** stk = (struct TreeNode**)malloc(0);
	int stk_top = 0;
	struct TreeNode** vec = (struct TreeNode**)malloc(0);
	int vec_len = 0;
	struct TreeNode* node = root;
	while (node != NULL || stk_top != 0) {
		while (node != NULL) {
			vec_len++;
			vec = (struct TreeNode**)realloc(vec, sizeof(struct TreeNode*) * vec_len);
			vec[vec_len - 1] = node;
			stk_top++;
			stk = (struct TreeNode**)realloc(stk, sizeof(struct TreeNode*) * stk_top);
			stk[stk_top - 1] = node;
			node = node->left;
		}
		node = stk[--stk_top];
		node = node->right;
	}
	for (int i = 1; i < vec_len; i++) {
		struct TreeNode *prev = vec[i - 1], *curr = vec[i];
		prev->left = NULL;
		prev->right = curr;
	}
	free(stk);
	free(vec);
}
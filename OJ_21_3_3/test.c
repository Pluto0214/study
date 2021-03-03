#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 10000
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	if (root == NULL)
	{
		*returnSize = 0;
		return;
	}
	int** result = (int**)malloc(sizeof(int*) * MAXSIZE);
	*returnColumnSizes = (int*)malloc(sizeof(int) * MAXSIZE);

	struct TreeNode* queue[10000];   //以下三步为初始化队列
	int rear = -1, front = -1;
	queue[++rear] = root;

	int n = 0, level = 0;  //用于每层的统计结点个数
	while (front != rear)
	{
		n = (rear - front % MAXSIZE);
		(*returnColumnSizes)[level] = n;
		result[level] = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
		{
			struct TreeNode* p = queue[++front];
			result[level][i] = p->val;
			if (p->left != NULL)
				queue[++rear] = p->left;
			if (p->right != NULL)
				queue[++rear] = p->right;
		}
		level++;
	}
	*returnSize = level;
	return result;
}
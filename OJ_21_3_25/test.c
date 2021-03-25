#define _CRT_SECURE_NO_WARNINGS 1

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


#define MAX_RETURN_NUM 1000
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	// �����������
	int **ret = (int**)calloc(MAX_RETURN_NUM, sizeof(int*));
	*returnColumnSizes = (int*)calloc(MAX_RETURN_NUM, sizeof(int));
	*returnSize = 0;
	// ����ָ��ڵ��ָ����к���������
	struct TreeNode *queue[10000];
	int outIndex = 0;
	int inIndex = 0;
	// �ж��쳣���룬����whileѭ��֮ǰ��ʼ��
	if (root == NULL) { return NULL; }
	queue[inIndex++] = root;
	int levelcount = inIndex - outIndex;
	int count = 0;
	// BFS
	while (levelcount > 0) {
		count++;
		ret[*returnSize] = (int*)calloc(levelcount, sizeof(int));
		(*returnColumnSizes)[*returnSize] = levelcount;
		// ÿһ��Ķ���
		for (int i = 0; i < levelcount; i++) {
			if (queue[outIndex]->left != NULL) {
				queue[inIndex++] = queue[outIndex]->left;
			}
			if (queue[outIndex]->right != NULL) {
				queue[inIndex++] = queue[outIndex]->right;
			}
			ret[*returnSize][i] = queue[outIndex]->val;
			outIndex++;
		}
		// ������һ��֮ǰ�Ķ���
		(*returnSize)++;
		levelcount = inIndex - outIndex;
	}
	return ret;
}
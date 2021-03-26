#define _CRT_SECURE_NO_WARNINGS 1

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/

void preorder(struct TreeNode* root, int *returnArr, int height, int* returnSize) {
	if (!root) {
		return;
	}
	if (height + 1 > returnSize[0]) {
		returnSize[0] = height + 1;
	}
	returnArr[height] = root->val;
	preorder(root->left, returnArr, height + 1, returnSize);
	preorder(root->right, returnArr, height + 1, returnSize);
	return;
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
	int *returnArr = (int*)calloc(1000, sizeof(int));
	returnSize[0] = 0;
	preorder(root, returnArr, 0, returnSize);
	return returnArr;
}
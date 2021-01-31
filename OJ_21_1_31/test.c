#define _CRT_SECURE_NO_WARNINGS 1

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *head = NULL, *tail = NULL;
	int carry = 0;
	while (l1 || l2) {
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;
		if (!head) {
			head = tail = malloc(sizeof(struct ListNode));
			tail->val = sum % 10;
			tail->next = NULL;
		}
		else {
			tail->next = malloc(sizeof(struct ListNode));
			tail->next->val = sum % 10;
			tail = tail->next;
			tail->next = NULL;
		}
		carry = sum / 10;
		if (l1) {
			l1 = l1->next;
		}
		if (l2) {
			l2 = l2->next;
		}
	}
	if (carry > 0) {
		tail->next = malloc(sizeof(struct ListNode));
		tail->next->val = carry;
		tail->next->next = NULL;
	}
	return head;
}


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
#define MAXSIZE 101
int len = 0;

void get_array(struct TreeNode* root, int *array) {/*in order*/
	if (root == NULL)  return;
	get_array(root->left, array);
	array[len++] = root->val;
	get_array(root->right, array);
	//return ans;
}
int get_min(int *array) {
	int delta = 100000, temp;
	for (int i = 1; i<len; i++) {
		temp = (array[i]>array[i - 1] ? (array[i] - array[i - 1]) : (array[i - 1] - array[i]));
		if (delta>temp) {
			delta = temp;
		}
	}
	return delta;
}
int getMinimumDifference(struct TreeNode* root) {
	if (root == NULL)  return false;
	int *array[MAXSIZE] = { 0 };
	get_array(root, array);
	return get_min(array);
}

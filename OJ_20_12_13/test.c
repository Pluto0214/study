#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode* reverseList(struct ListNode* head) {
	typedef struct ListNode * PtrToLNode;
	PtrToLNode new_head, old_head, temp;

	old_head = head;		//初始化当前旧表头为head
	new_head = NULL;		//初始化逆转后新表头为空

	while (old_head) {	//当旧表头不为空时
		temp = old_head->next;
		old_head->next = new_head;
		new_head = old_head;
		old_head = temp;
	}
	head = new_head;		//更新head
	return head;
}


struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* p;
	struct ListNode* q;
	p = q = head;
	while (1)
	{
		if (p->next == NULL)
		{
			break;
		}
		else if (p->next->next == NULL)
		{
			q = q->next;
			break;
		}
		else
		{
			p = p->next->next;
			q = q->next;
		}
	}
	return q;
}

struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	while ((fast) && (fast->next)) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	while ((fast) && (fast->next))
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast && (fast->next))
	{
		slow = slow->next;
		fast = head->next->next;
	}
	return slow;
}


class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		//思路：?使用快慢指针，快指针一次走两步，慢指针一次走一步，慢指针找到中间结点。然后反转中间的后面
		//再从头尾向中间遍历，若都相等则是回文
		if (A == NULL)
			return true;
		ListNode* mid;
		ListNode* fast;
		ListNode* tmp;
		mid = A;
		fast = A;

		while (fast->next != NULL)
		{
			tmp = mid;
			mid = mid->next;
			fast = fast->next;
			//循环结束后当元素个数为奇数时，mid指向中间的元素，当元素个数为偶数时，mid指向后半部分元素的第一个元素
			if (fast->next != NULL)
				fast = fast->next;
		}
		if (mid == A)
			return true;  //链表元素个数为1时不执行循环
		ListNode* cur;
		tmp->next = NULL;
		cur = mid->next;
		mid->next = NULL;
		while (cur != NULL)
		{
			tmp = cur->next;//反转链表
			cur->next = mid;
			mid = cur;
			cur = tmp;
		}

		while (A != NULL && mid != NULL)
		{
			if (A->val == mid->val)
			{
				A = A->next;
				mid = mid->next;
			}
			else 
				return false;
		}
		return true;
	}
};


void rotate(int* nums, int numsSize, int k) {
	int i = 0;
	int tmp = 0;
	int j = 0;
	k %= numsSize;//只需要旋转小于numsSize的长度
	for (i = 0, j = numsSize - 1 - k; i<j; i++, j--)//对前半部分逆置
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = numsSize - k, j = numsSize - 1; i<j; i++, j--)//对后半部分逆置
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = 0, j = numsSize - 1; i<j; i++, j--)//对整体数组逆置
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}


	void rotate(int* nums, int numsSize, int k) {
		int i = 0;
		int j = 0;
		int tmp = 0;
		k %= numSize;//确保当k大于numSize时旋转的最大值时numSize
		//逆置第一部分
		for (i = 0, j = numSize - 1 - k; i < j; i++, j--)
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
		//逆置第二部分
		for (i = numSize - k, j = numSize - 1; i < j; i++, j--)
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
		//逆置整体
		for (i = 0, j = numSize - 1; i < j; i++, j--)
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
	}

    void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
		int tail = m + n - 1;
		m--, n--;
		while (m >= 0 && n >= 0) 
		{
			nums1[tail] = nums1[m] > nums2[n] ? nums1[m] : nums2[n];
			tail--, n--, m--;
		}
		while (n >= 0) {
			nums1[tail] = nums2[n];
			tail--, n--;
		}
	}

	void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
		int i, j;
		i = m - 1;
		j = n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] < nums2[j]) {
				nums1[i + j + 1] = nums2[j];
				j--;
			}
			else {
				nums1[i + j + 1] = nums1[i];
				i--;
			}
		}
		//处理一下nmus2中没有弄过去的
		while (j >= 0) {
			nums1[j] = nums2[j];
			j--;
		}
	}

	struct ListNode* removeElements(struct ListNode* head, int val) {
		struct ListNode* fast = head;
		struct ListNode* slow = head;
		while(fast)
		{
			if (fast != val)
			{
				slow = slow->next;
				fast = slow;
			}
			else
			{
				fast = fast->next;
			}
			return head;
	}

		struct ListNode* removeElements(struct ListNode* head, int val) {
			while (head != NULL && head->val == val) {
				head = head->next;
			}

			struct ListNode* cur = head;  //  当前节点
			struct ListNode* pre = head;  //  保存删除节点的前一节点
			while (cur != NULL) {
				if (cur->val == val) {
					pre->next = cur->next;
				}
				else {
					pre = cur;
				}
				cur = cur->next;
			}

			return head;
		}

		struct ListNode* removeElements(struct ListNode* head, int val) {
			//哨兵节点
			struct ListNode *sentinel = malloc(sizeof(struct ListNode));
			sentinel->next = head;
			struct ListNode *cur = head, *prev = sentinel;

			while (curr != NULL) 
			{
				if (curr->val == val) 
				{
					prev->next = curr->next;
				}
				else 
				{
					prev = curr;
				}
				curr = curr->next;
			}
			return sentinel->next;

		}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode* reverseList(struct ListNode* head) {
	typedef struct ListNode * PtrToLNode;
	PtrToLNode new_head, old_head, temp;

	old_head = head;		//��ʼ����ǰ�ɱ�ͷΪhead
	new_head = NULL;		//��ʼ����ת���±�ͷΪ��

	while (old_head) {	//���ɱ�ͷ��Ϊ��ʱ
		temp = old_head->next;
		old_head->next = new_head;
		new_head = old_head;
		old_head = temp;
	}
	head = new_head;		//����head
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
		//˼·��?ʹ�ÿ���ָ�룬��ָ��һ������������ָ��һ����һ������ָ���ҵ��м��㡣Ȼ��ת�м�ĺ���
		//�ٴ�ͷβ���м����������������ǻ���
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
			//ѭ��������Ԫ�ظ���Ϊ����ʱ��midָ���м��Ԫ�أ���Ԫ�ظ���Ϊż��ʱ��midָ���벿��Ԫ�صĵ�һ��Ԫ��
			if (fast->next != NULL)
				fast = fast->next;
		}
		if (mid == A)
			return true;  //����Ԫ�ظ���Ϊ1ʱ��ִ��ѭ��
		ListNode* cur;
		tmp->next = NULL;
		cur = mid->next;
		mid->next = NULL;
		while (cur != NULL)
		{
			tmp = cur->next;//��ת����
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
	k %= numsSize;//ֻ��Ҫ��תС��numsSize�ĳ���
	for (i = 0, j = numsSize - 1 - k; i<j; i++, j--)//��ǰ�벿������
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = numsSize - k, j = numsSize - 1; i<j; i++, j--)//�Ժ�벿������
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = 0, j = numsSize - 1; i<j; i++, j--)//��������������
	{
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}


	void rotate(int* nums, int numsSize, int k) {
		int i = 0;
		int j = 0;
		int tmp = 0;
		k %= numSize;//ȷ����k����numSizeʱ��ת�����ֵʱnumSize
		//���õ�һ����
		for (i = 0, j = numSize - 1 - k; i < j; i++, j--)
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
		//���õڶ�����
		for (i = numSize - k, j = numSize - 1; i < j; i++, j--)
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
		//��������
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
		//����һ��nmus2��û��Ū��ȥ��
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

			struct ListNode* cur = head;  //  ��ǰ�ڵ�
			struct ListNode* pre = head;  //  ����ɾ���ڵ��ǰһ�ڵ�
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
			//�ڱ��ڵ�
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
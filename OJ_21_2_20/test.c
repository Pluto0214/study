#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;

ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
	ListNode* tail = l2;
	while (tail->next) tail = tail->next;

	int n = a;
	ListNode* p = l1;
	while (--n) p = p->next;

	n = b - a + 2;  // n == (b + 1) - (a - 1) == b + 1 - a + 1 == b - a + 2;
	ListNode *q = p, *r = p->next;
	while (n--)
		q = q->next;

	// C������û����Javaһ�����������ջ���(garbage collection)������Ҫ�ֶ��ͷ�
	// ���ǣ����������ջ��ƶԳ���Ա����������˵�Ļ���һ������?
	while (r != q) {
		ListNode* nxt = r->next;
		r->next = NULL;
		free(r);
		r = nxt;
	}

	p->next = l2;
	tail->next = q;
	return l1;
}
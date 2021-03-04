#define _CRT_SECURE_NO_WARNINGS 1

struct Stack {
	struct ListNode* val;
	struct Stack* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* dummy = malloc(sizeof(struct ListNode));
	dummy->val = 0, dummy->next = head;
	struct Stack* stk = NULL;
	struct ListNode* cur = dummy;
	while (cur) {
		struct Stack* tmp = malloc(sizeof(struct Stack));
		tmp->val = cur, tmp->next = stk;
		stk = tmp;
		cur = cur->next;
	}
	for (int i = 0; i < n; ++i) {
		struct Stack* tmp = stk->next;
		free(stk);
		stk = tmp;
	}
	struct ListNode* prev = stk->val;
	prev->next = prev->next->next;
	struct ListNode* ans = dummy->next;
	free(dummy);
	return ans;
}
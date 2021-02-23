#define _CRT_SECURE_NO_WARNINGS 1

/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL)
			return NULL;
		Node *newHead = new Node(head->val);
		Node *srcNode = head, *destNode = newHead;
		map<Node*, Node*> m;
		while (srcNode->next != NULL) {//�Ȳ�����random��ָ�����⣬�Ƚ����������������nextָ������
			destNode->next = new Node(srcNode->next->val);
			m.insert(pair<Node*, Node*>(srcNode, destNode));
			//srcNode->val=*(int*)(void*)destNode;//��srcNode��val����ΪdestNode�ĵ�ַ
			destNode = destNode->next;
			srcNode = srcNode->next;
		}
		m.insert(pair<Node*, Node*>(srcNode, destNode));
		//srcNode->val=*(int*)(void*)destNode;

		destNode = newHead;
		srcNode = head;
		while (srcNode != NULL) {
			if (srcNode->random == NULL)
				destNode->random = NULL;
			else {
				auto iter = m.find(srcNode->random);
				destNode->random = iter->second;
				//destNode->random=(Node*)(void*)&(srcNode->random->val);//��val����ת��Ϊ��ַ
			}
			destNode = destNode->next;
			srcNode = srcNode->next;
		}
		return newHead;
	}
};
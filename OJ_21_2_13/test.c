#define _CRT_SECURE_NO_WARNINGS 1

//����˼·:��ȸ�k�����ӷ�N��ƻ������ƽ���֣��ٰѶ�Ĵ�ͷ�����(ʵ�ʲ���ʱ������������һ��ֵģ���ΪҪ����ԭ����˳���)
//1.�����ڴ�(ע���Ƕ�άָ��)[һ��������άָ�룬���д������ĸ�ʽ�����±���ʣ�output[i]��Ӧ���ǵ�i������ı�ͷ]
//2.��������õ�length,���mod-ƽ������������Ľ����,size-ÿ�����ֱ�Ӧ�еĽ����
//3.ѭ�� �ָ�����(ע���������:length<k,k�Ժ�Ĳ��ֶ�Ӧ��NULL)
//3�е�����:curSize�ļ���
//ע���:����һ�� *returnSize ������Ҫ��ֵ�� (��Ϊ����������ָ�룬ֱ�Ӹ�ֵ����)
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize) {
	struct ListNode** output = (struct ListNode**)malloc(k*sizeof(struct ListNode*)); //ע�������ڴ�ı��ʽ
	int length = 0;
	struct ListNode* cur = root;
	while (cur != NULL)
	{
		length++;
		cur = cur->next;
	}
	cur = root;                //�����������˰�ָ�����õ�����ͷ/
	int mod = length%k;
	int size = length / k;
	for (int i = 0; i<k; i++)
	{
		output[i] = cur;  //���i<k����cur==NULL  ��ô֤�����������(length<k) ֻ��cur(��NULL)��������Ԫ�� ����Ķ���ִ��
		if (cur != NULL)
		{
			int curSize = size + (mod-- >0 ? 1 : 0);            //����
			for (int j = 0; j<curSize - 1; j++) cur = cur->next;   //�ָ�����
			struct ListNode* next = cur->next;
			cur->next = NULL;
			cur = next;
		}
	}
	*returnSize = k;                //��Ŀ�е�һ������(���������������������)
	return output;
}
#define _CRT_SECURE_NO_WARNINGS 1

//总体思路:类比给k个孩子分N个苹果，先平均分，再把多的从头往后分(实际操作时，是两个部分一起分的，因为要按照原来的顺序分)
//1.申请内存(注意是二维指针)[一段连续二维指针，便可写成数组的格式，用下标访问，output[i]对应的是第i个链表的表头]
//2.遍历链表得到length,算出mod-平均分完后多出来的结点数,size-每个部分本应有的结点数
//3.循环 分割链表(注意特殊情况:length<k,k以后的部分都应是NULL)
//3中的亮点:curSize的计算
//注意点:还有一个 *returnSize 参数需要赋值。 (因为传进来的是指针，直接赋值即可)
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize) {
	struct ListNode** output = (struct ListNode**)malloc(k*sizeof(struct ListNode*)); //注意申请内存的表达式
	int length = 0;
	struct ListNode* cur = root;
	while (cur != NULL)
	{
		length++;
		cur = cur->next;
	}
	cur = root;                //遍历后不能忘了把指针重置到链表开头/
	int mod = length%k;
	int size = length / k;
	for (int i = 0; i<k; i++)
	{
		output[i] = cur;  //如果i<k但是cur==NULL  那么证明是特殊情况(length<k) 只将cur(即NULL)赋给数组元素 后面的都不执行
		if (cur != NULL)
		{
			int curSize = size + (mod-- >0 ? 1 : 0);            //亮点
			for (int j = 0; j<curSize - 1; j++) cur = cur->next;   //分割链表
			struct ListNode* next = cur->next;
			cur->next = NULL;
			cur = next;
		}
	}
	*returnSize = k;                //题目中的一个参数(用来返回链表个数？？？)
	return output;
}
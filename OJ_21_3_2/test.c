#define _CRT_SECURE_NO_WARNINGS 1

/*
* @lc app=leetcode.cn id=220 lang=c
*
* [220] �����ظ�Ԫ�� III
*/

// @lc code=start

typedef long long ll_t;

typedef struct _info_st
{
	ll_t num;
	int id;
}info_st;

int compare(const void *a, const void *b)
{
	if ((*(info_st *)a).num != (*(info_st *)b).num)
	{
		//return (*(info_st *)a).num - (*(info_st *)b).num;
		int res = (*(info_st *)a).num > (*(info_st *)b).num ? 1 :
			((*(info_st *)a).num == (*(info_st *)b).num ? 0 : -1);
		return res;
	}
	else
	{
		return (*(info_st *)a).id - (*(info_st *)b).id;
	}

}

// ���㷨˼·�����򡣽����鰴�մ�С��λ�ý��ж�����������Ȼ��˫ָ��Ƚ�
// ע�������߽磬��Ҫ��չΪlong long
// ע��qsortΪ�˴���߽��������Ҫʹ�ñȽ�����ת��Ϊ1,0,-1
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
	if (k <= 0 || t < 0)
	{
		return false;
	}

	info_st *info = (info_st *)calloc(numsSize, sizeof(info_st));

	for (int i = 0; i < numsSize; i++)
	{
		info[i].num = nums[i];
		info[i].id = i;
	}

	qsort(info, numsSize, sizeof(info_st), compare);

	int ll = 0, rr = 0;

	for (int i = 0; i < numsSize - 1; i++)
	{
		int rr = i + 1;

		while (rr < numsSize)
		{
			if (info[rr].num - info[i].num > t)
			{
				break;
			}

			//printf("[%d, %d]  - [%d, %d] = %ld\n", info[rr].num, info[rr].id, info[i].num, info[i].id, info[rr].num - info[i].num);

			if (abs(info[rr].id - info[i].id) <= k)
			{
				return true;
			}

			rr++;
		}
	}

	return false;
}


// @lc code=end


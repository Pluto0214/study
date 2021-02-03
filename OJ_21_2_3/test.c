#define _CRT_SECURE_NO_WARNINGS 1
int longestSubstring(char * s, int k) {
	int n = strlen(s), prefix[26][n + 1];
	memset(prefix, 0, sizeof(prefix));
	// 1. 预处理前缀和：方便计算区间内数字出现个数
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			prefix[j][i + 1] = prefix[j][i];
		}
		prefix[s[i] - 'a'][i + 1]++;
	}
	// 2. 统计区间 [start, end] 内满足 s[i] < k 进行划分区间递归
	int helper(int start, int end) {
		for (int i = start; i <= end; i++) {
			if (prefix[s[i] - 'a'][end + 1] - prefix[s[i] - 'a'][start] < k) {
				return fmax(helper(start, i - 1), helper(i + 1, end));
			}
		}
		return fmax(end - start + 1, 0);  // 证明 [start,end] 都满足 或 不存在区间
	}
	return helper(0, n - 1);
}

class Solution :
	def longestSubstring(self, s: str, k : int) -> int :
	n = len(s)
	# 1. 计算前缀和
	prefix = [[0] * (n + 1) for _ in range(26)]
	for i in range(n) :
		for j in range(26) :
			prefix[j][i + 1] = prefix[j][i]  # 把前一个抄过来先
			prefix[ord(s[i]) - 97][i + 1] += 1  # 注意下标
			# 2. 用栈实现后序遍历（因为本题答案是全局，因此可以迭代实现）
			stack, res = [(0, n - 1)], 0
			while stack:  # 枚举区间不存在则结束
				start, end = stack.pop()
				for i in range(start, end + 1) :
					if prefix[ord(s[i]) - 97][end + 1] - prefix[ord(s[i]) - 97][start] < k :
						stack.extend([(start, i - 1), (i + 1, end)])
						break
					else : # 如果没有 break 则证明[start, end] 区间满足条件则更新
						res = max(res, end - start + 1)
						return res
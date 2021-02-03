#define _CRT_SECURE_NO_WARNINGS 1
int longestSubstring(char * s, int k) {
	int n = strlen(s), prefix[26][n + 1];
	memset(prefix, 0, sizeof(prefix));
	// 1. Ԥ����ǰ׺�ͣ�����������������ֳ��ָ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			prefix[j][i + 1] = prefix[j][i];
		}
		prefix[s[i] - 'a'][i + 1]++;
	}
	// 2. ͳ������ [start, end] ������ s[i] < k ���л�������ݹ�
	int helper(int start, int end) {
		for (int i = start; i <= end; i++) {
			if (prefix[s[i] - 'a'][end + 1] - prefix[s[i] - 'a'][start] < k) {
				return fmax(helper(start, i - 1), helper(i + 1, end));
			}
		}
		return fmax(end - start + 1, 0);  // ֤�� [start,end] ������ �� ����������
	}
	return helper(0, n - 1);
}

class Solution :
	def longestSubstring(self, s: str, k : int) -> int :
	n = len(s)
	# 1. ����ǰ׺��
	prefix = [[0] * (n + 1) for _ in range(26)]
	for i in range(n) :
		for j in range(26) :
			prefix[j][i + 1] = prefix[j][i]  # ��ǰһ����������
			prefix[ord(s[i]) - 97][i + 1] += 1  # ע���±�
			# 2. ��ջʵ�ֺ����������Ϊ�������ȫ�֣���˿��Ե���ʵ�֣�
			stack, res = [(0, n - 1)], 0
			while stack:  # ö�����䲻���������
				start, end = stack.pop()
				for i in range(start, end + 1) :
					if prefix[ord(s[i]) - 97][end + 1] - prefix[ord(s[i]) - 97][start] < k :
						stack.extend([(start, i - 1), (i + 1, end)])
						break
					else : # ���û�� break ��֤��[start, end] �����������������
						res = max(res, end - start + 1)
						return res
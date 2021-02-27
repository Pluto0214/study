#define _CRT_SECURE_NO_WARNINGS 1
bool canConstruct(char * ransomNote, char * magazine) {
	int arr[2][26] = { 0 };
	int i = 0;
	if (strlen(magazine)<strlen(ransomNote)) 
	{
		return false;
	}
	for (i = 0; i<strlen(magazine); i++) 
	{
		arr[0][magazine[i] - 'a']++;
		if (i<strlen(ransomNote)) 
		{
			arr[1][ransomNote[i] - 'a']++;
		}
	}
	for (i = 0; i<26; i++) 
	{
		if (arr[0][i]<arr[1][i]) 
		{
			return false;
		}
	}
	return true;

}

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	long tmp = x;
	long y = 0;
	while (tmp) 
	{
		y = y * 10 + tmp % 10;
		tmp /= 10;
	}

	return x == y;
}

int lengthOfLastWord(char * s) {
	int end = strlen(s) - 1;
	int start = 0;
	int res = 0;
	while (end >= 0 && s[end] == ' ') 
	{
		end--;
	}
	start = end;
	while (start >= 0 && s[start] != ' ') 
	{
		start--;
	}
	res = end - start;
	return res;
}

int cmp(const void*a, const void*b) 
{
	return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* a, int n)
{
	if (a == NULL || n <= 0) 
	{
		return false;
	}
	qsort(a, n, sizeof(int), cmp);
	for (int i = 1; i < n; i++) 
	{
		if (a[i] == a[i - 1]) 
		{
			return true;
		}
	}
	return false;
}

bool isLongPressedName(char* name, char* typed) {
	int n = strlen(name), m = strlen(typed);
	int i = 0, j = 0;
	while (j < m) 
	{
		if (i < n && name[i] == typed[j]) 
		{
			i++;
			j++;
		}
		else if (j > 0 && typed[j] == typed[j - 1]) 
		{
			j++;
		}
		else 
		{
			return false;
		}
	}
	return i == n;


	char *reverseOnlyLetters(char *s)
	{
		if (s == NULL) 
		{
			return NULL;
		}
		int len = strlen(s);
		char *a = (char*)malloc(sizeof(char) * (len + 1));
		memcpy(a, s, sizeof(char) * (len + 1));
		int i = 0, j = len - 1;
		//首尾双指针往中间移
		while (i < j) 
		{ 
			while (i < j && !isalpha(a[i])) 
			{
				i++;
			}
			while (i < j && !isalpha(a[j])) 
			{
				j--;
			}
			if (i < j) 
			{
				char t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++, j--;
			}
		}
		return a;
	}


	int* sortArrayByParity(int* A, int ASize, int* returnSize) {
		int i, j, temp;
		for (i = 0; i < ASize; i++) 
		{
			if (A[i] % 2 == 0) 
				continue;
			else 
			{
				for (j = i; j < ASize - 1; j++) 
				{
					if (A[j + 1] % 2 == 0) 
					{
						temp = A[j + 1];
						A[j + 1] = A[i];
						A[i] = temp;
						break;
					}
				}
			}
		}
		*returnSize = ASize;
		return A;

		int pivotIndex(int* nums, int numsSize) {
			int total = 0;
			for (int i = 0; i < numsSize; ++i) 
			{
				total += nums[i];
			}
			int sum = 0;
			for (int i = 0; i < numsSize; ++i) 
			{
				if (2 * sum + nums[i] == total) 
				{
					return i;
				}
				sum += nums[i];
			}
			return -1;
		}

		
			int* plusOne(int* digits, int digitsSize, int* returnSize) {
			int *num = (int*)malloc(sizeof(int) * (digitsSize + 1));
			num[0] = 1;
			int i;
			for (i = digitsSize - 1; i >= 0; i--) 
			{
				if (digits[i] == 9)
					digits[i] = 0;
				else 
				{
					digits[i] += 1;
					break;
				}
			}
			*returnSize = (digits[0] == 0) ? (digitsSize + 1) : digitsSize;
			for (i = 0; i < digitsSize; i++) 
			{
				num[i + 1] = digits[i];
			}
			return (digits[0] == 0) ? num : digits;
		}


		
			//1.设max[3]保存前三大的值，初始化为LONG_MIN意为最小值
			//2.遍历数组找前三大的值
			//3.判断max[2]是否存在，若不存在直接返回max[0]

			int thirdMax(int* nums, int numsSize) {
				long max[3] = { LONG_MIN,LONG_MIN,LONG_MIN }; //max数组保存前三大的数字，依次递减
				for (int i = 0; i < numsSize; i++)
				{
					if (nums[i] > max[0]) //比最大值还大
					{
						max[2] = max[1];
						max[1] = max[0];
						max[0] = nums[i];
					}
					else if (nums[i] < max[0] && nums[i] > max[1])   //比第二大的值大
					{
						max[2] = max[1];
						max[1] = nums[i];
					}
					else  if (nums[i] < max[1] && nums[i] > max[2])  //比第三大的值大
					{
						max[2] = nums[i];
					}
				}
				if (max[2] != LONG_MIN)
					return max[2];
				return max[0];
			}



			int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
				for (int i = 0; i < numsSize; ++i) 
				{
					for (int j = i + 1; j < numsSize; ++j) 
					{
						if (nums[i] + nums[j] == target) 
						{
							int* ret = malloc(sizeof(int) * 2);
							ret[0] = i, ret[1] = j;
							*returnSize = 2;
							return ret;
						}
					}
				}
				*returnSize = 0;
				return NULL;
			}


			char * addBinary(char * a, char * b) {
				int length, length1 = strlen(a), length2 = strlen(b);
				int	sum = 0, i = length1 - 1, j = length2 - 1, k, num;
				if (length1 > length2)
				{
					length = length1 + 1;
				}
				else
				{
					length = length2 + 1;
				}
				char *c = (char *)malloc(sizeof(char)*(length + 1));
				c[0] = '0'; c[length] = '\0';
				k = length - 1;
				while (i>-1 || j>-1 || sum)
				{
					num = (i>-1 ? a[i] - '0' : 0) + (j>-1 ? b[j] - '0' : 0) + sum;
					sum = 0;
					if (num>1)
					{
						sum = 1;
						num -= 2;
					}
					c[k--] = num + '0';
					j--; i--;
				}
				if (c[0] == '0')
				{
					for (i = 0; i<length - 1; i++)
						c[i] = c[i + 1];
					c[length - 1] = '\0';
				}
				return c;
			}


			int myAtoi(char * str) 
			{
				// 去掉开头的空格
				while (*str == ' ')
					++str;

				// 记录正负
				int flag = 1;
				if (*str == '-') 
				{
					flag = -1;
					++str;
				}
				else if (*str == '+')
					++str;

				int ret = 0;
				int div = INT_MAX / 10;
				while (*str <= '9' && *str >= '0') 
				{
					int dig = *str - '0';
					if (ret < div || (ret == div && dig < 8)) 
					{
						ret = ret * 10 + dig;
						++str;
					}
					// 溢出，根据正负性返回值
					else
						return (flag == 1 ? INT_MAX : INT_MIN);
				}
				return flag * ret;
			}






			int binarySearch(int* nums, int numsSize, int target, bool lower) 
			{
				int left = 0, right = numsSize - 1, ans = numsSize;
				while (left <= right) 
				{
					int mid = (left + right) / 2;
					if (nums[mid] > target || (lower && nums[mid] >= target)) 
					{
						right = mid - 1;
						ans = mid;
					}
					else 
					{
						left = mid + 1;
					}
				}
				return ans;
			}

			int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
				int leftIdx = binarySearch(nums, numsSize, target, true);
				int rightIdx = binarySearch(nums, numsSize, target, false) - 1;
				int* ret = malloc(sizeof(int) * 2);
				*returnSize = 2;
				if (leftIdx <= rightIdx && rightIdx < numsSize && nums[leftIdx] == target && nums[rightIdx] == target) 
				{
					ret[0] = leftIdx, ret[1] = rightIdx;
					return ret;
				}
				ret[0] = -1, ret[1] = -1;
				return ret;
			}


			bool isPalindrome(char * s) {
				int h, r, i, j = 0, len = strlen(s);
				char *t = calloc(len + 1, 1);

				for (i = 0; i < len; i++) 
				{
					if (isalnum(s[i])) 
					{
						if (isupper(s[i]))
							t[j++] = s[i] + 32;
						else
							t[j++] = s[i];
					}
				}
				h = 0;
				r = strlen(t) - 1;
				while (h < r) 
				{
					if (t[h] != t[r])
					{
						return false;
					}
					h++;
					r--;
				}
				free(t);

				return true;
			}






			int compress(char *chars, int charsSize)
			{
				int start = 0, end = 0, k = 0, t, i, j;
				for (; start < charsSize; start++) 
				{
					if (start + 1 == charsSize || chars[start] != chars[start + 1]) 
					{
						chars[k++] = chars[end];
						if (start > end) 
						{            
							t = start - end + 1;
							i = k;              
							while (t > 0) 
							{  
								chars[k++] = t % 10 + '0';
								t /= 10;
							}
							for (j = 0; j < (k - i) / 2; j++) 
							{    
								char tmp = chars[i + j];
								chars[i + j] = chars[k - 1 - j];
								chars[k - 1 - j] = tmp;
							}
						}
						end = start + 1;
					}
				}
				return k;
			



				int cmp(const int* a, const int* b)
				{
					return *(int*)a - *(int*)b;
				}

				int findUnsortedSubarray(int* nums, int numsSize) {
					int *copy = (int*)malloc(sizeof(int) * numsSize);
					for (int i = 0; i < numsSize; i++) 
					{
						copy[i] = nums[i];
					}

					qsort(nums, numsSize, sizeof(int), cmp);

					int start = 0;
					int end = numsSize - 1;
					int find_start = 0;
					int i = 0;
					while (i < numsSize && nums[i] == copy[i]) 
					{
						i++;
						start++;
					}
					i = numsSize - 1;
					while (i >= 0 && nums[i] == copy[i]) 
					{
						i--;
						end--;
					}

					int ans = end - start + 1;
					if (ans < 0) 
					{
						ans = 0;
					}
					return ans;
				}




				int evalRPN(char ** tokens, int tokensSize) {
					int* pStack = (int*)malloc(tokensSize * sizeof(int));
					int top = -1;
					int row = 0;
					int left = 0;
					int right = 0;

					for (row = 0; row <= tokensSize - 1; row++)
					{
						if ('+' == tokens[row][0])
						{
							right = pStack[top--]; // pop
							left = pStack[top--]; // pop 
							pStack[++top] = left + right; // push
						}
						else if ('-' == tokens[row][0] && '\0' == tokens[row][1]) // 负数
						{
							right = pStack[top--]; // pop
							left = pStack[top--]; // pop 
							pStack[++top] = left - right; // push
						}
						else if ('*' == tokens[row][0])
						{
							right = pStack[top--]; // pop
							left = pStack[top--]; // pop
							pStack[++top] = left * right; // push
						}
						else if ('/' == tokens[row][0])
						{
							right = pStack[top--]; // pop
							left = pStack[top--]; // pop
							pStack[++top] = left / right; // push
						}
						else // number
						{
							pStack[++top] = atoi(tokens[row]); // push
						}
					}

					return pStack[top]; // peek
				}



				int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
					int** ans = malloc(sizeof(int*) * (1 << numsSize));
					*returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
					*returnSize = 1 << numsSize;
					int t[numsSize];
					for (int mask = 0; mask < (1 << numsSize); ++mask) 
					{
						int tSize = 0;
						for (int i = 0; i < numsSize; ++i) 
						{
							if (mask & (1 << i)) 
							{
								t[tSize++] = nums[i];
							}
						}
						int* tmp = malloc(sizeof(int) * tSize);
						memcpy(tmp, t, sizeof(int) * tSize);
						(*returnColumnSizes)[mask] = tSize;
						ans[mask] = tmp;
					}
					return ans;
				}











				const int dirs[4][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
				int rows, columns;

				int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) 
				{
					if (matrixSize == 0 || matrixColSize[0] == 0) 
					{
						return 0;
					}
					rows = matrixSize;
					columns = matrixColSize[0];

					int** memo = (int**)malloc(sizeof(int*) * rows);
					for (int i = 0; i < rows; i++) 
					{
						memo[i] = (int*)malloc(sizeof(int) * columns);
						memset(memo[i], 0, sizeof(int) * columns);
					}
					int ans = 0;
					for (int i = 0; i < rows; ++i) 
					{
						for (int j = 0; j < columns; ++j) 
						{
							ans = fmax(ans, dfs(matrix, i, j, memo));
						}
					}
					free(memo);
					return ans;
				}

				int dfs(int** matrix, int row, int column, int** memo) 
				{
					if (memo[row][column] != 0) 
					{
						return memo[row][column];
					}
					++memo[row][column];
					for (int i = 0; i < 4; ++i) 
					{
						int newRow = row + dirs[i][0], newColumn = column + dirs[i][1];
						if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]) 
						{
							memo[row][column] = fmax(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
						}
					}
					return memo[row][column];
				}




				
				// 从右到左 root - right - left 次序遍历
				void travel(struct TreeNode* root, int depth, int* returnSize, int* res) {
					if (root == NULL)
					{
						return;
					}
					if (depth > *returnSize) 
					{
						res[*returnSize] = root->val;
						*returnSize = depth;
					}
					// 遍历 右、左子树
					travel(root->right, depth + 1, returnSize, res);
					travel(root->left, depth + 1, returnSize, res);
				}

				int* rightSideView(struct TreeNode* root, int* returnSize) 
				{
					// 初始返回数组大小为0
					*returnSize = 0;
					int* res = (int*)malloc(sizeof(int) * 1000);
					// 初始深度应为1
					travel(root, 1, returnSize, res);
					return res;
				}
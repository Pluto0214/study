#include<iostream>
using namespace std;
//string的传统写法简单实现（不包含增删查改）

namespace zwh
{
	class string
	{
	public:
		//构造函数
		//构造函数注意有参和无参两种情况，这里直接用一个缺省值将两种情况合并
		string(char* str = "")
			:_str(new char[strlen(str)+1])//这里+1是为了把\0也拷贝进来
		{
			//构造函数开完空间还要把数据也拷过来
			strcpy(_str, str);
		}

		//析构函数,注意析构函数没有参数
		~string()
		{
			delete[] _str;
		}

		//拷贝构造函数 string s2(s1)
		string(const string& s)
			:_str(new char[strlen(s._str)+1])//_str是s2的 s._str是s1的
		{
			strcpy(_str, s._str);
		}

		//赋值运算符重载，注意赋值是两个已经存在了的对象
		//s1 = s3
		string& operator=(const string& s)
		{
			//防止自己给自己赋值的情况
			if (this != &s)
			{
				//注意s1是this，s3是s
				//先把s1之前的空间干掉，然后开一块跟s3一样的空间，然后再把s3的值拷贝给s1
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
				//为了支持连续拷贝，要注意返回值返回类型 string&
				return *this;
			}
		}

	private: 
		char* _str;
	};
}

int main()
{
	return 0;
}
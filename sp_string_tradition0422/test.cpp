#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//string的传统简单模拟实现（不包含增删查改）
namespace zwh
{
	class string
	{
	public:
		//构造函数
		string(const char* str = "")
		{
			if (str == nullptr)
			{
				assert(false);
				return;
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		//析构函数
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}

		//拷贝构造函数
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		//赋值运算符重载 s1=s3
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[]_str;
				new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
			
		}
	private:
		char* _str;
	};
}
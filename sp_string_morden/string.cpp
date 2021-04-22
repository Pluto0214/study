#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

//string现代的简单模拟实现
//与传统写法不一样的地方主要体现在拷贝构造函数和赋值运算符重载
namespace zwh
{
	class string
	{
	public:
		//构造函数
		string(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//析构函数
		~string()
		{
			delete[]_str;
			_str = nullptr;
		}

		//拷贝构造函数s1(s2）
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//赋值运算符重载
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}
		/*string& operator=(const string& s)
		{
			swap(_str, s._str);
			return *this;
		}*/

	private:
		char* _str;

	};
}
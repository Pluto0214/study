#include<iostream>
using namespace std;

//string的简单模拟实现 现代写法
namespace zwh
{
	class string
	{
	public:
		//构造函数
		string(const char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}

		//析构函数
		~string()
		{
			delete[] _str;
		}

		//拷贝构造函数
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
		/*string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}*/
	private:
		char* _str;
	};
}
int main()
{
	return 0;
}
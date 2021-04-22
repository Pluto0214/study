#include<iostream>
#include<string>
using namespace std;

namespace zwh
{
	class string
	{
	public:
		//构造函数
		string(char* str = "/0")//"/0"是为了无参的情况或者"" 这样也可以，空字符串里面也有一个\0
			:_str(new char[strlen(str)+1])//+1是为了把/0也拷过来
		{
			strcpy(_str, str);
		}

		//operator[]
		char& operator[](size_t i)
		{
			return _str[i];
		}

		//析构函数
		~string()
		{
			delete[] _str;
		}

		//拷贝构造函数string s2(s1)
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		//s1 = s3
		string& operator=(const string& s)
		{
			delete[]_str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			return *this;
		}
		
	private:
		char* _str;
	};
}

int main()
{
	zwh::string s1("hello");

	return 0;
}
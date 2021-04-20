#include<iostream>
#include<string>
using namespace std;

namespace zwh
{
	class string
	{
	public:
		//���캯��
		string(char* str = "/0")//"/0"��Ϊ���޲ε��������"" ����Ҳ���ԣ����ַ�������Ҳ��һ��\0
			:_str(new char[strlen(str)+1])//+1��Ϊ�˰�/0Ҳ������
		{
			strcpy(_str, str);
		}

		//operator[]
		char& operator[](size_t i)
		{
			return _str[i];
		}

		//��������
		~string()
		{
			delete[] _str;
		}

		//�������캯��string s2(s1)
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
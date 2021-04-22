#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//string�Ĵ�ͳ��ģ��ʵ�֣���������ɾ��ģ�
namespace zwh
{
	class string
	{
	public:
		//���캯��
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

		//��������
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}

		//�������캯��
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		//��ֵ��������� s1=s3
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
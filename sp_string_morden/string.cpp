#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

//string�ִ��ļ�ģ��ʵ��
//�봫ͳд����һ���ĵط���Ҫ�����ڿ������캯���͸�ֵ���������
namespace zwh
{
	class string
	{
	public:
		//���캯��
		string(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//��������
		~string()
		{
			delete[]_str;
			_str = nullptr;
		}

		//�������캯��s1(s2��
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//��ֵ���������
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
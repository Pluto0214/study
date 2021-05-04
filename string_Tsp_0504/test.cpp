#include<iostream>
using namespace std;
//string�Ĵ�ͳд����ʵ�֣���������ɾ��ģ�

namespace zwh
{
	class string
	{
	public:
		//���캯��
		//���캯��ע���вκ��޲��������������ֱ����һ��ȱʡֵ����������ϲ�
		string(char* str = "")
			:_str(new char[strlen(str)+1])//����+1��Ϊ�˰�\0Ҳ��������
		{
			//���캯������ռ仹Ҫ������Ҳ������
			strcpy(_str, str);
		}

		//��������,ע����������û�в���
		~string()
		{
			delete[] _str;
		}

		//�������캯�� string s2(s1)
		string(const string& s)
			:_str(new char[strlen(s._str)+1])//_str��s2�� s._str��s1��
		{
			strcpy(_str, s._str);
		}

		//��ֵ��������أ�ע�⸳ֵ�������Ѿ������˵Ķ���
		//s1 = s3
		string& operator=(const string& s)
		{
			//��ֹ�Լ����Լ���ֵ�����
			if (this != &s)
			{
				//ע��s1��this��s3��s
				//�Ȱ�s1֮ǰ�Ŀռ�ɵ���Ȼ��һ���s3һ���Ŀռ䣬Ȼ���ٰ�s3��ֵ������s1
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
				//Ϊ��֧������������Ҫע�ⷵ��ֵ�������� string&
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
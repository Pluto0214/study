#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int main()
{
	char str[50], *pstr;
	int i, j, k, m, e10, digit, ndigit, a[10], *pa;
	cout << "请输入:" << endl;
	gets_s(str);
	cout << endl;
	pstr = &str[0];
	pa = &a[0];
	ndigit = 0;
	i = 0;
	j = 0;
	while (*(pstr + i) != '\0')
	{
		if ((*(pstr + i) >= '0') && (*(pstr + i) <= '9'))
			j++;
		else
		{
			if (j > 0)
			{
				digit = *(pstr + i - 1) - 48;
				k = 1;
				while (k < j)
				{
					e10 = 1;
					for (m = 1; m <= k; m++)
						e10 = e10 * 10;
					digit = digit + (*(pstr + i - 1 - k) - 48) * e10;
					k++;
				}
				*pa = digit;
				ndigit++;
				pa++;
				j = 0;
			}
		}
		i++;
	}
	if (j > 0)
	{
		digit = *(pstr + i - 1) - 48;
		k = 1;
		while (k < j)
		{
			e10 = 1;
			for (m = 1; m <= k; m++)
				e10 = e10 * 10;
			digit = digit + (*(pstr + i - 1 - k) - 48) * e10;
			k++;
		}
		*pa = digit;
		ndigit++;
		j = 0;
	}
	cout << "这一行有数字" << ndigit << "个，数字是；" << endl;
	j = 0;
	pa = &a[0];
	for (j = 0; j < ndigit; j++)
		cout << *(pa + j) << endl;
	cout << endl;
	return 0;
}








using namespace std;
class Teacher
{
public:
	Teacher(const char* name, int a, const char* t) 
	{
		m_name = new char[strlen(name) + 1];
		strcpy_s(m_name, strlen(name) + 1, name);
		m_title = new char[strlen(t) + 1];
		strcpy_s(m_title, strlen(t) + 1, t);
		m_age = a;
	}
	void display() 
	{
		cout << "name;" << this->m_name << endl;
		cout << "age" << this->m_age << endl;
		cout << "title" << this->m_title << endl;

	}
	~Teacher() 
	{
		if (m_name != NULL) 
		{
			delete[]m_name;
			m_name = NULL;
		}
		if (m_title != NULL) 
		{
			delete[]m_title;
			m_title = NULL;
		}
	}

	char* m_name;
	int m_age;
	char* m_title;
};
class student 
{
public:
	student(const char name[], char s, float sco) :sex(s), score(sco)
	{
		name1 = new char[strlen(name) + 1];
		strcpy_s(name1, strlen(name) + 1, name);

	}
	void display() 
	{
		cout << "name;" << this->name1 << endl;
		cout << "sex" << this->sex << endl;
		cout << "score" << this->score << endl;

	}
	~student()
	{
		if (name1 != NULL) 
		{
			delete[]name1;
			name1 = NULL;
		}
	}
	char* name1;
	char sex;
	float score;
};
class graduate :public Teacher, public student 
{
public:
	graduate(const char* name, int a, char s, const char* t, float sco, float w) :
		Teacher(name, a, t), student(name, s, sco), wage(w) {}
	void show() 
	{
		cout << "name;      " << this->m_name << endl;
		cout << "age;       " << this->m_age << endl;
		cout << "title;     " << this->m_title << endl;
		cout << "sex;       " << this->sex << endl;
		cout << "score;     " << this->score << endl;
		cout << "wages;     " << this->wage << endl;
	}
private:
	float wage;
};
int main() 
{
	graduate gard("Tony", 22, 'm', "head", 89, 9800);
	gard.show();
	return 0;
}

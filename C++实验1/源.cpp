#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
class Teacher
{
public:
	Teacher(string name, int age, char sex, string d, string  p, string title)
		:m_name(name), m_age(age), m_sex(sex), m_d(d), phone(p), m_title(title) {}
	void display()
	{
		cout << "����:" << m_name << endl;
		cout << "����:" << m_age << endl;
		cout << "�Ա�:" << m_sex << endl;
		cout << "��ַ��" << m_d << endl;
		cout << "�绰���룺" << phone << endl;
		cout << "ְ�ƣ�" << m_title << endl;
	}
protected:
	string m_name;
	int m_age;
	char m_sex;
	string m_d;
	string phone;
	string m_title;
};
class Cadre
{
public:
	Cadre(string name, int age, char sex, string d, string  p, string post)
		:m_name(name), m_age(age), m_sex(sex), m_d(d), phone(p), m_post(post) {}
protected:
	string m_name;
	int m_age;
	char m_sex;
	string m_d;
	string phone;
	string m_post;
};
class Teacher_Cadre :public Teacher, Cadre
{
public:
	Teacher_Cadre(float wage)
		:m_wage(wage), Teacher("xiaoming", 25, 'm', "����", "123456789", "��ʦ"),
		Cadre("xiaoming", 25, 'm', "����", "123456789", "assitant") {}
	void show();

	float m_wage;
};
void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "ְ��" << m_post << endl;
	cout << "���ʣ�" << m_wage << endl;
}
int main()
{
	Teacher_Cadre c1(5000);
	c1.show();
}

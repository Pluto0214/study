#include<iostream>
using namespace std;

class Person
{
public:
	string _name; // ����
};

class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};

class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};
void Test()
{
	Assistant a;
	a._name = "peter";
}

class A
{
public:
	int _a;
};
 /*class B : public A*/
class B : virtual public A
{
public:
	int _b;
};
 //class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	cout << sizeof(d) << endl;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}

//class Person
//{
//public:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a._name = "peter";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//class Person
//{
//public :
//	Person(const char* name = "����")
//		: _name(name)
//	{
//		/*cout << "Person()" << endl;*/
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		/*cout << "Person(const Person& p)" << endl;*/
//	}
//	Person& operator=(const Person& p)
//	{
//		/*cout << "Person operator=(const Person& p)" << endl;*/
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; 
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name = "����", int num = 1)
//		: Person(name)
//		, _num(num)
//	{
//		/*cout << "Student()" << endl;*/
//	}
//	Student(const Student& s)
//		: Person(s)
//		, _num(s._num)
//	{
//		/*cout << "Student(const Student& s)" << endl;*/
//	}
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		Person::~Person();
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; 
//};
//int main()
//{
//	Student s1;
//	return 0;
//}

//���캯������
//class Person
//{
//public:
//	Person(const char* name )
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//protected:
//	string _name;
//};
//class Student : public Person
//{
//public:
//	Student(const char* name = "����",int num = 1)
//		:Person(name)
//		,_num(num)
//	{}
//protected:
//	int _num;
//};




//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//};

//class Person
//{
//protected:
//	string _name = "peter";//ע�����ﲻ�ǳ�ʼ������ʼ�����ڶ���ĵط����У�������ֻ��������������ȱʡֵ��
//	int _age = 20;
//};
//
//class Student : public Person
//{
//protected:
//	int _grade;//�꼶
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid;//����
//};
//
//int main()
//{
//
//	return 0;
//}
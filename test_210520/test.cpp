#include<iostream>
using namespace std;

class Person
{
public:
	string _name; // 姓名
};

class Student : virtual public Person
{
protected:
	int _num; //学号
};

class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
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
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//class Person
//{
//public :
//	Person(const char* name = "张三")
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
//	Student(const char* name = "张三", int num = 1)
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

//构造函数举例
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
//	Student(const char* name = "李四",int num = 1)
//		:Person(name)
//		,_num(num)
//	{}
//protected:
//	int _num;
//};




//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
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
//	string _name = "peter";//注意这里不是初始化，初始化是在定义的地方进行，而这里只是声明。这里是缺省值。
//	int _age = 20;
//};
//
//class Student : public Person
//{
//protected:
//	int _grade;//年级
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid;//工号
//};
//
//int main()
//{
//
//	return 0;
//}
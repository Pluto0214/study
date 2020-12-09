#define _CRT_SECURE_NO_WARNINGS 1


#include<fstream>
#include<iostream>
using namespace std;
void main()
{
	ifstream sfile("E:\\e_text_w\\read.txt");
	ofstream dfile("E:\\e_text_w\\write.txt");
	char ch;
	if (!sfile)
	{
		cout << "不能打开源文件:" << "e:\\e_text_w\\read.cpp" << endl;
		exit(1);
	}
	else
	{
		cout << "已执行" << endl;
	}
	sfile.unsetf(ios::skipws);
	while (sfile >> ch)
		dfile << ch;
	sfile.close();
	dfile.close();
}







#include<iostream>
using namespace std;
#include<string>
class person
{
public:
	person(string nam, char s, int a)
	{
		name = nam;
		sex = s;
		age = a;
	}
protected:
	string name;
	char sex;
	int age;
};
class teather :virtual public person
{
public:
	teather(string nam, char s, int a, string t) :person(nam, s, a)
	{
		title = t;
	}
protected:
	string title;
};
class student :virtual public person
{
public:
	student(string nam, char s, int a, float sco) :person(nam, s, a), score(sco) {}
protected:
	float score;
};
class graduate :public teather, public student
{
public:
	graduate(string nam, char s, int a, string t, float sco, float w) :person(nam, s, a), teather(nam, s, a, t), student(nam, s, a, sco), wage(w) {}
	void show()
	{
		cout << "name:" << name << endl;
		cout << "age:" << age << endl;
		cout << "sex:" << sex << endl;
		cout << "score:" << score << endl;
		cout << "title:" << title << endl;
		cout << "wage:" << wage << endl;
	}
private:
	float wage;
};
int main()
{
	graduate a("xiaoming", 'm', 20, "assistant", 92.5, 5000);
	a.show();
	return 0;
}

//#include<iostream>
//#include<math.h>
//using namespace std;
//bool isleapyear(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0)
//	{
//		return true;
//	}
//	else if (year % 100 == 0 && year % 400 == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//int setyearday(int year, int month, int day)
//{
//	int yearday = 0;
//	int n = 0;
//	n = round(month / 2);
//	if (month > 2)
//	{
//		if (isleapyear)
//		{
//			yearday = (month - 1) * 30 + n - 1 + day;
//		}
//		else
//		{
//			yearday = (month - 1) * 30 + n - 2 + day;
//		}
//	}
//	else
//	{
//		yearday = day + 31;
//	}
//	return yearday;
//}
//
//void test()
//{
//	int year = 0;
//	int sum = 0;
//	int day = 0;
//	int month = 0;
//	cout << "请输入年份:" << endl;
//	cin >> year;
//	cout << "请输入月份;" << endl;
//	cin >> month;
//	cout << "请输入日期:" << endl;
//	cin >> day;
//	for (int i = year - 1; i > 0; i--)
//	{
//		if (isleapyear(i))
//		{
//			sum = 366 + sum;
//		}
//		else
//		{
//			sum = 365 + sum;
//		}
//	}
//	sum = setyearday(year, month, day) + sum;
//	cout << "距离0年0月0日一共：" << sum << "：天" << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<string>
//class student
//{
//public:
//	student(int num, float score, int age) :M_num(num), M_score(score), M_age(age) {}
//
//	void total()
//	{
//		sum += M_score;
//		count++;
//	}
//	static float average()
//	{
//		return (sum / count);
//	}
//
//	int  M_num;
//	int M_age;
//	float M_score;
//	static float sum;
//	static int count;
//};
//float student::sum = 0;
//int student::count = 0;
//void test()
//{
//	int n = 0;
//	student std[5] =
//	{
//		student(200,90,19),
//		student(201,94,19),
//		student(202,93,19),
//		student(203,91,19),
//		student(204,85,19)
//	};
//	cout << "请输入前多少名学生平均成绩:" << endl;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		std[i].total();
//	}
//	cout << "前" << n << "名学生的成绩是;" << student::average() << endl;
//}
//int main() {
//	test();
//	return 0;
//}

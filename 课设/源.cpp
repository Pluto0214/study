#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
#include<stdio.h>
#define M 100

using namespace std;
FILE *fpw = NULL;//定义文件，用于存储所有输入的学生信息
				 //cout<<"请输入您的总数据个数:"；
				 //cin<<a;
typedef struct stu
{
	char name[20];//姓名
	char sex[10];//性别
	char num[10];//学号,设置成字符类型，学号是一个整体
	int score[7];//语文，英语，数学，物理，化学，生物，平时成绩
	int ave;//平均分
	int total;//总分
}STU;


class Student
{
public:
	Student();
	void input();//数据输入
	void print();//输出
	void output(char curse[], int t);//文件
	void look();//浏览
	void find();//查找
	void Delete();//删除
	void design();//修改
	friend ostream &operator<<(ostream &os, STU &stu);//输出运算符重载
	friend istream &operator >> (istream &is, STU &stu);//输入运算符重载
private:
	STU stu;
};
Student s[M];//100个学生对象
Student::Student()//构造函数不能带参数，要不定义类对象的时候不知道赋什么
{
	for (int i = 0; i<M; i++)
	{
		strcpy(s[i].stu.name, " ");
		strcpy(s[i].stu.sex, " ");
		strcpy(s[i].stu.num, " ");
		s[i].stu.total = 0;
		s[i].stu.ave = 0;
		for (int j = 0; j<7; j++)
		{
			s[i].stu.score[j] = 0;
		}
	}
}
void Student::input()//学生成绩录入函数
{
	char ju = 'Y';
	int i = 0;
	cout << "请输入学生信息：" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "姓名  性别   学号   语文  英语  数学  物理  化学  生物  平时分 " << endl;
	cout << "----------------------------------------------------------------" << endl;
	while (ju == 'Y' || ju == 'y')
	{
		int sum = 0;
		cin >> s[i].stu;
		for (int j = 0; j<6; j++)
		{
			sum = sum + s[i].stu.score[j];
		}
		s[i].stu.ave = (int)(sum / 6);
		s[i].stu.total = (int)(0.3*s[i].stu.score[6] + 0.7*s[i].stu.ave);
		i++;
		cout << "继续请输入'Y'或'y',否则请输入任意字符" << endl;
		cin >> ju;
	}
}
void Student::output(char curse[], int t)//文件保存函数
{
	char a[50] = "C:\\Users\\Asus\\Desktop\\吴灿", b[5] = ".txt";
	strcat(curse, b);
	strcat(a, curse);
	//cin>>a;
	fpw = fopen(a, "w");
	if (fpw == NULL)
		cout << "文件无法打开" << endl;
	else
	{

		for (int i = 0; i<M; i++)
		{
			if (s[i].stu.num[6] == curse[1])
			{
				fputs(s[i].stu.name, fpw);//姓名
				fputs("  ", fpw);//空格
				fputs(s[i].stu.sex, fpw);//性别
				fputs("   ", fpw);//空格
				fputs(s[i].stu.num, fpw);//学号
				fputs("   ", fpw);//空格
				fprintf(fpw, "%d\n", s[i].stu.score[t]);//单科成绩
			}
		}
		fclose(fpw);//关闭文件
		cout << "文件保存成功" << endl;
	}
}
void Student::look()//调用文件保存函数
{
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有数据可以使用" << endl;
	else
	{
		char curse[20], cu[8];
		int t;
		cout << "请输入您要查看的班级代码及科目,如1班语文则输入c1yuwen:" << endl;
		cin >> curse;
		for (int i = 0; i<8; i++)
		{
			cu[i] = curse[i + 2];
		}
		if (strcmp(cu, "yuwen") == 0)
		{
			t = 0;
			output(curse, t);
		}
		if (strcmp(cu, "yingyu") == 0)
		{
			t = 1;
			output(curse, t);
		}
		if (strcmp(cu, "shuxue") == 0)
		{
			t = 2;
			output(curse, t);
		}
		if (strcmp(cu, "wuli") == 0)
		{
			t = 3;
			output(curse, t);
		}
		if (strcmp(cu, "huaxue") == 0)
		{
			t = 4;
			output(curse, t);
		}
		if (strcmp(cu, "shengwu") == 0)
		{
			t = 5;
			output(curse, t);
		}
	}
}
void Student::find()
{
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有数据可以使用" << endl;
	else
	{
		char na[10], b = 'Y';
		int t, k;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "姓名  性别   学号   语文  英语  数学  物理  化学  生物  平时分  总评 " << endl;
		cout << "----------------------------------------------------------------------" << endl;
		while (b == 'Y' || b == 'y')
		{
			cout << "请输入您要查找的学生的姓名:" << endl;
			cin >> na;//输入要查找的学生的姓名
			for (int i = 0; i<M; i++)
			{
				if (strcmp(s[i].stu.name, na) == 0)
				{
					t = 1;
					k = i;
					break;
				}
				else
					t = 0;
			}
			if (t == 1)
				cout << s[k].stu;
			if (t == 0)
				cout << "学生信息中没有您要查找的同学" << endl;
			cout << "是否继续进行查找,如是，请输入'Y'或'y',否则请输入任意字符" << endl;
			cin >> b;
		}
	}
}
void Student::design()//学生成绩修改函数
{
	int sum = 0;
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有数据可以使用" << endl;
	else
	{
		char a[10], n = 'Y';
		int  t, k;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "姓名  性别   学号   语文  英语  数学  物理  化学  生物  平时分  总评 " << endl;
		cout << "--------------------------------------------------------------------" << endl;
		while (n == 'Y' || n == 'y')
		{
			cout << "请输入需要修改成绩的学生姓名：" << endl;
			cin >> a;
			for (int i = 0; i<M; i++)
			{
				if (strcmp(s[i].stu.name, a) == 0)
				{
					t = 1;
					k = i;
					break;
				}
				else
					t = 0;
			}
			if (t == 1)
				cout << s[k].stu << endl;
			if (t == 0)
				cout << "学生信息中没有此同学";
			if (t == 1)
			{
				cout << "请输入修改后该学生的姓名：" << endl;
				cin >> a;
				strcpy(s[k].stu.name, a);
				cout << "请输入修改后该学生的性别：" << endl;
				cin >> a;
				strcpy(s[k].stu.sex, a);
				cout << "请输入修改后该学生的学号：" << endl;
				cin >> a;
				strcpy(s[k].stu.num, a);
				cout << "请按顺序输入修改后该学生的各项成绩：" << endl;
				for (int i = 0; i<7; i++)
				{
					cin >> s[k].stu.score[i];
				}
				for (int j = 0; j<6; j++)
				{
					sum = sum + s[k].stu.score[j];
				}
				s[k].stu.ave = (int)(sum / 6);
				s[k].stu.total = (int)(0.3*s[k].stu.score[6] + 0.7*s[k].stu.ave);
				cout << "修改完成" << endl;
				cout << "修改后信息" << endl;
				cout << s[k].stu;
			}
			cout << "是否继续进行修改,如是，请输入'Y'或'y'，如否，请输入任意字符" << endl;
			cin >> n;
		}
	}
}


ostream &operator<<(ostream &os, STU &stu)//输出运算符重载
{
	os << stu.name << "  " << stu.sex << "   " << stu.num << "   " << stu.score[0] << "    " << stu.score[1] << "    " << stu.score[2] << "    " << stu.score[3] << "    " << stu.score[4] << "    " << stu.score[5] << "    " << stu.score[6] << "    " << stu.total << endl;
	return os;
}


istream &operator >> (istream &is, STU &stu)//输入运算符重载
{
	is >> stu.name >> stu.sex >> stu.num >> stu.score[0] >> stu.score[1] >> stu.score[2] >> stu.score[3] >> stu.score[4] >> stu.score[5] >> stu.score[6];
	return is;
}
void Student::Delete()//学生信息删除函数
{
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有数据可以使用" << endl;
	else
	{
		char na[10];
		char q = 'Y';
		while (q == 'Y' || q == 'y')
		{
			cout << "请输入需要删除的同学的姓名：";
			cin >> na;
			for (int i = 0; i<M; i++)
			{
				if (strcmp(s[i].stu.name, na) == 0)//判断是否相等
				{
					for (int j = i; j<M - 1; j++)
					{
						strcpy(s[j].stu.name, s[j + 1].stu.name);//用后一个将需要删除的进行覆盖
						strcpy(s[j].stu.sex, s[j + 1].stu.sex);
						strcpy(s[j].stu.num, s[j + 1].stu.num);
						s[j].stu.total = s[j + 1].stu.total;
						for (int k = 0; k<7; k++)
						{
							s[j].stu.score[k] = s[j + 1].stu.score[k];
						}

					}
					break;
				}
				else
					cout << "没有该学生" << endl;
			}
			cout << "删除完成" << endl;
			cout << "是否继续进行删除操作，如是，请输入'Y'或'y';如否，请输入‘N’或'n'" << endl;
			cin >> q;
		}
		cout << "删除后的学生信息表为：" << endl;
		print();
	}
}
void Student::print()
{
	int t = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "姓名  性别   学号   语文  英语  数学  物理  化学  生物  平时分  总评 " << endl;
	cout << "----------------------------------------------------------------------" << endl;
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "没有数据可以使用" << endl;
	else
	{
		for (int i = 0; i<M; i++)
		{
			if (strcmp(s[i].stu.name, " ") != 0)
			{
				cout << s[i].stu;
			}
		}
		cout << "输出完成" << endl;
	}
}
void headline()
{
	cout << "\n\n\n\t\t   【学生成绩管理系统主菜单】" << endl;
	cout << "\t\t\t1.学生成绩录入" << endl;
	cout << "\t\t\t2.浏览学生成绩" << endl;
	cout << "\t\t\t3.查询学生成绩" << endl;
	cout << "\t\t\t4.修改学生成绩" << endl;
	cout << "\t\t\t5.删除学生成绩" << endl;
	cout << "\t\t\t6.数据存入文件" << endl;
	cout << "\t\t\t7.文件读出数据" << endl;
	cout << "\t\t\t0.退出系统" << endl;
	cout << "\n\t*请输入一位数字(1 - 7)选择您所需的功能，并按回车键确认【退出请输0】:";
}
void main()
{
	Student su;
	headline();
	char x = 'Y';
	int select;
	while (x == 'Y' || x == 'y')
	{
		system("cls");
		headline();
		cout << "请选择您要进行的操作:" << endl;
		cin >> select;
		switch (select)
		{
		case 0:break;
		case 1:su.input(); break;
		case 2:su.print(); break;
		case 3:su.find(); break;
		case 4:su.design(); break;
		case 5:su.Delete(); break;
		case 6:su.look(); break;
		default:cout << "error"; break;
		}
		cout << "是否继续进行其他操作，如是请输入'Y'或'y'，否则请输入任意字母" << endl;
		cin >> x;
	}
}
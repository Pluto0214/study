#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;

class student
{
private:
	char name[20];
	char sex[6];
	int number;
	int score[7];
	int total;
	int average;
	int last;
public:
	student();
	void add();
	void output();
	void find();
	void modify();
	void deleted();
	void save();
	void load();
	student&operator=(student& T);
	friend istream& operator >> (istream & scin, student &s1);
	friend ostream& operator << (ostream & scout, student &s2);
};


student stu[200];
int n = 0;
void student::add() {
	char flag = 'Y';
	while (toupper(flag) == 'Y')
	{
		cin >> stu[n];
		n++;
		cout << "请问继续输入吗?(请输入Y或者N)" << endl;
		cin >> flag;
		if (toupper(flag) != 'Y') {
			if (toupper(flag) == 'N') {
				break;
			}
			else {
				cout << "输入错误，请重新输入；" << endl;
				cin >> flag;
			}
		}
	}
}
void student::output()
{
	if (n != 0)
	{
		cout << "--------------------------------------------------------------" << endl;
		cout << " 学号 姓名 性别 语文 英语 数学 物理 化学 生物 平时成绩 总评" << endl;
		cout << "--------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << stu[i];
		}
	}
	getch();
}
void student::find()
{
	int f3 = 0;
	char n1[20];
	student temp;
	cout << endl;
	cout << "请输入您要查找的学生姓名；" << endl;
	cin >> n1;
	for (int j = 0; j < n; j++)
	{
		if (strcmp(stu[j].name, n1) == 0) {
			temp = stu[j];
			f3 = 1;
		}
	}
	if (f3 == 0) {
		cout << "对不起未找到您要查找的学生" << endl;
	}
	else {
		cout << "--------------------------------------------------------------" << endl;
		cout << " 学号 姓名 性别 语文 英语 数学 物理 化学 生物 平时成绩 总评" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << setw(5) << temp.number << setw(6) << temp.name << setw(6) << temp.sex << setw(6) << temp.score[0]
			<< setw(6) << temp.score[1] << setw(6) << temp.score[2] << setw(6) << temp.score[3] <<
			setw(6) << temp.score[4] << setw(6) << temp.score[5] << setw(6) << temp.score[6] <<
			setw(9) << temp.last << endl;
	}
	getch();
}
void student::modify() {
	int f4 = 0;
	int t = 0;
	char n2[50];
	cout << endl;
	cout << "请输入您要修改的学生姓名；" << endl;
	cin >> n2;
	for (int j = 0; j < n; j++) {
		if (strcmp(stu[j].name, n2) == 0) {
			t = j;
			f4 = 1;
		}
	}
	if (f4 == 0) {
		cout << "对不起为找到该学生" << endl;
	}
	else
	{
		cout << "请输入修改的学生学号；" << endl;
		cin >> stu[t].number;
		cout << "请输入修改的学生姓名；" << endl;
		cin >> stu[t].name;
		cout << "请输入修改的学生性别；" << endl;
		cin >> stu[t].sex;
		cout << "请输入修改的语文成绩；" << endl;
		cin >> stu[t].score[0];
		cout << "请输入修改的英语成绩；" << endl;
		cin >> stu[t].score[1];
		cout << "请输入修改的数学成绩；" << endl;
		cin >> stu[t].score[2];
		cout << "请输入修改的物理成绩；" << endl;
		cin >> stu[t].score[3];
		cout << "请输入修改的化学成绩；" << endl;
		cin >> stu[t].score[4];
		cout << "请输入修改的生物成绩；" << endl;
		cin >> stu[t].score[5];
		cout << "请输入修改的平时成绩；" << endl;
		cin >> stu[t].score[6];
		stu[t].total = stu[t].score[0] + stu[t].score[1] + stu[t].score[2] + stu[t].score[3] + stu[t].score[4] + stu[t].score[5];
		stu[t].average = stu[t].total / 6;
		stu[t].last = (int)(stu[t].score[6] * 0.3 + stu[t].average * 0.7);
		cout << "修改成功！" << endl;
	}
	getch();
}


void student::deleted()
{
	char n3[20];
	bool f5 = 0;
	char c;
	do
	{
		cout << '\n';
		cout << "请输入您要删除的学生姓名：";
		cin >> n3;
		for (int i = 0; i < n; i++)
		{
			if (strcmp(n3, stu[i].name) == 0)
			{
				f5 = 1;
				n--;
				do
				{
					stu[i] = stu[i + 1];
					i++;
				} while (i <= n);
			}
		}
		if (f5 == 0)
		{
			cout << "您要删除的学生不存在";
		}
		cout << "请问要继续删除吗？（输入y或n）" << endl;
		cin >> c;
		if (toupper(c) != 'Y'&&toupper(c) != 'N')
		{
			cout << "输入 错误，您只能输入Y或N" << endl;
			cin >> c;

		}
	} while (toupper(c) == 'Y');
	getch();
}



void student::save()
{
	char filename1[20];
	cout << "请输入文件名：";
	cin >> filename1;
	ofstream fout(filename1, ios::app);
	if (!fout)
	{
		cout << "文件不能打开！" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fout << ' ' << stu[i].number << ' ' << stu[i].name << ' ' << stu[i].sex << ' ' << stu[i].score[0]
				<< ' ' << stu[i].score[1] << ' ' << stu[i].score[2] << ' ' << stu[i].score[3] << ' ' << stu[i].score[4]
				<< ' ' << stu[i].score[5] << ' ' << stu[i].score[6] << ' ' << stu[i].total << ' ' << stu[i].average << ' ' << stu[i].last;
		}
		cout << "保存成功！" << endl;
	}
	fout.close();
	getch();
}
void student::load()
{
	char filename2[20];
	cout << "请输入您要读取的文件名：";
	cin >> filename2;
	ifstream fin(filename2, ios::in);
	if (!fin)
	{
		cout << "文件不能打开！" << endl;
	}
	else
	{
		for (int i = 0;; i++, n = i - 1)
		{
			if (fin.eof())
				break;
			fin << ' ' << stu[i].number << ' ' << stu[i].name << ' ' << stu[i].sex << ' ' << stu[i].score[0]
				<< ' ' << stu[i].score[1] << ' ' << stu[i].score[2] << ' ' << stu[i].score[3] << ' ' << stu[i].score[4]
				<< ' ' << stu[i].score[5] << ' ' << stu[i].score[6] << ' ' << stu[i].total << ' ' << stu[i].average << ' ' << stu[i].last;
		}
		cout << "文件读取成功！" << endl;
	}
	fin.close();
	getch();
}


student & student::operator=(student &T)
{
	strcpy(name, T.name);
	strcpy(sex, T.sex);
	number = T.number;
	for (int i = 0; i < 7; i++)
		score[i] = T.score[i];
	total = T.total;
	average = T.average;
	last = T.last;
	return(*this);
}


ostream& operator <<(ostream & scout, student &s2)
{
	cout << setw(5) << s2.number << setw(6) << s2.name << setw(6) << s2.sex << setw(6) << s2.score[0]
		<< setw(6) << s2.score[1] << setw(6) << s2.score[2] << setw(6) << s2.score[3] << setw(6) << s2.score[4]
		<< setw(6) << s2.score[5] << setw(7) << s2.score[6] << setw(9) << s2.last << '\n';
	return scout;
}

istream& operator >>(istream & scin, student &s1)
{
	cout << "\n";
	cout << "学号:";
	scin >> s1.number;
	cout << "姓名:";
	scin >> s1.name;
	cout << "性别:";
	scin >> s1.sex;
	cout << "语文:";
	scin >> s1.score[0];
	cout << "英语 :";
	scin >> s1.score[1];
	cout << "数学:";
	scin >> s1.score[2];
	cout << "物理:";
	scin >> s1.score[3];
	cout << "化学:";
	scin >> s1.score[4];
	cout << "生物:";
	scin >> s1.score[5];
	cout << "平时成绩:";
	scin >> s1.score[6];
	s1.total = s1.score[0] + s1.score[1] + s1.score[2] + s1.score[3] + s1.score[4] + s1.score[5];
	s1.average = s1.total / 6;
	s1.last = (int)(s1.score[6] * 0.3 + s1.average*0.7);
	return scin;

}

student::student()
{
	strcpy(name, " ");
	strcpy(sex, " ");
	number = 0;
	for (int i = 0; i<7; i++)
		score[i] = 0;
	total = 0;
	average = 0;
	last = 0;
}


void menu()
{
	cout << "\n\n\n\t\t\t【学生成绩管理系统主菜单】" << endl;
	cout << "\n\n\n\t\t\t1学生成绩录八" << endl;
	cout << "\n\n\n\t\t\t2浏览学生成绩" << endl;
	cout << "\n\n\n\t\t\t3查询学生成绩" << endl;
	cout << "\n\n\n\t\t\t4修改学生成绩" << endl;
	cout << "\n\n\n\t\t\t5册除学生成绩" << endl;
	cout << "\n\n\n\t\t\t6数据存入文件" << endl;
	cout << "\n\n\n\t\t\t7文件读出数据" << endl;
	cout << "\n\n\n\t\t\t0退出系统" << endl;
	cout << "\n\n\t请输入一位数字(1 - 7)选择您所需的功能，并按回车键确认【退出请输0】:";
}

int main()
{
	int choose;
	student s;
	do {
		menu();
		cin >> choose;
		switch (choose)
		{
		case 1: s.add(); break;
		case 2: s.output(); break;
		case 3: s.find(); break;
		case 4: s.modify(); break;
		case 5: s.deleted(); break;
		case 6: s.save(); break;
		case 7: s.load(); break;
		default: break;
		}
	} while (choose != 0);
}
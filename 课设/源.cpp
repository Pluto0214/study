#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
#include<stdio.h>
#define M 100

using namespace std;
FILE *fpw = NULL;//�����ļ������ڴ洢���������ѧ����Ϣ
				 //cout<<"���������������ݸ���:"��
				 //cin<<a;
typedef struct stu
{
	char name[20];//����
	char sex[10];//�Ա�
	char num[10];//ѧ��,���ó��ַ����ͣ�ѧ����һ������
	int score[7];//���ģ�Ӣ���ѧ��������ѧ�����ƽʱ�ɼ�
	int ave;//ƽ����
	int total;//�ܷ�
}STU;


class Student
{
public:
	Student();
	void input();//��������
	void print();//���
	void output(char curse[], int t);//�ļ�
	void look();//���
	void find();//����
	void Delete();//ɾ��
	void design();//�޸�
	friend ostream &operator<<(ostream &os, STU &stu);//������������
	friend istream &operator >> (istream &is, STU &stu);//�������������
private:
	STU stu;
};
Student s[M];//100��ѧ������
Student::Student()//���캯�����ܴ�������Ҫ������������ʱ��֪����ʲô
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
void Student::input()//ѧ���ɼ�¼�뺯��
{
	char ju = 'Y';
	int i = 0;
	cout << "������ѧ����Ϣ��" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "����  �Ա�   ѧ��   ����  Ӣ��  ��ѧ  ����  ��ѧ  ����  ƽʱ�� " << endl;
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
		cout << "����������'Y'��'y',���������������ַ�" << endl;
		cin >> ju;
	}
}
void Student::output(char curse[], int t)//�ļ����溯��
{
	char a[50] = "C:\\Users\\Asus\\Desktop\\���", b[5] = ".txt";
	strcat(curse, b);
	strcat(a, curse);
	//cin>>a;
	fpw = fopen(a, "w");
	if (fpw == NULL)
		cout << "�ļ��޷���" << endl;
	else
	{

		for (int i = 0; i<M; i++)
		{
			if (s[i].stu.num[6] == curse[1])
			{
				fputs(s[i].stu.name, fpw);//����
				fputs("  ", fpw);//�ո�
				fputs(s[i].stu.sex, fpw);//�Ա�
				fputs("   ", fpw);//�ո�
				fputs(s[i].stu.num, fpw);//ѧ��
				fputs("   ", fpw);//�ո�
				fprintf(fpw, "%d\n", s[i].stu.score[t]);//���Ƴɼ�
			}
		}
		fclose(fpw);//�ر��ļ�
		cout << "�ļ�����ɹ�" << endl;
	}
}
void Student::look()//�����ļ����溯��
{
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "û�����ݿ���ʹ��" << endl;
	else
	{
		char curse[20], cu[8];
		int t;
		cout << "��������Ҫ�鿴�İ༶���뼰��Ŀ,��1������������c1yuwen:" << endl;
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
		cout << "û�����ݿ���ʹ��" << endl;
	else
	{
		char na[10], b = 'Y';
		int t, k;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "����  �Ա�   ѧ��   ����  Ӣ��  ��ѧ  ����  ��ѧ  ����  ƽʱ��  ���� " << endl;
		cout << "----------------------------------------------------------------------" << endl;
		while (b == 'Y' || b == 'y')
		{
			cout << "��������Ҫ���ҵ�ѧ��������:" << endl;
			cin >> na;//����Ҫ���ҵ�ѧ��������
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
				cout << "ѧ����Ϣ��û����Ҫ���ҵ�ͬѧ" << endl;
			cout << "�Ƿ�������в���,���ǣ�������'Y'��'y',���������������ַ�" << endl;
			cin >> b;
		}
	}
}
void Student::design()//ѧ���ɼ��޸ĺ���
{
	int sum = 0;
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "û�����ݿ���ʹ��" << endl;
	else
	{
		char a[10], n = 'Y';
		int  t, k;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "����  �Ա�   ѧ��   ����  Ӣ��  ��ѧ  ����  ��ѧ  ����  ƽʱ��  ���� " << endl;
		cout << "--------------------------------------------------------------------" << endl;
		while (n == 'Y' || n == 'y')
		{
			cout << "��������Ҫ�޸ĳɼ���ѧ��������" << endl;
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
				cout << "ѧ����Ϣ��û�д�ͬѧ";
			if (t == 1)
			{
				cout << "�������޸ĺ��ѧ����������" << endl;
				cin >> a;
				strcpy(s[k].stu.name, a);
				cout << "�������޸ĺ��ѧ�����Ա�" << endl;
				cin >> a;
				strcpy(s[k].stu.sex, a);
				cout << "�������޸ĺ��ѧ����ѧ�ţ�" << endl;
				cin >> a;
				strcpy(s[k].stu.num, a);
				cout << "�밴˳�������޸ĺ��ѧ���ĸ���ɼ���" << endl;
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
				cout << "�޸����" << endl;
				cout << "�޸ĺ���Ϣ" << endl;
				cout << s[k].stu;
			}
			cout << "�Ƿ���������޸�,���ǣ�������'Y'��'y'����������������ַ�" << endl;
			cin >> n;
		}
	}
}


ostream &operator<<(ostream &os, STU &stu)//������������
{
	os << stu.name << "  " << stu.sex << "   " << stu.num << "   " << stu.score[0] << "    " << stu.score[1] << "    " << stu.score[2] << "    " << stu.score[3] << "    " << stu.score[4] << "    " << stu.score[5] << "    " << stu.score[6] << "    " << stu.total << endl;
	return os;
}


istream &operator >> (istream &is, STU &stu)//�������������
{
	is >> stu.name >> stu.sex >> stu.num >> stu.score[0] >> stu.score[1] >> stu.score[2] >> stu.score[3] >> stu.score[4] >> stu.score[5] >> stu.score[6];
	return is;
}
void Student::Delete()//ѧ����Ϣɾ������
{
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "û�����ݿ���ʹ��" << endl;
	else
	{
		char na[10];
		char q = 'Y';
		while (q == 'Y' || q == 'y')
		{
			cout << "��������Ҫɾ����ͬѧ��������";
			cin >> na;
			for (int i = 0; i<M; i++)
			{
				if (strcmp(s[i].stu.name, na) == 0)//�ж��Ƿ����
				{
					for (int j = i; j<M - 1; j++)
					{
						strcpy(s[j].stu.name, s[j + 1].stu.name);//�ú�һ������Ҫɾ���Ľ��и���
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
					cout << "û�и�ѧ��" << endl;
			}
			cout << "ɾ�����" << endl;
			cout << "�Ƿ��������ɾ�����������ǣ�������'Y'��'y';��������롮N����'n'" << endl;
			cin >> q;
		}
		cout << "ɾ�����ѧ����Ϣ��Ϊ��" << endl;
		print();
	}
}
void Student::print()
{
	int t = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "����  �Ա�   ѧ��   ����  Ӣ��  ��ѧ  ����  ��ѧ  ����  ƽʱ��  ���� " << endl;
	cout << "----------------------------------------------------------------------" << endl;
	if (strcmp(s[0].stu.name, " ") == 0)
		cout << "û�����ݿ���ʹ��" << endl;
	else
	{
		for (int i = 0; i<M; i++)
		{
			if (strcmp(s[i].stu.name, " ") != 0)
			{
				cout << s[i].stu;
			}
		}
		cout << "������" << endl;
	}
}
void headline()
{
	cout << "\n\n\n\t\t   ��ѧ���ɼ�����ϵͳ���˵���" << endl;
	cout << "\t\t\t1.ѧ���ɼ�¼��" << endl;
	cout << "\t\t\t2.���ѧ���ɼ�" << endl;
	cout << "\t\t\t3.��ѯѧ���ɼ�" << endl;
	cout << "\t\t\t4.�޸�ѧ���ɼ�" << endl;
	cout << "\t\t\t5.ɾ��ѧ���ɼ�" << endl;
	cout << "\t\t\t6.���ݴ����ļ�" << endl;
	cout << "\t\t\t7.�ļ���������" << endl;
	cout << "\t\t\t0.�˳�ϵͳ" << endl;
	cout << "\n\t*������һλ����(1 - 7)ѡ��������Ĺ��ܣ������س���ȷ�ϡ��˳�����0��:";
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
		cout << "��ѡ����Ҫ���еĲ���:" << endl;
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
		cout << "�Ƿ����������������������������'Y'��'y'������������������ĸ" << endl;
		cin >> x;
	}
}
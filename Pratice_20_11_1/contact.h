#pragma once
//���͵�����+����������
#include<stdio.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 100
#define MAX_QQ   20
#define MAX_SEX  5  

#define MAX 1000
typedef struct PeoInfo//�˵���Ϣ
{
	char name[MAX_NAME];
	//δ�������ֵ��ڴ��С���ܲ�����
	//���д��char name[20],���Ժ���ĵĻ��͵��ڸ����ط���������
	//�������������ֱ��#define,
	//�Ժ������ĵĻ�ֱ����#define MAX_NAME��ľ��С�
	//���涼ͬ��
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;
//����Ժ���������ṹ��Ļ���һֱ����struct PeoInfo
//Ϊ�˼�д��PeoInfo��д������������ָ�ʽ
//������Щ��һ���˵���Ϣ����������ȥtest.cȥ����һ��1000�˵�����

//ͨѶ¼
typedef struct Contact
{
	PeoInfo data[MAX];//�������
	int sz;//ͨѶ¼����Ϣ�˵���Ч����
}Contact;

//���һ���˵���Ϣ
void add_contact(Contact* pc);

//��ʾͨѶ¼�����Ϣ
void show_contact(Contact* pc);

//ɾ��ָ����ϵ��
void del_contact(Contact* pc);

//����ָ����ϵ��
void search_contact(Contact* pc);

//�޸�ָ����ϵ��
void modify_contact(Contact* pc);

//����ͨѶ¼������
void sort_contact(Contact* pc);
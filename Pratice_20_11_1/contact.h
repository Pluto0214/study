#pragma once
//类型的声明+函数的声明
#include<stdio.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 100
#define MAX_QQ   20
#define MAX_SEX  5  

#define MAX 1000
typedef struct PeoInfo//人的信息
{
	char name[MAX_NAME];
	//未来对名字的内存大小可能不符合
	//如果写成char name[20],那以后想改的话就得在各个地方把他改了
	//所以在这里可以直接#define,
	//以后如果想改的话直接在#define MAX_NAME这改就行。
	//下面都同理
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;
//如果以后想用这个结构体的话得一直输入struct PeoInfo
//为了简化写成PeoInfo，写成了上面的这种格式
//以上这些是一个人的信息，所以现在去test.c去定义一个1000人的数组

//通讯录
typedef struct Contact
{
	PeoInfo data[MAX];//存放数据
	int sz;//通讯录中信息人的有效个数
}Contact;

//添加一个人的信息
void add_contact(Contact* pc);

//显示通讯录里的信息
void show_contact(Contact* pc);

//删除指定联系人
void del_contact(Contact* pc);

//查找指定联系人
void search_contact(Contact* pc);

//修改指定联系人
void modify_contact(Contact* pc);

//排序通讯录的数据
void sort_contact(Contact* pc);
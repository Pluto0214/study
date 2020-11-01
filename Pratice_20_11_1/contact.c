#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void add_contact(Contact* pc)
{
	//要在添加的时候检验一下通讯录有没有满
	if (pc->sz == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		//把sz的值作为这个数组的下标
		printf("请输入名字:");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入电话:");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入地址:");
		scanf("%s", pc->data[pc->sz].addr);
		printf("请输入qq:");
		scanf("%s", pc->data[pc->sz].qq);
		printf("请输入性别:");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入年龄:");
		scanf("%d", &(pc->data[pc->sz].age));
		//age是一个变量，所以需要取地址
		pc->sz++;
		printf("添加成功\n");
	}
}

void show_contact(Contact* pc)
{
	int i = 0;
	printf("%20s %12s %30s %5s %12s %5s\n", 
		"名字", "电话", "地址", "年龄", "QQ", "性别");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%20s %12s %30s %5d %12s %5s\n", pc->data[i].name,
			pc->data[i].tele,
			pc->data[i].addr,
			pc->data[i].age,
			pc->data[i].qq,
			pc->data[i].sex);
	}
}

static int find_peo_byname(Contact* pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;//找到了，返回下标。
		}
	}
	return -1;//找不到
}

void del_contact(Contact* pc)
{
	//先判断它是不是空的
	if (pc->sz == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("输入要删除人的名字:");
		scanf("%s", name);
		//1.找到指定联系人的位置
		int pos =find_peo_byname(pc,name);
		if (pos == -1)
		{
			printf("改联系人不存在\n");
		}
		else
		{
			//2.删除
			//要删除的元素的后面元素把它顶替，然后后面的元素依次往前挪一位
			int j = 0;
			for (j = pos; j < pc->sz; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("删除成功\n");
		}
	}
}

void search_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入查找人的名字:");
	scanf("%s", name);
	int pos=find_peo_byname(pc, name);
	if (pos == -1)
	{
		printf("没有找到这个人\n");
	}
	else
	{
		printf("%20s %12s %30s %5s %12s %5s\n",
			"名字", "电话", "地址", "年龄", "QQ", "性别");
		printf("%20s %12s %30s %5d %12s %5s\n", pc->data[pos].name,
			pc->data[pos].tele,
			pc->data[pos].addr,
			pc->data[pos].age,
			pc->data[pos].qq,
			pc->data[pos].sex);
	}
}

void modify_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入修改人的名字:");
	scanf("%s", name);
	int pos = find_peo_byname(pc, name);
	if (pos == -1)
	{
		printf("没有找到这个人");
	}
	else
	{
		printf("请输入新的名字:");
		scanf("%s", pc->data[pos].name);
		printf("请输入新的电话:");
		scanf("%s", pc->data[pos].tele);
		printf("请输入新的地址:");
		scanf("%s", pc->data[pos].addr);
		printf("请输入新的qq:");
		scanf("%s", pc->data[pos].qq);
		printf("请输入新的性别:");
		scanf("%s", pc->data[pos].sex);
		printf("请输入新的年龄:");
		scanf("%d", &(pc->data[pos].age));
	}
}

void sort_contact(Contact* pc)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pc->sz - 1; i++)
	{
		int flag = 1;//假设已经有序
		//这个flag是冒泡排序的一种优化。
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}
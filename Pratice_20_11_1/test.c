#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("******** 1.add     2.del    ******\n");
	printf("******** 3.search  4.modify ******\n");
	printf("******** 5.sort    6.show   ******\n");
	printf("********      0.exit        ******\n");
	printf("**********************************\n");
}
//枚举成员的命名一般都是大写
enum Option
{
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW,
	EXIT
};

void test()
{
	/*PeoInfo data[MAX];*///定义了一个1000人的数组
	/*int sz = 0;*///统计通讯录中有效信息人的个数
	Contact con = { 0 };//创建的通讯录
	int input = 0;
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			//这里需要sz，但不能直接传sz，要传sz的地址
			//因为这就是形参相当于实参的一份临时拷贝,
			//这样的话形参中的数改变是不会改变实参的，
			//所以要传地址让形参和实参之间建立联系
			//更简单的办法就是再封装一个结构体,
			//把PeoInfo data[MAX]和sz直接放进去,直接引用这个结构体即可
			break;
		case DEL:
			del_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误\n");
			break;
		
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
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
//ö�ٳ�Ա������һ�㶼�Ǵ�д
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
	/*PeoInfo data[MAX];*///������һ��1000�˵�����
	/*int sz = 0;*///ͳ��ͨѶ¼����Ч��Ϣ�˵ĸ���
	Contact con = { 0 };//������ͨѶ¼
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			//������Ҫsz��������ֱ�Ӵ�sz��Ҫ��sz�ĵ�ַ
			//��Ϊ������β��൱��ʵ�ε�һ����ʱ����,
			//�����Ļ��β��е����ı��ǲ���ı�ʵ�εģ�
			//����Ҫ����ַ���βκ�ʵ��֮�佨����ϵ
			//���򵥵İ취�����ٷ�װһ���ṹ��,
			//��PeoInfo data[MAX]��szֱ�ӷŽ�ȥ,ֱ����������ṹ�弴��
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�������\n");
			break;
		
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
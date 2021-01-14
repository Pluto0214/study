#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a; //һ������ _ָ�������ǳ�Ա
	int _top; //ջ���±� ����size��
	int _capacity;
}Stack;
//��ȻջҲ�����óɾ�̬��
//struct Stack
//{
//	int a[N];
//	int size;
//};

//��ʼ��������
void StackInit(Stack* pst);
void StackDestory(Stack* pst);
//��ջ
void StackPush(Stack* pst, STDataType x);
//��ջ
void StackPop(Stack* pst);

//��ȡ���ݸ���
//���ﲻ��ı����� ����Ҳ���Բ���ָ�룬��Ϊ��ͳһ��û��Ǵ�ָ��
int StackSize(Stack* pst);

//����1�ǿգ�����0�Ƿǿ�
int StackEmpty(Stack* pst);

//��ȡջ��������
STDataType StackTop(Stack* pst);

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct {
	int *queue;
	int head;
	int tail;
} RecentCounter;

RecentCounter* recentCounterCreate() {
	int i = 3000;
	RecentCounter *obj = malloc(sizeof(RecentCounter));
	obj->head = 0;
	obj->tail = 0;
	obj->queue = malloc(3001 * sizeof(int));
	while (i >= 0) (obj->queue)[i--] = -1;
	return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
	while ((obj->queue)[obj->head]<t - 3000 && (obj->queue)[obj->head] != -1) {
		(obj->queue)[obj->head] = -1;
		if ((obj->queue)[obj->tail] != -1) obj->head++;
		if (obj->head>3000) obj->head = obj->head - 3001;
	}
	if ((obj->queue)[obj->tail] != -1) obj->tail++;
	if (obj->tail>3000) obj->tail = obj->tail - 3001;
	(obj->queue)[obj->tail] = t;
	return obj->tail >= obj->head ? obj->tail - obj->head + 1 : obj->tail + 3002 - obj->head;
}

void recentCounterFree(RecentCounter* obj) {
	free(obj->queue);
	free(obj);
}


typedef struct {
	int *data;//数据域
	int front;//队列头
	int rear;//队列尾
	int size;//队列大小 -> 用以避免数组越界  
	int flag;//标志队列是否满 ->   1 满   0 不满
			 //如果不用此标志位的话，数组需要留多一位空位用来 判别 队列是否满
			 //即：当 头指针 在 尾指针的下一个位置（多的空位）时，队列满。
} MyCircularQueue;//采用数组实现


bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
//注意加上函数声明

MyCircularQueue* myCircularQueueCreate(int k) {
	if (k < 0) {//传参检查
		return NULL;
	}
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (obj == NULL) {
		return NULL;
	}
	obj->data = (int*)malloc(k * sizeof(int));
	if (obj->data == NULL) {
		return NULL;
	}
	//赋各项初值
	obj->front = obj->rear = 0;
	obj->size = k;
	obj->flag = 0;
	return obj;
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj)) {//判断队列是否满
		return false;
	}
	obj->data[obj->rear] = value;//插入数据
	obj->rear = ((obj->rear + 1) < obj->size) ? (obj->rear + 1) : 0;
	//判断是否到达数组边界，且尾指针+1
	if (obj->rear == obj->front) {//在插入新元素后，两指针指向相同，只有队列满一种情况。
		obj->flag = 1;//队列已满
	}
	return true;
}


bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj)) {//判断队列是否空
		return false;
	}
	obj->data[obj->front] = 0;//清除队头的数据
	obj->front = ((obj->front + 1) < obj->size) ? (obj->front + 1) : 0;
	//判断是否到达数组边界,且头指针+1
	obj->flag = 0;//只要删除了元素，队列就不可能满
	return true;
}


int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj)) {
		return -1;
	}
	return obj->data[obj->front];
}


int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj)) {
		return -1;
	}
	int i = (obj->rear == 0) ? (obj->size - 1) : (obj->rear - 1);
	//尾指针指向的是末尾数据的下一个位置，此处避免数组越界
	return obj->data[i];
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->flag == 0 && obj->front == obj->rear) {//队列未满 且 首尾指针指向相同，则表明队列空
		return true;
	}
	else {
		return false;
	}
}


bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if (obj->flag == 1) {
		return true;
	}
	else {
		return false;
	}
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	obj->data = NULL;
	free(obj);
	obj = NULL;
}

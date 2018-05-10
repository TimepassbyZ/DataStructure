// 错误
#include <iostream>

using namespace std;

#ifndef MaxSize
#define MaxSize 10
#endif

typedef struct
{
	int data[MaxSize];
	int rear, front;
	bool empty;
} SqQueue;

typedef struct node
{
	struct node *next;
	SqQueue *linkdata = NULL;
} LinkQueue;

bool insert (SqQueue *q[10])
{
	cout << "input count:" << endl;
	int count;
	cin >> count;

	// 接收10以内的数字并插入对应序号的队列
	for (int i = 0; i < count; ++i)
	{
		cout << "input num0-9:" << endl;
		int num;
		cin >> num;
		if ((q[num] -> rear + 1) % MaxSize == q[num] -> front)
		{
			cout << "full!" << endl;
			return false;
		}
		else
		{
			q[num] -> rear = (q[num] -> rear + 1) % MaxSize;
			q[num] -> data[q[num] -> rear] = num;
			q[num] -> empty = false;
		}
	}
	return true;
}

void link (SqQueue *q[10], LinkQueue *&l)
{
	LinkQueue *temp, *tail;
	temp = new LinkQueue;
	temp -> next = NULL;
	tail = l; // 目前l为空

	for (int i = 0; i < 10; ++i)
	{
		if (q[i] -> empty == false)
		{
			temp -> linkdata = q[i];
			tail -> next = temp;
			tail = temp;
		}
	}
	tail -> next = NULL;
}

void display (LinkQueue *l)
{
	cout << "display:" << endl;
	LinkQueue *temp = l -> next;
	while (temp != NULL)
	{
		temp -> linkdata -> front = (temp -> linkdata -> front + 1) % MaxSize;
		while (temp -> linkdata -> data[temp -> linkdata -> front])
		{
			cout << temp -> linkdata -> data[temp -> linkdata -> front] << endl;
		}
		temp = temp -> next;
	}
}

int main(int argc, char const *argv[])
{
	// 初始化这10个队列
	SqQueue *q[10];
	for (int i = 0; i < 10; ++i)
	{
		q[i] = new SqQueue;
		q[i] -> rear = q[i] -> front = 0;
		q[i] -> empty = true;
	}
	if (insert(q) == false)
	{
		return -1;
	}
	// 初始化链
	LinkQueue *l;
	l = new LinkQueue;
	l -> next = NULL;
	link(q, l);
	display(l);
	delete l;
	// 释放指针数组
	for (int i = 0; i < 10; ++i)
	{
		delete q[i];
	}
	return 0;
}
#include <iostream>

using namespace std;

typedef char ElemType;

typedef struct qnode
{
	ElemType data;
	struct qnode *next;
} QNode;

typedef struct
{
	QNode *front;
	QNode *rear;
} LiQueue;

void InitQueue (LiQueue *&q)
{
	q = new LiQueue;
	q -> front = q -> rear = NULL;
}

void DestroyQueue (LiQueue *&q)
{
	QNode *p = q -> front, *r;
	if (p != NULL)
	{
		r = p -> next;
		while (r != NULL)
		{
			delete p;
			p = r;
			r = p -> next;
		}
	}
	delete p;
	delete q;
}

bool QueueEmpty (LiQueue *q)
{
	return (q -> rear == NULL);
}

void enQueue (LiQueue *&q, ElemType e)
{
	QNode *p;
	p = new QNode;
	p -> data = e;
	p -> next = NULL;
	// 链队为空
	if (q -> rear == NULL)
	{
		q -> front = q -> rear = p; // 新节点既是队首节点又是队尾节点
	}
	else
	{
		q -> rear -> next = p;
		q -> rear = p;
	}
}

bool deQueue (LiQueue *&q, ElemType &e)
{
	if (q -> rear == NULL)
	{
		return false;
	}
	QNode *p;
	p = q -> front;
	e = p -> data;
	// 队列中只有一个节点
	if (q -> front == q -> rear)
	{
		q -> front = q -> rear = NULL;
	}
	else
	{
		q -> front = p -> next;
	}
	delete p;
	return true;
}

int main(int argc, char const *argv[])
{
	LiQueue *q;
	InitQueue(q);
	cout << "2.Empty:" << QueueEmpty(q) << endl;
	enQueue(q, 'a');
	enQueue(q, 'b');
	enQueue(q, 'c');
	ElemType e;
	deQueue(q, e);
	cout << "4.out:" << e << endl;
	if (q -> rear == NULL)
	{
		cout << "5.num:0" << endl;
	}
	else
	{
		QNode *p = q -> front;
		int num = 0;
		while (p != NULL)
		{
			num++;
			p = p -> next;
		}
		cout << "5.num:" << num << endl;
	}
	enQueue(q, 'd');
	enQueue(q, 'e');
	enQueue(q, 'f');
	if (q -> rear == NULL)
	{
		cout << "7.num:0" << endl;
	}
	else
	{
		QNode *p = q -> front;
		int num = 0;
		while (p != NULL)
		{
			num++;
			p = p -> next;
		}
		cout << "7.num:" << num << endl;
	}
	if (q -> rear == NULL)
	{
		cout << "8.display:NONE" << endl;
	}
	else
	{
		QNode *p = q -> front;
		cout << "8.display:" << endl;
		while (p != NULL)
		{
			cout << p -> data << endl;
			p = p -> next;
		}
	}
	DestroyQueue(q);
	return 0;
}
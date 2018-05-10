// 伪代码
typedef struct
{
	ElemType data[MaxSize];
	int front;
	int count; // 队列中的元素个数
} QuType;

#ifndef MaxSize
#define MaxSize 10
#endif

typedef char ElemType;

void InitQueue (QuType *&q)
{
	q = new QuType;
	q -> front = 0;
	q -> count = 0;
}

bool EnQueue (QuType *&q, ElemType e)
{
	int rear;
	if (q -> count == MaxSize)
	{
		return false;
	}
	else
	{
		rear = (q -> front + q -> count) % MaxSize;
		rear = (rear + 1) % MaxSize;
		q -> data[rear] = e;
		q -> count++;
		return true;
	}
}

bool DeQueue (QuType *&q, ElemType &e)
{
	if (q -> count == 0)
	{
		return false;
	}
	else
	{
		q -> front = (q -> front + q -> count) % MaxSize;
		e = q -> data[q -> front];
		q -> count--;
		return true;
	}
}

bool QueueEmpty (QuType *q)
{
	return (q -> count == 0);
}

// 队尾指针rear = (front + count) % MaxSize;
// 
// 队空
// count == 0;
// 
// 队满
// count == MaxSize;
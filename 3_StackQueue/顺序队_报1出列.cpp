// 121212... 报1出列，报2排队尾
#include <iostream>

using namespace std;

typedef int ElemType;

#ifndef MaxSize
#define MaxSize 10
#endif

typedef struct
{
	ElemType data[MaxSize];
	int front;
	int rear;
} SqQueue;

void outOrder (SqQueue q)
{
	cout << "out order:" << endl;
	while (q.front != q.rear)
	{
		// 指向第一个数据后出队
		q.front = (q.front + 1) % MaxSize;
		cout << q.data[q.front] << " | ";
		if (q.front != q.rear)
		{
			// 第二个元素排队尾
			q.front = (q.front + 1) % MaxSize;
			ElemType e;
			e = q.data[q.front];
			q.rear = (q.rear + 1) % MaxSize;
			q.data[q.rear] = e; // 出队的元素入队
		}
	}
}

int main(int argc, char const *argv[])
{
	cout << "input length:" << endl;
	int length;
	cin >> length;
	SqQueue q;
	q.front = 0;
	q.rear = 0;
	// 如果为 SqQueue *q
	// 则应先分配动态内存 q = new SqQueue;
	// 目的是能手动选择q的生存周期，扩大其作用域
	
	// 初始排序
	for (int i = 1; i <= length; ++i)
	{
		q.rear = (q.rear + 1) % MaxSize;
		q.data[q .rear] = i;
	}
	outOrder(q);

	return 0;
}
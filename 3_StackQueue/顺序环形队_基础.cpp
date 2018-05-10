#include <iostream>

using namespace std;

typedef char ElemType;

// 队列最长长度
#ifndef MaxSize
#define MaxSize 10
#endif

// rear	英[rɪə(r)]	美[rɪr]
// vt.	饲养; 养育; 抚养; 养育;
// vt.	抬起;
// n.	后部，背面，背后; 臀部; （舰队或军队的） 后方，后尾，殿后部队; 〈英口〉厕所;
// [例句]	He settled back in the rear of the taxi.
// 			他靠坐在出租车的后排座上。
// [其他]	第三人称单数：rears 复数：rears 现在分词：rearing 过去式：reared 过去分词：reared
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;


// queue	英[kju:]	美[kju]
// n.	（人或车辆） 行列，长队; 辫子;
// vi.	（人、车等） 排队等候;
// vt.	（使） 排队，列队等待;
// [例句]	I watched as he got a tray and joined the queue
// 			我看着他拿了个托盘排起了队。
// [其他]	第三人称单数：queues 复数：queues 现在分词：queuing 过去式：queued 过去分词：queued
void InitQueue (SqQueue *&q)
{
	q = new SqQueue;
	q -> front = q -> rear = 0;
}

void DestroyQueue (SqQueue *&q)
{
	delete q;
}

bool QueueEmpty (SqQueue *q)
{
	return (q -> front == q -> rear);
}

// 从尾插入
bool enQueue (SqQueue *&q, ElemType e)
{
	if ((q -> rear + 1) % MaxSize == q -> front)
	{
		return false;
	}
	// 先指向下一个空位置，再填入元素
	q -> rear = (q -> rear + 1) % MaxSize;
	q -> data[q -> rear] = e;
	return true;
}

// 从头删除
bool deQueue (SqQueue *&q, ElemType &e)
{
	if (q -> front == q -> rear)
	{
		return false;
	}
	// 头指针指向下一个待删除元素的位置相当于从队列删除
	q -> front = (q -> front + 1) % MaxSize;
	e = q -> data[q -> front];
	return true;
}

int main(int argc, char const *argv[])
{
	SqQueue *q;

	InitQueue(q);
	cout << "2.empty:" << QueueEmpty(q) << endl;
	enQueue(q, 'a');
	enQueue(q, 'b');
	enQueue(q, 'c');
	ElemType e;
	deQueue(q, e);
	cout << "4.out:" << e << endl;
	cout << "5.length:" << (q -> rear - q -> front + MaxSize) % MaxSize << endl;
	enQueue(q, 'd');
	enQueue(q, 'e');
	enQueue(q, 'f');
	cout << "7.length:" << (q -> rear - q -> front + MaxSize) % MaxSize << endl;
	cout << "8.allout:" << endl;
	while (deQueue(q, e))
	{
		cout << e << endl;
	}
	DestroyQueue(q);


	return 0;
}

// 队首指针front指向队中队头元素的前一个位置
// 队尾指针rear指向队中队尾元素
// 
// 队中元素个数
// num = (rear - front + MaxSize) % MaxSize;
// 
// 队首指针进一
// front = (front + 1) % MaxSize;
// 
// 队尾指针进一
// rear = (rear + 1) % MaxSize;
// 
// 队空
// q -> rear == q -> front;
// 
// 队满
// (q -> rear + 1) % MaxSize == q -> front;
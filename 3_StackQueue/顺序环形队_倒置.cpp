// 伪代码
#include <iostream>

using namespace std;

#ifndef MaxSize
#define MaxSize 10
#endif

typedef struct
{
	char data[MaxSize];
	int front, rear;
} SqQueue;

// reverse	英[rɪˈvɜ:s]	美[rɪˈvɜ:rs]
// vt.	（使） 反转; （使） 颠倒; 掉换，交换; [法] 撤消，推翻;
// vi.	倒退; [桥牌] 逆叫;
// adj.	反面的; 颠倒的; 倒开的; [生] 倒卷的;
// [例句]	They have made it clear they will not reverse the decision to increase prices
// 			他们已经明确表示不会更改提价的决定。
// [其他]	第三人称单数：reverses 复数：reverses 现在分词：reversing 过去式：reversed 过去分词：reversed
void reverse(SqQueue *q, SqQueue *&r)
{
	r = new SqQueue;
	r -> front = r -> rear = 0;
	// 设q已被正确赋值
	while (q -> data[rear])
	{
		r -> rear = (r -> rear + 1) % MaxSize;
		r -> data[rear] = q -> data[rear];
		q -> rear = (q -> rear - 1) % MaxSize;
	}
}
// 显示后释放q，r
#include <iostream>

using namespace std;

#ifndef MaxSize
#define MaxSize 100
#endif

typedef char ElemType;

// stack	英[stæk]	美[stæk]
// n.	垛，干草堆; （一排） 烟囱; 层积; 整个的藏书架排列;
// vt.	堆成堆，垛; 堆起来或覆盖住; 洗牌作弊; 秘密事先运作;
// [例句]	There were stacks of books on the bedside table and floor.
// 			床头桌和地板上有几摞书。
// [其他]	第三人称单数：stacks 复数：stacks 现在分词：stacking 过去式：stacked 过去分词：stacked
typedef struct
{
	ElemType data[MaxSize];
	int top; // 栈顶指针
} SqStack;

// 初始化
void InitStack (SqStack *&S)
{
	S = new SqStack;
	S -> top = -1; // 栈为空
}

// 销毁栈
void DestroyStack (SqStack *&S)
{
	delete S;
}

// 判断为空
bool StackEmpty (SqStack *S)
{
	return (S -> top == -1);
}

// 进栈(插入元素e)
bool Push (SqStack *&S, ElemType e)
{
	// 满栈
	if (S -> top == MaxSize -1)
	{
		return false;
	}
	// 先加一，到达栈顶的空位置
	S -> top++;
	S -> data[S -> top] = e;
	return true;
}

// pop	英[pɒp]	美[pɑ:p]
// vi.	（意外地、突然地） 出现; 突然出现; 发出爆裂声; （突然地） 行动;
// vt.	（突然地） 伸出; （突然地） 提出问题; （把准备好的东西） 突然拿出来; 敲击;
// n.	流行音乐; 汽水; （尤用作称呼） 爸; （迅速打上的） 记号;
// [例句]	Which great British pop band had a hit with 'In the Army Now'?
// 			英国哪一支伟大的流行乐队以一曲《正在服役》风靡一时？
// [其他]	第三人称单数：pops 复数：pops 现在分词：popping 过去式：popped 过去分词：popped
// 出栈(取出元素e)
bool Pop (SqStack *&S, ElemType &e)
{
	// 空栈
	if (S -> top == -1)
	{
		return false;
	}
	// 先取值，再减一
	e = S -> data[S -> top];
	S -> top--;
	return true;
}

int main(int argc, char const *argv[])
{
	SqStack *S;
	ElemType e;

	InitStack(S);
	cout << "2:Empty:" << StackEmpty(S) << endl;
	Push(S, 'a');
	Push(S, 'b');
	Push(S, 'c');
	Push(S, 'd');
	Push(S, 'e');
	cout << "4:Empty:" << StackEmpty(S) << endl;
	cout << "5:Length:" << S -> top + 1 << endl;
	cout << "6:Elem:" << endl;
	for (int i = 0; i <= S -> top; ++i)
	{
		cout << S -> data[i] << endl;
	}
	cout << "7:Pop:" << endl;
	while (Pop(S, e))
	{
		cout << e << endl;
	}
	cout << "8:Empty:" << StackEmpty(S) << endl;
	DestroyStack(S);

	return 0;
}
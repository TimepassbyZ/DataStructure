#include <iostream>

using namespace std;

typedef char ElemType;

typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
} LiStack;

// 初始化
void InitStack (LiStack *&s)
{
	s = new LiStack;
	s -> next = NULL;
}

// 销毁栈
void DestroyStack (LiStack *&s)
{
	LiStack *pre = s, *p = s -> next;
	while (p != NULL)
	{
		delete pre;
		pre = p;
		p = p -> next;
	}
	delete pre; // 此时指向尾节点
}

// 为空
bool StackEmpty (LiStack *s)
{
	return (s -> next == NULL);
}

// 数据进栈
void Push (LiStack *&s, ElemType e)
{
	LiStack *p;
	p = new LiStack;
	p -> data = e;
	// s为头结点
	p -> next = s -> next;
	s -> next = p;
}

// 数据出栈
bool Pop (LiStack *&s, ElemType &e)
{
	if (s -> next == NULL)
	{
		return false;
	}
	LiStack *p; // 目的是删除出栈的数据节点
	p = s -> next;
	e = p -> data;
	s -> next = s -> next -> next;
	delete p;
	return true;
}

// 求长度
int StackLength (LiStack *s)
{
	LiStack *p = s;
	int length = 0;
	while (p -> next != NULL)
	{
		length++;
		p = p -> next;
	}
	return length;
}

int main(int argc, char const *argv[])
{
	LiStack *s;
	ElemType e;

	InitStack(s);
	cout << "2:Empty:" << StackEmpty(s) << endl;
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	Push(s, 'e');
	cout << "4:Empty:" << StackEmpty(s) << endl;
	cout << "5:Length:" << StackLength(s) << endl;
	cout << "6:Elem:" << endl;
	if (s -> next == NULL)
	{
		cout << "None" << endl;
	}
	else
	{
		LiStack *p = s -> next;
		while (p != NULL)
		{
			cout << p -> data << endl;
			p = p -> next;
		}
	}
	cout << "7:Pop:" << endl;
	while (Pop(s, e))
	{
		cout << e << endl;
	}
	cout << "8:Empty:" << StackEmpty(s) << endl;
	DestroyStack(s);

	return 0;
}
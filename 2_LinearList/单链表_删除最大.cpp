// 删除一个单链表L中元素值最大的节点
#include <iostream>

using namespace std;

#ifndef MaxSize
#define MaxSize 100
#endif

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;

} LinkList;

void InitList (LinkList *&L, ElemType a[], int length)
{
	L = new LinkList;
	L -> next = NULL;
	LinkList *p; // 数据
	LinkList *r = L; // 尾巴
	for (int i = 0; i < length; ++i)
	{
		cout << "input the" << i+1 <<" number" << endl;
		cin >> a[i];

		p = new LinkList;
		p -> data = a[i];
		r -> next = p;
		r = p;
	}
}

void ListDelete (LinkList *&L)
{
	LinkList *p, *pre, *maxp, *maxpre;
	pre = L;
	p = L -> next;
	maxpre = L;
	maxp = L -> next;
	while (p != NULL)
	{
		if (maxp -> data < p -> data)
		{
			maxp = p;
			maxpre = pre;
		}
		p = p -> next;
		pre = pre -> next;
	}
	maxpre -> next = maxp -> next;
	delete maxp;
}

void DispList (LinkList *L)
{
	LinkList *p = L -> next;
	while (p != NULL)
	{
		cout << p -> data << endl;
		p = p -> next;
	}
}

void DeleteList (LinkList *&L)
{
	LinkList *p, *pre;
	p = L -> next;
	pre = L;
	while (p != NULL)
	{
		delete pre;
		pre = p;
		p = pre -> next;
	}
	delete pre;
}

int main(int argc, char const *argv[])
{
	LinkList *L;
	int length;
	cout << "input length:" << endl;
	cin >> length;
	ElemType a[MaxSize];
	InitList(L, a, length); // 直接使用L，代表地址
	ListDelete(L);
	cout << "show:" << endl;
	DispList(L);
	DeleteList(L);
	return 0;
}
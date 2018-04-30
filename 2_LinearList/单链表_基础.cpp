// 单链表
// 1. 初始化单链表h
// 2. 采用尾插法依次插入元素 abcde
// 3. 输出单链表h
// 4. 输出单链表h长度
// 5. 判断单链表h是否为空
// 6. 输出单链表h的第三个元素
// 7. 输出元素a的位置
// 8. 在第四个元素位置上插入元素f
// 9. 输出单链表h
// 10. 删除h的第三个元素
// 11. 输出单链表h
// 12. 释放单链表h
#include <iostream>

using namespace std;

typedef char ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LinkList;

// 头插法
void CreateListF (LinkList *&L, ElemType a[], int n)
{
	// 初始化线性表
	L = new LinkList;
	L -> next = NULL;

	// 头插法
	for (int i = 0; i < n; ++i)
	{
		// 利用s链接到头部L后，其余不变
		LinkList *s;
		s = new LinkList;
		s -> data = a[i];
		s -> next = L -> next; // 保证后续不变，s代表L中第一个数据
		L -> next = s; // L头后跟s，s代表L中第一个数据
		// delete s;
	}
}

// 尾插法
void CreateListR (LinkList *&L, ElemType a[], int n)
{
	L = new LinkList;
	L -> next = NULL;

	// 需要指针r始终指向L的尾部，这样才能插入
	LinkList *r;
	r = L; // 此时L就是尾部，为空链表
	// 同时，也需要一个s存放数据
	for (int i = 0; i < n; ++i)
	{
		LinkList *s;
		s = new LinkList;

		s -> data = a[i]; // s代表L中最后一个数据
		r -> next = s; // 把之前尾部拼接到s，得到新的尾部
		r = s; // 这是新的尾部
		// delete s;
	}
	r -> next = NULL;
}

// 初始化
void InitList (LinkList *&L)
{
	L = new LinkList;
	L -> next = NULL;
}

// 销毁
void DestroyList (LinkList *&L)
{
	// 初始化
	LinkList *pre, *p;
	pre = L;
	p = L -> next;
	// L中的元素一个一个的释放
	while (p != NULL)
	{
		delete pre;
		pre = p; // 指向下一个元素
		p = pre -> next; // 循环往复
	}
	delete pre;
	
}

// 判断是否为空
bool ListEmpty (LinkList *L)
{
	return (L -> next == NULL);
}

// 求数据节点长度
int ListLength (LinkList *L)
{
	LinkList *p;
	p = L;
	int n = 0;
	while (p -> next != NULL)
	{
		n++;
		p = p -> next;
	}
	return n;
}

// 输出线性表
void DispList (LinkList *L)
{
	LinkList *p;
	p = L -> next;
	cout << "Start display:" << endl;
	while (p != NULL)
	{
		cout << p -> data << endl;
		p = p -> next;
	}
	cout << "end display" << endl;
}

// 查找第i个元素
bool GetElem (LinkList *L, int i, ElemType &e)
{
	LinkList *p;
	p = L;
	int j = 0;
	while (j < i && p != NULL)
	{
		j++;
		p = p -> next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p -> data;
		// delete p;
		return true;
	}
}

// 按元素值查找
int LocateElem (LinkList *L, ElemType e)
{
	LinkList *p;
	p = L -> next;
	int i = 1; // 代表第一个元素
	while (p -> data != e && p != NULL)
	{
		p = p -> next;
		i++;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return i;
	}
}

// 插入元素到第i个位置
bool ListInsert (LinkList *&L, int i, ElemType e)
{
	LinkList *p, *s;
	p = L;
	int j = 0; // 0代表头结点
	while (j < i-1 && p != NULL) // 找前驱节点
	{
		j++;
		p = p -> next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		s = new LinkList;
		s -> data = e;
		s -> next = p -> next;
		p -> next = s;
		// delete s;
		return true;
	}
}

// 删除第i个元素
bool ListDelete (LinkList *&L, int i, ElemType &e)
{
	LinkList *p, *q;
	p = L;
	int j = 0;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p -> next;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		q = p -> next; // 为了释放删除的节点
		if (q == NULL)
		{
			return false;
		}
		e = q -> data;
		p -> next = q -> next;
		delete q;
		return true;
	}
}

int main(int argc, char const *argv[])
{
	LinkList *h;
	cout << "1 initial" << endl;
	InitList(h); // 传入L的地址
	cout << "2 insert abcde" << endl;
	ListInsert(h, 1, 'a'); // 在第一个位置插入a
	ListInsert(h, 2, 'b'); 
	ListInsert(h, 3, 'c'); 
	ListInsert(h, 4, 'd'); 
	ListInsert(h, 5, 'e');
	cout << "3 display" << endl;
	DispList(h);
	cout << "4 length" << endl;
	cout << ListLength(h) << endl;
	cout << "5 empty" << endl;
	cout << ListEmpty(h) << endl;
	ElemType e;
	GetElem(h, 3, e);
	cout << "6 3rd:" << e << endl;
	cout << "7 'a' location:";
	cout << LocateElem(h, 'a') << endl;
	cout << "8 insert f" << endl;
	ListInsert(h, 4, 'f');
	cout << "9 display" << endl;
	DispList(h);
	cout << "10 delete 3rd" << endl;
	ListDelete(h, 3, e);
	cout << "11 display" << endl;
	DispList(h);
	cout << "12 destroy" << endl;
	DestroyList(h);
	return 0;
}
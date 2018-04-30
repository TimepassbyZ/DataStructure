// 输入一个到头节点的单链表L = {a1，b1，a2，b2...an，bn}
// 拆分成L1 = {a1，a2...} L2 = {bn，bn-1...}
// L1使用L的头结点
#include <iostream>

using namespace std;
typedef int ElemType;
#ifndef MaxSize
#define MaxSize 100
#endif

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkList;

// 尾插法
void CreateList (LinkList *&L, ElemType a[], int length)
{
	LinkList *p, *r; // p数据；r尾巴
	L = new LinkList;
	r = L;
	for (int i = 0; i < length; ++i)
	{
		p = new LinkList;
		p -> data = a[i];
		r -> next = p; // 把p拼接到r后面
		r = p;
		cout << p -> data << endl;
	}
	r -> next = NULL;
	// 这里不能有 delete p; 
}

// split	英[splɪt]	美[splɪt]
// vt.	分裂; 分开; <俚>（迅速）离开; 分担;
// n.	划分; 分歧; 裂缝; 劈叉;
// vi.	<俚>走开; 揭发; 被撞碎; <美>[证券]（股票）增加发行;
// [例句]	In a severe gale the ship split in two
// 			在一次大风中，船断成了两截。
// [其他]	第三人称单数：splits 复数：splits 现在分词：splitting 过去式：split 过去分词：split
void split (LinkList *&L, LinkList *&L1, LinkList *&L2)
{
	LinkList *Lp, *L1r, *L2p;

	// 初始化L1
	L1 = L;

	// 初始化L2
	L2 = new LinkList;
	L2 -> next = NULL;

	Lp = L -> next; // L的数据
	L1r = L1; // L1的尾巴
	while (Lp != NULL)
	{
		// L1 = {a1，a2...}
		// 尾插法(先进的在前面)
		L1r -> next = Lp;
		L1r = Lp;

		// 数据后移
		Lp = Lp -> next;

		// L2 = {bn，bn-1...}
		// 头插法(先进的在后面)
		L2p = Lp -> next; // L2p暂存Lp的后续(原数据)
		Lp -> next = L2 -> next; // 产生插入后的除头结点的数据链
		L2 -> next = Lp; // 数据链拼到L2头结点后面
		Lp = L2p; // 归还原数据
	}
	L1r -> next = NULL;
}

void DispList (LinkList *L)
{
	LinkList *p;
	p = L -> next;
	while (p != NULL)
	{
		cout << p -> data << endl;
		p = p -> next;
	}
}

void DestroyList (LinkList *&L)
{
	LinkList *pre, *p;
	pre = L;
	p = L -> next;
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
	// 初始化L
	LinkList *L;

	// 输入数据
	int length;
	ElemType a[MaxSize];
	cout << "input an !even! length:" << endl;
	cin >> length;
// even	英[ˈi:vn]	美[ˈivən]
// adv.	甚至; 即使; 更加; 恰巧在…时候;
// adj.	公平的; 平坦的; 偶数的; 平均的;
// vt.	使平坦; 使相等;
// [例句]	He kept calling me for years, even after he got married
// 		多年来他一直打电话给我，甚至是在他结婚以后。
// [其他]	第三人称单数：evens 现在分词：evening 过去式：evened 过去分词：evened
	for (int i = 0; i < length; ++i)
	{
		cout << "input data[" << i << "]:" << endl;
		cin >> a[i];
	}
	
	CreateList(*&L, a, length);
	// DispList(L);

	LinkList *L1, *L2;
	split(L, L1, L2);

	cout << "display L1:" << endl;
	DispList(L1);
	cout << "display L2:" << endl;
	DispList(L2);

	DestroyList(L);
	DestroyList(L1);
	DestroyList(L2);
	return 0;
}
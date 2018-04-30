// 排列为递增有序
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
} LinkList;

void InitList (LinkList *&L, ElemType a[], int length)
{
	L = new LinkList;
	L -> next = NULL;
	LinkList *p, *r;	
	r = L;
	for (int i = 0; i < length; ++i)
	{
		cout << "input " << i+1 << " number" << endl;
		cin >> a[i];

		p = new LinkList;
		p -> data = a[i];
		r -> next = p;
		r = p;
	}

}

void RankList (LinkList *&L, LinkList *&L1)
// rank	英[ræŋk]	美[ræŋk]
// n.	军衔; 阶层，等级; 次序，顺序; 行列;
// vt.	排列，使成横排; 把…分类;
// vt.	排列; 超过，高于; 把…分等级;
// [例句]	He eventually rose to the rank of captain
// 			他终于升职当上了船长。
// [其他]	比较级：ranker 最高级：rankest 第三人称单数：ranks 复数：ranks 现在分词：ranking 过去式：ranked 过去分词：ranked

// sort	英[sɔ:t]	美[sɔ:rt]
// n.	分类，类别; 品质，本性; 方法; 一群;
// vt.	分类; 整顿，整理; 适合;
// vt.	挑选; 把…分类; 将…排顺序;
// [例句]	What sort of school did you go to?
// 			你上的是哪类学校？
// [其他]	第三人称单数：sorts 复数：sorts 现在分词：sorting 过去式：sorted 过去分词：sorted
{
	LinkList *p, *q, *pre;
	p = L -> next -> next; // 第二个节点
	L -> next -> next = NULL;
	while (p != NULL)
	{
		// p位于原L上，pre位于新L上
		q = p -> next; // 第三个节点，保存原L上的数据
		pre = L; // 头结点
		// 寻找插入点的前驱节点
		while (pre -> next != NULL && pre -> next -> data < p -> data)
		{
			pre = pre -> next;
		}
		p -> next = pre -> next;
		pre -> next = p;
		p = q;
	}
}

void DispList (LinkList *L)
{
	LinkList *p = L -> next;
	cout << "Display:" << endl;
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
		p = p -> next;
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
	InitList(L, a, length);
	LinkList *L1;
	RankList(L, L1);
	DispList(L);
	DeleteList(L);
	return 0;
}
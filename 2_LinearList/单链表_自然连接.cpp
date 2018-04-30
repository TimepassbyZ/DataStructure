#include <iostream>

using namespace std;
// row	英[rəʊ]	美[roʊ]
// n.	划船; 行，排; 吵闹; 路，街;
// vt.	划船; 使…成排; 与…进行划船比赛; 〈口〉争吵，吵闹;
// [例句]	Several men are pushing school desks and chairs into neat rows.
// 			几个人正挪动学校的桌椅，将它们排整齐。
// [其他]	第三人称单数：rows 复数：rows 现在分词：rowing 过去式：rowed 过去分词：rowed

// column	英[ˈkɒləm]	美[ˈkɑ:ləm]
// n.	专栏; 圆柱; 纵队，列;
// [例句]	There were reports of columns of military vehicles appearing on the streets.
// 		有报道说几队军用车辆出现在街头。
// [其他]	复数：columns
#ifndef MaxCol
#define MaxCol 10
#endif

#ifndef MaxSize
#define MaxSize 100
#endif

typedef int ElemType;

// 数据节点
typedef struct Node
{
	ElemType data[MaxSize];
	struct Node *next;
} LinkList;

// 头结点
typedef struct HeadNode
{
	int row, col;
	LinkList *next;
} HeadList;

// 输入数据
void Input (HeadList *&L)
{
	// 初始化头结点
	L = new HeadList;
	L -> next = NULL; // 第一个数据置空

	cout << "input row:" << endl;
	cin >> L -> row;
	cout << "input col:" << endl;
	cin >> L -> col;

	LinkList *s, *r;
	for (int i = 0; i < L -> row; ++i)
	{
		// 存储一行的数据
		s = new LinkList;
		cout << "input row" << i + 1 << " data:" << endl;
		for (int j = 0; j < L -> col; ++j)
		{		
			cin >> s -> data[j];
		}
		if (L -> next == NULL)
		{
			L -> next = s; // 插入第一个数据节点
		}
		else
		{
			r -> next = s;
		}
		// 不能直接用 r -> next = s; 要分类，因为头结点和数据节点类型不同
		r = s;
	}
	r -> next = NULL;
}

void Destroy (HeadList *&L)
{
	LinkList *s, *pre;
	pre = L -> next;
	s = pre -> next;
	while (s != NULL)
	{
		delete pre;
		pre = s;
		s = s -> next;
	}
	delete pre;
	delete L;
}

void Display (HeadList *L)
{
	LinkList *s;
	s = L -> next;
	while (s != NULL)
	{
		for (int i = 0; i < L -> col; ++i)
		{
			cout << s -> data[i] << " ";
		}
		cout << endl;
		s = s -> next;
	}
}

void Link (HeadList *L1, HeadList *L2, HeadList *&L)
{
	int colA, colB; 
	cout << "input A's col:" << endl;
	cin >> colA;
	cout << "input B's col:" << endl;
	cin >> colB;

	// 初始化生成链表L
	L = new HeadList;
	L -> row = 0;
	L -> col = L1 -> col + L2 -> col;
	L -> next = NULL;

	LinkList *p = L1 -> next;
	LinkList *q, *s, *r;
	while (p != NULL)
	{
		q = L2 -> next;
		while (q != NULL)
		{
			if (p -> data[colA - 1] == q -> data[colB - 1])
			{
				s = new LinkList;
				for (int i = 0; i < L1 -> col; ++i)
				{
					s -> data[i] = p -> data[i];
				}
				for (int i = 0; i < L2 -> col; ++i)
				{
					s -> data[L1 -> col + i] = q -> data[i];
				}
				if (L -> next == NULL)
				{
					L -> next = s;
				}
				else
				{
					r -> next = s;
				}
				r = s;
				L -> row++;
			}
			q = q -> next;
		}
		p = p -> next;
	}
	r -> next = NULL;
}

int main(int argc, char const *argv[])
{
	HeadList *L1, *L2, *L;
	cout << "A:" << endl;
	Input(L1);
	cout << "B:" << endl;
	Input(L2);
	Display(L1);
	Display(L2);
	Link(L1, L2, L);
	cout << "result:" << endl;
	Display(L);
	Destroy(L1);
	Destroy(L2);
	Destroy(L);
	return 0;
}
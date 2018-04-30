// 顺序表
// 1. 初始化顺序表L
// 2. 采用尾插法依次插入元素 abcde
// 3. 输出顺序表L
// 4. 输出顺序表L长度
// 5. 判断顺序表L是否为空
// 6. 输出顺序表L的第三个元素
// 7. 输出元素a的位置
// 8. 在第四个元素位置上插入元素f
// 9. 输出顺序表L
// 10. 删除L的第三个元素
// 11. 输出顺序表L
// 12. 释放顺序表L
#include <iostream>

using namespace std;

typedef char ElemType;
#ifndef Max
#define MaxSize 100
#endif

// 顺序表的结构体定义
typedef struct
{
	ElemType data[MaxSize];
	int length;
} SqList;

// 建立顺序表
void CreateList (SqList *&L, ElemType a[], int n)
{
	L = new SqList;
	for (int i = 0; i < n; ++i)
	{
		L -> data[i] = a[i];
	}
	L -> length = n;
}

//初始化线性表
void InitList (SqList *&L)
{
	L = new SqList;
	L -> length = 0;
}

// 销毁线性表
void DestroyList (SqList *&L)
{
	delete(L);
}

// 判断是否为空
bool ListEmpty (SqList *L)
{
	return (L -> length == 0);
}

// 求长度
int ListLength (SqList *L)
{
	return (L -> length);
}

// 输出线性表
void DispList (SqList *L)
{
	for (int i = 0; i < L -> length; ++i)
	{
		cout << L -> data[i] << endl;
	}
}

// 按位置查找(用e返回第i个元素的值)
bool GetElem (SqList *L, int i, ElemType &e)
{
	if (i < 1 || i > L -> length)
	{
		return false;
	}
	e = L -> data[i - 1];
	return true;
}

// 按元素值查找
int LocateElem (SqList *L, ElemType e)
{
	int i = 0;
	while (i < L ->length && L -> data[i] != e)
	{
		i++;
	}
	if (i >= L -> length)
	{
		return 0;
	}
	else
	{
		return i + 1;
	}
}

// 插入
bool ListInsert (SqList *&L, int i, ElemType e)
{
	if (i < 1 || i > L -> length + 1)
	{
		return false;
	}
	i--; // 将顺序表逻辑序号转化为物理序号
	for (int j = L -> length; j > i; --j)
	{
		L -> data[j] = L -> data[j - 1]; // 将data[i]及后面元素后移一个位置
	}
	L -> data[i] = e;
	L -> length++;
	return true;
}

// 删除
bool ListDelete (SqList *&L, int i, ElemType &e)
{
	if (i < 1 || i > L -> length)
	{
		return false;
	}
	i --; // 将顺序表逻辑序号转化为物理序号
	e = L -> data[i];
	for (int j = i; j < L -> length - 1; ++j)
	{
		L -> data[j] = L -> data[j + 1]; // 将data[i]及前面元素前移一个位置
	}
	L -> length--;
	return true;
}

int main(int argc, char const *argv[])
{
	SqList *L; // 声明一个SQ类型的指针
	cout << "1 initial" << endl;
	InitList(L); // 传入L的地址
// initial	英[ɪˈnɪʃl]	美[ɪˈnɪʃəl]
// adj.	最初的; 开始的; 首字母的;
// n.	首字母; [语音学] 声母; 特大的大写字母;
// vt.	用姓名的首字母签名;
// [例句]	The initial reaction has been excellent
// 			初期的反应非常好。
// [其他]	第三人称单数：initials 复数：initials 现在分词：initialling 过去式：initialled 过去分词：initialled
	cout << "2 insert abcde" << endl;
	ListInsert(L, 1, 'a'); // 在第一个位置插入a
	ListInsert(L, 2, 'b'); 
	ListInsert(L, 3, 'c'); 
	ListInsert(L, 4, 'd'); 
	ListInsert(L, 5, 'e');
	cout << "3 display" << endl;
	DispList(L);
	cout << "4 length" << endl;
	cout << ListLength(L) << endl;
	cout << "5 empty" << endl;
	cout << ListEmpty(L) << endl;
	ElemType e;
	GetElem(L, 3, e);
	cout << "6 3rd:" << e << endl;
	cout << "7 'a' location:";
	cout << LocateElem(L, 'a') << endl;
	cout << "8 insert f" << endl;
	ListInsert(L, 4, 'f');
	cout << "9 display" << endl;
	DispList(L);
	cout << "10 delete 3rd" << endl;
	ListDelete(L, 3, e);
	cout << "11 display" << endl;
	DispList(L);
	cout << "12 destroy" << endl;
	DestroyList(L);
	return 0;
}
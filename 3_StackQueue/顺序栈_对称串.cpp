#include <iostream>

using namespace std;

typedef char ElemType;

#ifndef MaxSize
#define MaxSize 100
#endif

typedef struct
{
	ElemType data[MaxSize];
	int top;
} SqStack;

void Input (SqStack *&s, int length, ElemType a[])
{
	s = new SqStack;
	s -> top = -1;
	for (int i = 0; i < length; ++i)
	{
		s -> top ++;
		cout << "input " << i+1 << " data:" << endl;
		cin >> a[i];
		s -> data[s -> top] = a[i];
	}
}

bool Pop (SqStack *&s, int length, ElemType a[])
{
	for (int i = 0; i < length; ++i)
	{
		if(a[i] != s -> data[s -> top])
		{
			s -> top --;
			return false;
		}
		s -> top --;
	}
	return true;
}

void DestroyStack (SqStack *&s)
{
	delete s;
}

int main(int argc, char const *argv[])
{
	SqStack *s;
	int length;
	ElemType a[MaxSize];
	cout << "input length:" << endl;
	cin >> length;
	Input(s, length, a);
	cout << "symmetry? :" << Pop(s, length, a) << endl;
	DestroyStack(s);
	return 0;
}
// symmetry	英[ˈsɪmətri]		美[ˈsɪmɪtri]
// n.	对称; 对称美; 整齐，匀称;
// [例句]	I loved the house because it had perfect symmetry
// 			我喜欢这所房子，因为它非常对称。
// [其他]	复数：symmetries

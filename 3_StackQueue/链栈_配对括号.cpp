#include <iostream>
#include <cstring>

using namespace std;

typedef char ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
} LiStack;

bool match (LiStack *&s)
{
	string str;
	cout << "input math str:" << endl;
	// 输入数学表达式
	cin >> str;
	LiStack *p;
	for (int i = 0; i < (int)str.length(); ++i)
	{
		// “(”进栈
		if (str[i] == '(')
		{
			p = new LiStack;
			p -> data = '(';
			p -> next = s -> next;
			s -> next = p;
		}
		if (str[i] == ')')
		{
			// “)”无匹配报错
			if (s -> next == NULL)
			{
				return false;
			}
			// “)”有匹配，出栈一个“(”
			else
			{
				p = s -> next;
				s -> next = s -> next -> next;
				delete p;
			}
		}
	}
	// 最后栈内存在元素“(”报错
	if (s -> next != NULL)
	{
		return false;
	}
	return true;
}

void DestroyStack (LiStack *&s)
{
	LiStack *p = s -> next, *pre = s;
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
	LiStack *s;
	s = new LiStack;
	s -> next = NULL;
	cout << "the result:" << match(s) << endl;
	DestroyStack(s);
	return 0;
}
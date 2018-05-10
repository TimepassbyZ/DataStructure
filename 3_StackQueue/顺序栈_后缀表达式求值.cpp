// 程序有误！
#include <iostream>

using namespace std;

#ifndef MaxSize
#define MaxSize 100
#endif

// 运算“a Op b”
int op (int a, char Op, int b)
{
	if (Op == '+')
	{
		return a + b;
	}
	if (Op == '-')
	{
		return a - b;
	}
	if (Op == '*')
	{
		return a * b;
	}
	if (Op == '/')
	{
		if (b == 0)
		{
			cout << "err!!!" << endl;
			return 0;
		}
		else
		{
			return a / b;
		}
	}
}

// 计算后缀表达式
int com (char exp[])
{
	int stack[MaxSize];
	int top = -1;

	char Op;
	int a, b, c;
	for (int i = 0; exp[i] != '\0'; ++i)
	{
		// 操作数
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			stack[++top] = exp[i] - '0';
		}
		// 运算符
		else
		{
			Op = exp[i];
			b = stack[top--]; // 先出栈的是第二个操作数
			a = stack[top--];
			c = op(a, Op, b);
			stack[++top] = c;
		}
	}
	return stack[top];
}

int main(int argc, char const *argv[])
{
	// 操作数均只有一位，(6-2)/(1+3)
	char exp[] = {6, 2, '-', 1, 3, '+', '/'};
	cout << "result:" << com(exp) << endl;
	return 0;
}
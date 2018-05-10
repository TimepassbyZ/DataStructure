#include <iostream>
#include <windows.h>

using namespace std;

#ifndef MaxSize
#define MaxSize 100
#endif

#ifndef MaxOp
#define MaxOp 7
#endif

// 设定运算符优先级
struct node
{
	char ch; // 运算符
	int pri; // 优先级
}	lpri[] = {{'=', 0}, {'(', 1}, {'*', 5}, {'/', 5}, {'+', 3}, {'-', 3}, {')', 6}},
	rpri[] = {{'=', 0}, {'(', 6}, {'*', 4}, {'/', 4}, {'+', 2}, {'-', 2}, {')', 1}};
// 求左运算符优先级
int leftpri (char op)
{
	for (int i = 0; i < MaxOp; ++i)
	{
		if (lpri[i].ch == op)
		{
			return lpri[i].pri;
		}
	}
	cout << "leftpri-1" << endl;
	return -1;
}
// 求右运算符优先级
int rightpri (char op)
{
	for (int i = 0; i < MaxOp; ++i)
	{
		if (rpri[i].ch == op)
		{
			return rpri[i].pri;
		}
	}
	cout << "rightpri-2" << endl;
	return -2;
}
// 判断ch是否位运算符
bool InOp (char ch)
{
	if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}
// precede	英[prɪˈsi:d]	美[prɪˈsid]
// vt.	在…之前发生或出现，先于; 在…之上，优于; 给…作序; 处于…前面的位置;
// [例句]	Intensive negotiations between the main parties preceded the vote
// 			主要政党在选举前进行了集中的谈判。
// [其他]	第三人称单数：precedes 现在分词：preceding 过去式：preceded 过去分词：preceded
// 比较运算符优先级
int Precede (char op1, char op2)
{
	if (leftpri(op1) == rightpri(op2))
	{
		return 0;
	}
	else if (leftpri(op1) < rightpri(op2))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
// 转为后缀表达式
void trans (char *exp, char postexp[])
{
	// 运算符栈
	struct
	{
		char data[MaxSize];
		int top;
	} op;
	int i = 0; // i为postexp下标
	op.top = -1;
	// "="进栈
	op.top++;
	op.data[op.top] = '=';
	while (*exp != '\0')
	{
		if (!InOp(*exp)) // 为数字字符的情况
		{
			// 判定为数字
			while (*exp >= '0' && *exp <= '9')
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#'; // 用“#”标识一个数值串结束
		}
		else // 为运算符的情况
		{
			switch (Precede (op.data[op.top], *exp))
			{
				// 栈顶运算符的优先级低
				case -1:
					op.top++;
					op.data[op.top] = *exp;
					exp++; // 继续扫描其他字符
					break;
				// 只有括号满足这种情况
				case 0:
					op.top--; // 将“(”退栈
					exp++; // 继续扫描其他字符
					break;
				// 退栈并输出到postexp中
				case 1:
					postexp[i++] = op.data[op.top];
					op.top--;
					break;
			}
		}
	}
	// 此时exp扫描完毕，退栈到“=”为止
	while (op.data[op.top] != '=')
	{
		postexp[i++] = op.data[op.top];
		op.top--;
	}
	// 给postexp表达式添加结束标志
	postexp[i] = '\0';
}
// 求后缀表达式
float compvalue (char *postexp)
{
	struct
	{
		float data[MaxSize];
		int top;
	} st;
	float d, a, b, c;
	st.top = -1;
	while (*postexp != '\0')
	{
		switch (*postexp)
		{
			case '+':
				a = st.data[st.top];
				st.top--;
				b = st.data[st.top];
				st.top--;
				c = a + b;
				st.top++;
				st.data[st.top] = c;
				break;
			case '-':
				a = st.data[st.top];
				st.top--; // 先出栈的为第二个操作数
				b = st.data[st.top];
				st.top--;
				c = b - a;
				st.top++;
				st.data[st.top] = c;
				break;
			case '*':
				a = st.data[st.top];
				st.top--;
				b = st.data[st.top];
				st.top--;
				c = a * b;
				st.top++;
				st.data[st.top] = c;
				break;
			case '/':
				a = st.data[st.top];
				st.top--;
				b = st.data[st.top];
				st.top--;
				if (a != 0)
				{
					c = b / a;
					st.top++;
					st.data[st.top] = c;
				}
				else
				{
					cout << "err!!!" << endl;
					exit(0); // 异常退出
				}
				break;
			default:
				d = 0;
				while (*postexp >= '0' && *postexp <= '9')
				{
					d = 10 * d + *postexp - '0';
					postexp++;
				}
				st.top++;
				st.data[st.top] = d;
				break;
		}
		postexp++;
	}
	return (st.data[st.top]);
}

int main(int argc, char const *argv[])
{
	char exp[] = "(56-20)/(4+2)"; // 输入不带空格
	char postexp[MaxSize];
	trans(exp,postexp);
	cout << "middle:" << exp << endl;
	cout << "after:" << postexp << endl;
	cout << "value:" << compvalue(postexp) << endl;
	return 0;
}

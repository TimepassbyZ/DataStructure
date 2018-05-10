#include <iostream>
#include <cstring>

#ifndef MaxSize
#define MaxSize 100
#endif

using namespace std;

bool match (string str)
{
	// 定义栈存放“(”
	char stack[MaxSize];
	int top = -1;

	for (int i = 0; i < (int)str.length(); ++i)
	{
		if (str[i] == '(')
		{
			stack[++top] = '(';
		}
		if (str[i] == ')')
		{
			if (top == -1)
			{
				return false;
			}
			else
			{
				--top;
			}
		}
	}
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	cout << "input str:" << endl;
	string str;
	cin >> str;
	cout << "result:" << match(str) << endl;
	return 0;
}
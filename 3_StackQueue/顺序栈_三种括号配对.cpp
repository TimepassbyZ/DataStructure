#include <iostream>
#include <cstring>
using namespace std;

typedef char ElemType;

#ifndef MaxSize
#define MaxSize 10
#endif

typedef struct
{
	ElemType data[MaxSize];
	int top;
} SqStack;


// judge	英[dʒʌdʒ]	美[dʒʌdʒ]
// vt.	审判，评判; 断定;
// vt.	评价; 估计; （尤指） 批评; 想，认为;
// n.	法官; 裁判员; 评判员; 鉴定人;
// [例句]	A panel of judges is now selecting the finalists.
// 			评判小组现在正选拔参加决赛的选手。
// [其他]	第三人称单数：judges 复数：judges 现在分词：judging 过去式：judged 过去分词：judged
bool judge (string str)
{
	ElemType p[MaxSize], q[MaxSize], r[MaxSize];
	int ptop = -1, qtop = -1, rtop = -1;

	for (int i = 0; i < (int)str.length(); ++i)
	{
		switch (str[i])
		{
			case '(':
			{
				p[++ptop] == '(';
				break;
			}
			case ')':
			{
				if (ptop == -1)
				{
					return false;
				}
				else
				{
					--ptop;
					break;
				}
			}
			case '[':
			{
				q[++qtop] == '(';
				break;
			}
			case ']':
			{
				if (qtop == -1)
				{
					return false;
				}
				else
				{
					--qtop;
					break;
				}
			}
			case '{':
			{
				r[++rtop] == '(';
				break;
			}
			case '}':
			{
				if (rtop == -1)
				{
					return false;
				}
				else
				{
					--rtop;
					break;
				}
			}
			default:
			{
				break;
			}
		} // switch END
	} // for END
	if (ptop == -1 && qtop == -1 && rtop == -1)
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
	cout << "input string:" << endl;
	string str;
	cin >> str;
	cout << "result:" << judge(str) << endl;
	return 0;
}
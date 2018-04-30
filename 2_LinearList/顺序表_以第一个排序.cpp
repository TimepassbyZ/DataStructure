// 以数组第一个数为基准，<=的它排前面，>的排它后面
#include <iostream>

using namespace std;
#ifndef MaxSize
#define MaxSize 100
#endif

int main(int argc, char const *argv[])
{
	int length;
	cout << "input array length:" << endl;
	cin >> length;
	int a[MaxSize];

	for (int i = 0; i < length; ++i)
	{
		cout << "input a[" << i << "]:" << endl;
		cin >> a[i];
	}

	int base = a[0];
	int i = 0, j = length - 1; // i头j尾
	while (i < j) 
	{
		// 从后面找小的可以放在a[0]处
		while (i < j && a[j] > base) // i < j必须有
		{
			j--; // 过滤满足条件的元素
		}
		a[i] = a[j]; // 第一个不满足条件的放入左边
		i++; // 从左边的下一个开始过滤满足条件的
		while (i < j && a[i] <= base)
		{
			i++;
		}
		a[j] = a[i];
		j--;
	}
	// 最后把base放入左边的a[i]
	a[i] = base;

	cout << "disp:" << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << "a[" << i <<"]:" << a[i] << endl;
	}
	return 0;
}
// 求素数-普通筛选法--埃拉托斯特尼筛法
// 时间复杂度：O(NloglogN)
// 原理：素数的倍数一定不是素数
// （1）先把1删除（现今数学界1既不是质数也不是合数）
// （2）读取队列中当前最小的数2，然后把2的倍数删去
// （3）读取队列中当前最小的数3，然后把3的倍数删去
// （4）读取队列中当前最小的数5，然后把5的倍数删去
// （5）如上所述直到需求的范围内所有的数均删除或读取
// 注：此处的队列并非数据结构队列，如需保留运算结果，处于存储空间的充分利用以及大量删除操作的实施，建议采用链表的数据结构。

// 思路：用一个bool数组，存储n个数的状态，初始化都为true，
// 然后从2开始，如果2的状态为true，就开始遍历比n小的所有的2的倍数，将其全部置为false。
// 把2的倍数遍历完后，继续往下找下一个状态为true的数，
// 即3，遍历比n小的所有的3的倍数（按3*3，3*4，3*5这样遍历，注意不需要从3*2开始了）。
// .....
// 最后剩下的状态为true的数全为质数。

// filter	英[ˈfɪltə(r)]	美[ˈfɪltɚ]
// n.	滤波器; 滤光器; 滤色镜; [化] 过滤器;
// vi.	过滤; 透过; 渗透;
// vt.	过滤; 滤除;
// [例句]	The best prevention for cholera is to boil or filter water, and eat only well-cooked food.
// 			预防霍乱的最佳方法是将水煮沸或过滤，并且只食用煮熟后的食物。
// [其他]	第三人称单数：filters 复数：filters 现在分词：filtering 过去式：filtered 过去分词：filtered

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int max;
	cout << "input max:" << endl;
	cin >> max;
	if (max <=1)
	{
		return 0; // 小于等于1的都不是质数
	}
	bool *a = new bool[max+1]; // 指针变量名 = new 类型[长度]
	// bool *a;
	// a = new bool[n+1];
	// a[0]是0的状态，a[1]是1的状态...a[max]是max的状态
	a[0] = false;
	a[1] = false; // 排除0和1
	for (int i = 2; i <= max; ++i) // 取等
	{
		a[i] = true; // 对数组的每个数字的布尔值初始化
	}
	for (int i = 2; i <= max; ++i)
	// for (int i = 2; i * i < max; ++i)
	{
		if (a[i])
		{
			for (int j = i; i * j <= max; ++j)
			// i*j是数值
			{
				a[i*j] = false; // “删除”i的倍数数字
			}
		}
	}
	cout << "prime number lists:" << endl;
	int num = 0;
	for (int i = 0; i <= max; ++i)
	{
		if (a[i])
		{
			num++;
			cout << i << endl; // i是数值，a[i]是状态
		}
	}
	cout << "prime num:" << num << endl;
	
	return 0;
}
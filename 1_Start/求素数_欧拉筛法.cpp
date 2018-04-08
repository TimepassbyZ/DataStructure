// 求素数-线性筛法(欧拉筛法)
// 时间复杂度：O(N)

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
	int num = 0, b[max]; // b[用于保存素数]
	for (int i = 2; i <= max; ++i)
	// for (int i = 2; i * i < max; ++i)
	{
		if (a[i])
		{
			b[num++] = i; // 将这句话放在下面的循环前以保证num和b[]值的完整性
		}
		for (int j = 0; j < num; ++j)
		{
			if (i * b[j] > max)
			{
				break; // 超跳出过最大范围
			}
			a[i * b[j]] = false; // “删除”倍数
			if (i % b[j] == 0)
			{
				break; // 保证只筛到以b[j]为最小质因数的数
			}
		}
	}
// 首先，先明确一个条件，任何合数都能表示成一系列素数的积。
// 然后利用了每个合数必有一个最小素因子，每个合数仅被它的最小素因子筛去正好一次，所以为线性时间。
// 代码中体现在：
// if(i%prime[j]==0)break;
// prime数组中的素数是递增的,当 i 能整除 prime[j]，那么 i*prime[j+1] 这个合数肯定被 prime[j] 乘以某个数筛掉。
// 因为i中含有prime[j], prime[j] 比 prime[j+1] 小。接下去的素数同理。所以不用筛下去了。
// 在满足i%prme[j]==0这个条件之前以及第一次满足改条件时,prime[j]必定是prime[j]*i的最小因子。
	cout << "prime number lists:" << endl;
	for (int i = 0; i < num; ++i)
	{

		cout << b[i] << endl; // i是数值，a[i]是状态

	}
	cout << "prime num:" << num << endl;
	
	return 0;
}
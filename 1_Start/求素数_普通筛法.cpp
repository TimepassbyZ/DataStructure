// 求素数-平方根法
// 假设N是一个合数，则有 N = a * b，且a，b之中总有一个小于或等于根号n
// 例如，假设a <= b，则有 a*a <= a*b = n，两边开平方，就有 a <= sqrt(n) 了
#include <iostream>
#include <cmath>

using namespace std;

// prime number
// 英[praim ˈnʌmbə]	美[praɪm ˈnʌmbɚ]
// n.	质数，素数;
// [例句]	It's a one, it's a prime number.
// 			这是数字一，它是个质数。
// [其他]	复数：prime numbers

// SQRT	
// [词典]	[计] = SQuare RooT,平方根;

int main(int argc, char const *argv[])
{
	int max, each, num;
	cout << "input max(max > 2):" << endl;
	cin >> max;
	cout << "prime number lists:" << endl;
	for (each = 2, num = 0; each <= max; ++each) // 对每一个数字each进行判断(1既不是质数也不是合数)
	{
		int i;
		for (i = 2; i <= (int)sqrt(each); ++i) // 判断每个数字的模，直到根号each
		// sqrt(each) 需要用int强制转换取整数部分
		{
			if (each % i == 0)
			{
				break; // 是合数就跳出，判断下一个数
				// cout << each << endl;
				// num++；
				// 这段注释代码错误，必须都满足才能进行计数器加一
			}
		}
		if (i > (int)sqrt(each)) // 如果最终这个判断值大于了根号each，则这个数each一定是质数
		{
			num++;
			cout << each << endl;
		}
	}
	cout << "prime num:" << num << endl;

	return 0;
}
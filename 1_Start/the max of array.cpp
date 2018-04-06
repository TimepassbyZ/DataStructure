#include <iostream>

using namespace std;

#ifndef MAX
#define MAX 100
#endif

int max (int a[MAX], int n)//记得写形参类型（如int）
{
	int max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	int a[MAX], n;
	cout << "input n:" << endl;
	cin >> n;
	cout << "input array:" << endl;	
// array	英[əˈreɪ]	美[ə'reɪ]
// n.	数组; 队列，阵列; 一大批; 衣服;
// vt.	排列; 部署兵力; 打扮，装饰;
// [例句]	As the deadline approached she experienced a bewildering array of emotions
// 			随着最后期限的临近，她开始心绪纷乱，不知所措。
// [其他]	第三人称单数：arrays 复数：arrays 
// 			现在分词：arraying 过去式：arrayed 
// 			过去分词：arrayed
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "the largest:" << max(a, n) << endl;
	return 0;
}
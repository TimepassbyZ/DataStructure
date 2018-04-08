//判断回文
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cout << "input string:" << endl;
	cin >> str;

	int len = str.length();
	bool b = true;
	// cout << str[len]; 最后一位是/0
	for (int i = 0; i <= len / 2; ++i)
	{
		if (str[i] != str[len - i - 1]) // 12321/0
		{
			b = false;
			cout << "no" << endl;
			break;
		}
	}
	if (b)
	{
		cout << "yes" << endl;
	}
	return 0;
}
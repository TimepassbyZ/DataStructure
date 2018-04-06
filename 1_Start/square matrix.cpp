// 求两个n阶方阵的和 C = A + B;
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef MAX
#define MAX 100
#endif

void input (int a[MAX][MAX], int n)
//在被调用函数中对形参数组定义时可以指定所有维数的大小，
//也可以省略第一维的大小说明,
//但是不能把第二维或者更高维的大小省略,
//也不能只指定一维而不指定第二维。
//另外，实参数组维数可以大于形参数组，
//这时，形参数组只取实参数组的一部分，其余部分不起作用。
//数组越界问题应该避免，即：形参数量 = 实参数量。
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
			//cin >>
			//cout <<
		}
	}
}

void sum (int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int n)
//每个形参都必须要有数据类型（如，都要写int）
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c[i][j] = a[i][j] + b[i][j];
			// cout << "aaa" << endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "input n:" << endl;
	cin >> n;
	int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
	cout << "input first square matrix" << endl;
	input(a, n);
	cout << "input second square matrix" << endl;
	input(b, n);
// matrix	英[ˈmeɪtrɪks]	美[ˈmetrɪks]
// n.	基质; <数>矩阵; 模型; 母体，子宫;
// [例句]	The basis matrix B is unimodular.
// 			基矩阵b是幺模的。
// [其他]	复数：matrices
	sum(a, b, c, n);
	cout << "sum:" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << setw(5) << c[i][j] << ' ';
			// cout << "bbb" << endl;
			// setw()设置字段宽度,
			// 在头文件<iomanip>中声明.
		}
		cout << endl;
	}
	return 0;
}
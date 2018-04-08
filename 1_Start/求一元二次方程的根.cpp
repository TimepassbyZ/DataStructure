//求一元二次方程ax²+bx+c=0（a≠0）的根
//中文乱码
#include <iostream>
#include <cmath>

using namespace std;
// void calculate (float a, float b, float c);

void calculate (float a, float b, float c)
// calculate	英[ˈkælkjuleɪt]		美[ˈkælkjəˌlet]
// vt.	计算; 估计; 打算，计划; 旨在;
// vt.	预测，推测;
// [例句]	From this you can calculate the total mass in the Galaxy
// 			由此你可以算出银河系的总质量。
// [其他]	第三人称单数：calculates 现在分词：calculating 过去式：calculated 过去分词：calculated
{
	float d, x, y;
	d = b * b - 4 * a * c;
	if (d > 0)
	{
		x = (-b + sqrt(d)) / (2 * a);
		y = (-b - sqrt(d)) / (2 * a);
		cout << "two:" << x << "and" << y << endl;
	}
	else if (d < 0)
	{
		cout << "none" << endl;
	}
	else //这里不写条件(d = 0)
	{
		x = (-b) / (2 * a);
		cout << "one:" << x << endl;
	}
}

int main(int argc, char const *argv[])//见底部
{
	float a, b, c;
	cout << "print ax2+bx+c=0 a, b, c:" << endl;
	while (1)
	{
		cout << "print a:" << endl;	
		cin >> a;
		if (a)
		{
			break;
		}
		else
		{
			cout << "a is NOT 0" << endl;
		}
	}
	cout << "print b:" << endl;	
	cin >> b;
	cout << "print c:" << endl;	
	cin >> c;
	calculate(a, b, c);
	return 0;
}
// 问：
// int main(int argc, char* argv[])里的(int argc, char* argv[])是什么意思?为什么要用这个?

// 答1：
// 很多程序都是带参数运行的，比如WINDOWS命令行下的很多实用程序。参数增加了程序的灵活性。
// 你可以在“开始”->“运行”中输入cmd进入命令行。
// 比如一个叫做del的命令，（删除文件），其实就是del.exe，它带参数的，完整的命令格式可以是
// del readme.txt
// 这个命令将删除当前路径下的readme.txt文件（如果有的话）；
// 此时，运行的程序就是del.exe，而readme.txt就是它的参数，
// 假设del程序的main函数原型为 int main(int argc, char* argv[])，那么
// argc = 1，（1个参数）
// argv[0] = “readme.txt”（接收的字符串）；
// 假设一个程序的main函数不带任何参数，那么很显然，它仍可以运行，只是，不接收参数罢啦

// 答2：
// void main(int argc, char* argv[ ]) 
// 假设程序编译成为 cp.exe
// 然后在命令行中输入
// c:\>cp.exe doc1.txt doc2.txt
// 这行中有三个字符串分别为 cp.exe doc1.txt doc2.txt
// 则argc为3，即argc是命令行中参数的个数。
// char *argv[]为一个指像字符串的数组。
// argv[0]="cp.exe"
// argv[1]="doc1.txt"
// argv[2]="doc2.txt"
// 即命令行中各各字符串保存在 *argv[]中

// 归纳：
// 简单说，这两个就是用于接受参数和记录参数信息的。
// 因为在LINUX或DOS中， 使用命令后面一般都加上参数等，如：c:\>cp.exe doc1.txt doc2.txt
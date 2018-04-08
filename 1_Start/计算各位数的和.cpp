// 计算正整数各位数字的和
#include <iostream>
#include <cstring>
// #include <cmath>
#include <sstream>
using namespace std;


// integer	英[ˈɪntɪdʒə(r)]	美[ˈɪntɪdʒɚ]
// n.	整数;
// [例句]	A reversible covert communication method based on integer linear transform and sorting was proposed.
// 			描述了一种基于整数线性变换和排序的无损隐秘传输方法仿真。
// [其他]	复数：integers


int main(int argc, char const *argv[])
{
	string integer;
	cout << "input an +integer:" << endl;
	cin >> integer;
	int result = 0;
	int len = integer.length(); // 见末尾

	stringstream stream; // 声明一个stringstream变量
	// <sstream>库定义了三种类：istringstream、ostringstream和stringstream，分别用来进行流的输入、输出和输入输出操作。
	stream << integer; // 向stream中插入字符串
	int new_integer;
	stream >> new_integer; // 从stream中提取刚插入的字符串,并将其赋予变量new_integer完成字符串到int的转换
	// stream.clear(); // 同一stream进行多次转换应调用成员函数clear
	
	for (int i = len - 1; i >= 0; --i)
	{
		int temp;

		// 不能用pow(10, i); 比如i = 2 -> n = 99, 会丢失精度，影响结果
		int n = 1;
		for (int j = 0; j < i; ++j)
		{

			n *= 10;
		}

		temp = new_integer / n; // 得到最高位数
		result += temp;
		new_integer -= temp * n; // 删除最高位
	}
	cout << "sum:" << result << endl;
	return 0;
}
// C++ string类型的字符串长度获取的三种方法

// (1).	用string的成员方法length()获取字符串长度
// 		length()比较直观，表示的就是该字符串的长度。

// #include <string>  
// #include <iostream>  
// using namespace std;  
// int main()  
// {  
//     string str = "my string";  
//     cout << str.length() << endl;  
//     return 0;  
// }  

// (2).	用string的成员方法size()获取字符串长度
// 		size()表示的是string这个容器中的元素个数。如果使用过std::vector之类的容器的话，可以把string看做是一个vector<char> (这里只是举例，并不能等价)， char就是这个容器的元素类型。那么size()表示的就是这个vector(容器)中char的个数。

// #include <string>  
// #include <iostream>     
// using namespace std;  
// int main()  
// {  
//     string str = "Test string";  
//     cout << str.size() << endl;  
//     return 0;  
// } 
 
// (3).	用strlen获取字符串长度
// 		strlen同样也可以用于C++的string。但是需要用c_str()将C++ string转换为char*类型。

// #include <stdio.h>  
// #include <string>  
// using namespace std;  
// void main()  
// {  
// string str;  
// str = "Test string";  
// len = str.length();  
// printf("%d",len);  
// }

// 答案解法
// int func(int num)
// {
//     int s=0;
//     do
//     {
//         s+=num%10; // 得到最后一位数
//         num/=10; // 去掉最后一位数
//     }
//     while(num);
//     return(s);
// }
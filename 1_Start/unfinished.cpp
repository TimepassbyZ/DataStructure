//未完成的伪代码
#include <iostream>

using namespace std;

#ifndef STU_NUM
#define STU_NUM 50
#endif
#ifndef LES_NUM
#define LES_NUM 6
#endif

struct student
{
	int stu_no, cla_no;
	string name;
};
struct lesson
{
	int stu_no, les_no;
	float score;
};

float stu_ave (struct student a, int stu_no)
{
	int n;
	float sum = 0;
	if (a.stu_no == stu_no)// "="赋值；"=="判断相等的条件
	{
		sum = sum + a.score;
		n++;
	}
	return sum / n;
}

float les_ave (struct lesson a, int les_no)
{
	int n;
	float sum = 0;
	if (a.les_no == les_no)
	{
		sum = sum + a.score;
		n++;
	}
	return sum / n;
}

int main(int argc, char const *argv[])
{
	struct student a[STU_NUM];
	struct lesson b[LES_NUM];
	cout << "STUDENTS:" << endl;
	for (int i = 0; i < STU_NUM; ++i)
	{
		cout << "stu_no:" << a[i].stu_no << endl;
		cout << "stu_name:" << a[i].name << endl;
		cout << "cla_no:" << a[i].cla_no << endl;
		cout << "stu_ave:" << stu_ave(a, a[i].stu_no) << endl;
		cout << "-------------------------------------------------" << endl;
	}
	cout << "LESSONS:" << endl;
	for (int i = 0; i < LES_NUM; ++i)
	{
		cout << "les_no:" << b[i].les_no << endl;
		cout << "les_ave:" << les_ave(b, b[i].les_no) << endl;
		cout << "-------------------------------------------------" << endl;
	}

	return 0;
}
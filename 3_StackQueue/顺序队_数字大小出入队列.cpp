#include <iostream>

using namespace std;

#ifndef MaxSize
#define MaxSize 10
#endif

int main(int argc, char const *argv[])
{
	int x, q[MaxSize], rear = 0, front = 0; // 变量放外面
	while (1)
	{
		cout << "input an integer[>0,in;<0,out;=0,end]:" << endl;
		cin >> x;
		if (x > 0)
		{
			if ((rear + 1) % MaxSize == front)
			{
				cout << "full!" << endl;
				return -1;
			}
			else
			{		
				rear = (rear + 1) % MaxSize;
				q[rear] = x;
				cout << x << " in success!" << endl;
			}
		}
		else if (x < 0)
		{
			if (rear == front)
			{
				cout << "empty!" << endl;
				return -1;
			}
			else
			{
				front = (front + 1) % MaxSize;
				cout << q[front] << " out success!" << endl;
			}
		}
		else
		{
			// cout << "input over, display queue:" << endl;
			// if (rear == front)
			// {
			// 	cout << "NONE" << endl;
			// }
			// else
			// {
			// 	front = (front + 1) % MaxSize;
			// 	while (q[front] != 0)
			// 	{
			// 		cout << q[front] << " | ";
			// 		front = (front + 1) % MaxSize;
			// 	}
			// 	return 0;
			// }
			cout << "end!" << endl;
			return 0;
		}
	} // while1 END
	return 0;
}
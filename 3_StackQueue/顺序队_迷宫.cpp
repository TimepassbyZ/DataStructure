#include <iostream>

using namespace std;

#ifndef MaxSize
#define MaxSize 100
#endif

// 假设为8x8的迷宫(共10x10大小)
#ifndef M
#define M 8
#endif

#ifndef N
#define N 8
#endif

typedef struct
{
	int x, y; // 方块位置
	int pre; // 本路径中上一方块在队列中的下标
} Box;

typedef struct
{
	Box data[MaxSize];
	int front, rear;
} QuType;
// 出队时不会删除队列元素，还要进行迷宫路径的输出

int maze[M + 2][N + 2] = // MxN的迷宫，四周为墙壁；1为墙壁，0为可走
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

void displaypath (QuType qu, int front)
{
	cout << "\n";
	// 反向找最短路径，将该路径方块的pre设为-1
	int k = front;
	do
	{
		int j = k;
		k = qu.data[k].pre;
		qu.data[j].pre = -1;
	} while (k != 0);
	cout << "path display:" << endl;
	k = 0;
	int ns = 0; // 计数用
	while (k < MaxSize)
	{
		if (qu.data[k].pre == -1)
		{
			ns++;
			cout << "\t(" << qu.data[k].x << "," << qu.data[k].y << ")";
			if (ns % 5 == 0)
			{
				cout << "\n"; // 每输出五个方块换一行显示
			}
		}
		k++;
	}
	cout << "\n";
}

// 路径为(sx, sy)->(ex, ey)
bool path (int sx, int sy, int ex, int ey)
{
	// 定义顺序队
	QuType qu;
	qu.front = qu.rear = -1;

	// (sx, sy)进队
	qu.rear++;
	qu.data[qu.rear].x = sx;
	qu.data[qu.rear].y = sy;
	qu.data[qu.rear].pre = -1;
	maze[sx][sy] = -1; // 变为不可走，以免重复

	int find = 0, row, col;
	while (qu.front != qu.rear && !find)
	{
		// 出队
		qu.front++;
		row = qu.data[qu.front].x;
		col = qu.data[qu.front].y;

		// 找到出口
		if (row == ex && col == ey)
		{
			find = 1;
			displaypath(qu, qu.front);
			return true;
		}

		for (int i = 0; i < 4; ++i)
		{
			switch (i)
			{
				case 0: // 向上走，行号-1，列号不变
				{
					row = qu.data[qu.front].x - 1;
					col = qu.data[qu.front].y;
					break;
				}
				case 1: // 向右走，行号不变，列号+1
				{
					row = qu.data[qu.front].x;
					col = qu.data[qu.front].y + 1;
					break;
				}
				case 2: // 向下走，行号+1，列号不变
				{
					row = qu.data[qu.front].x + 1;
					col = qu.data[qu.front].y;
					break;
				}
				case 3: // 向左走，行号不变，列号-1
				{
					row = qu.data[qu.front].x;
					col = qu.data[qu.front].y - 1;
					break;
				}
			} // switch END
			if (maze[row][col] == 0)
			{
				// 插入队列
				qu.rear++;
				qu.data[qu.rear].x = row;
				qu.data[qu.rear].y = col;
				qu.data[qu.rear].pre = qu.front; // 指向上一方块
				maze[row][col] = -1;
			}
		} // for END
	} // while END
	return false;
}

int main(int argc, char const *argv[])
{
	if (!path(1,1,M,N)) // 从左上走到右下
	{
		cout << "No path!!!" << endl;
	}
	return 0;
}
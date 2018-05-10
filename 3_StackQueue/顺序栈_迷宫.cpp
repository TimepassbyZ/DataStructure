// 穷举法
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
// maze	英[meɪz]	美[mez]
// n.	迷宫; 迷惑; 错综复杂; 迷宫图;
// vt.	使困惑; 使混乱; 迷失;
// [例句]	The palace has extensive gardens, a maze, and tennis courts.
// 			这座宫殿有几座大花园、一处迷宫和几个网球场。
// [其他]	第三人称单数：mazes 复数：mazes 现在分词：mazing 过去式：mazed 过去分词：mazed
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

// 定义方块类型
typedef struct
{
	int x; // 行号
	int y; // 列号
	int di; // 下一个可走的相邻方块的方位号
			// 0表示上，1表示右，2表示下，3表示左，-1表示不可走
} Box;

// 定义顺序栈类型
typedef struct
{
	Box data[MaxSize];
	int top;
} StType;

// 路径为(sx, sy)->(ex, ey)
bool path (int sx, int sy, int ex, int ey)
{
	// 初始化栈
	StType st;
	st.top = -1;

	// 初始方块进栈
	st.top++;
	st.data[st.top].x = sx;
	st.data[st.top].y = sy;
	st.data[st.top].di = -1;
	maze[sx][sy] = -1; // 一个元素进栈，对应元素值改为-1(变为不可走的相邻方块)

	int row, col, dii;
	while (st.top > -1)
	{
		// 取栈顶方块
		row = st.data[st.top].x;
		col = st.data[st.top].y;
		dii = st.data[st.top].di;

		if (row == ex && col == ey) // 到达出口，输出路径
		{
			cout << "maze path:" << endl;
			for (int i = 0; i <= st.top; ++i)
			{
				cout << "\t(" << st.data[i].x << "," << st.data[i].y << ")";
				if ((i + 1) % 5 == 0)
				{
					cout << "\n"; // 每输出五个方块换一行显示
				}
			}
			cout << "\n";
			return true;
		}

		int find = 0;
		while (dii < 4 && find == 0) // 找下一个可走方块
		{
			dii++;
			switch (dii)
			{
				case 0: // 向上走，行号-1，列号不变
				{
					row = st.data[st.top].x - 1;
					col = st.data[st.top].y;
					break;
				}
				case 1: // 向右走，行号不变，列号+1
				{
					row = st.data[st.top].x;
					col = st.data[st.top].y + 1;
					break;
				}
				case 2: // 向下走，行号+1，列号不变
				{
					row = st.data[st.top].x + 1;
					col = st.data[st.top].y;
					break;
				}
				case 3: // 向左走，行号不变，列号-1
				{
					row = st.data[st.top].x;
					col = st.data[st.top].y - 1;
					break;
				}
			} // switch END
			if (maze[row][col] == 0)
			{
				find = 1; // 标记为找到下一个可走方块
			}
		} // while找可走方块 END

		if (find == 1) // 找到下一可走方块时
		{
			st.data[st.top].di = dii; // 修改原栈顶的可走方位

			// 下一可走方块进栈
			st.top++;
			st.data[st.top].x = row;
			st.data[st.top].y = col;
			st.data[st.top].di = -1;
			maze[row][col] = -1; // 避免重复走到该方块
		}
		else // 没找到下一可走方块时
		{
			maze[st.data[st.top].x][st.data[st.top].y] = 0; // 重新把-1该回到0
			st.top--; // 该不可走的方块出栈
		}
	} // while取栈顶元素 END
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
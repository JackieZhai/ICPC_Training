/**
练习题：Inner Vertices_POJ 3109
    坐标范围是10^9，但只有10^5个点，所以用坐标离散化建BIT
    双BIT：
    1、维护初始个数
    2、保存累加值
    解决无法高效更新区间的值的痛点
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100000 + 16
typedef long long LL;

LL bit0[MAX_N], bit1[MAX_N];	// 双BIT实现O(logn)区间加法
int N, X[MAX_N], Y[MAX_N];
vector<int> line[MAX_N];	// 每个黑子构成的一条条水平线，y坐标作为下标
bool visited[MAX_N];		// 是否已经算过了

// 求和sum{a[t], 0 <= t <= i}
LL sum(LL *b, int i)
{
	int s = 0;
	while (i > 0)
	{
		s += b[i];
		i -= (i & -i);
	}
	return s;
}
// 求和a[from, to)
LL sum(LL* bit, int from, int to)
{
	return sum(bit, to - 1) - sum(bit, from - 1);
}
// 执行 a[i] += v
void add(LL *b, int i, LL v)
{
	while (i <= MAX_N)
	{
		b[i] += v;
		i += (i & -i);
	}
}

// 双BIT进行重载
//[0,n]
LL sum(int i)
{
	return sum(bit1, i) * i + sum(bit0, i);
}
//(from, to]
LL sum(int from, int to)
{
	return sum(to) - sum(from);
}
// [from, to]
void add(int from, int to, LL x)
{
	add(bit0, from, -x * (from - 1));
	add(bit1, from, x);
	add(bit0, to, x * to);
	add(bit1, to, -x);
}

// 压缩坐标，将坐标的值变成“这是第几种值”，返回一共有几种坐标
// x为坐标数组，长度为N
int compress(int *p)
{
	vector<int> ps(N);

	for (int i = 0; i < N; ++i)
	{
		ps[i] = p[i];
	}

	sort(ps.begin(), ps.end());
	ps.erase(unique(ps.begin(), ps.end()), ps.end());
	for (int i = 0; i < N; ++i)
	{
		p[i] = 1 + distance(ps.begin(), lower_bound(ps.begin(), ps.end(), p[i]));	// 此处加1为了防止 i += (i & -i); 永远为0
	}
	return ps.size();
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", X + i, Y + i);
	}
	int w = compress(X);
	int h = compress(Y);

	for (int i = 0; i < N; ++i)
	{
		line[Y[i]].push_back(X[i]);	// 一条条扫描线
	}

	LL result = N;
	for (int y = 1; y <= h; ++y)
	{
		// 对每条扫描线，计算上面空白点的个数
		vector<int>& xs = line[y];	// 纵坐标为y的那些点的横坐标，一条扫描线
		sort(xs.begin(), xs.end());

		for (vector<int>::iterator i = xs.begin(); i != xs.end(); ++i)
		{
			int x = *i;
			LL s = sum(x - 1, x);	// 横坐标为x的空白点个数

			if (visited[x])
			{
				result += s;		// 就是要染色的像素点
			}
			else
			{
				visited[x] = true;
			}
			add(bit0, x, -s);		// 等同于add(x, x, -s);即对count[x] -= s；这是一个复位操作，为下次统计做准备
			if (i + 1 != xs.end())
			{
				// 到下一个黑点之间空白点的个数
				// 这两个分支合并起来就是 add(x + 1, next_x - 1, 1);的意思
				if (x + 1 < *(i + 1) - 1)			// 下一个黑子
				{
					add(x + 1, *(i + 1) - 1, 1);	// 遇到了空白
				}
				else if (x + 1 == *(i + 1) - 1)
				{
					add(bit0, x + 1, 1);			// 遇到了空白,此时等同于add(x + 1, x + 1, 1);
				}
			}
		}
	}
	cout << result << endl;



	return 0;
}

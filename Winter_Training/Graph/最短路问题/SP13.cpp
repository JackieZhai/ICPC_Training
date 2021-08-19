/*
练习题：Mr.Rito Post Office_AOJ 2200 
	先单独考虑只走水路或旱路的情况，用warshall_floyd求出任意两点间的最短路。
	然后定义 dp[i][k] := 已经去了第i个镇子后，船停在第k个镇子里的状态下的最短路。
	然后ijk三重循环更新dp，其中递推公式思路：
	在推导ik的时候，定义一个中间状态j表示先从i-1走旱路到j，
	然后从j走水路去k，最后从k走旱路去i，于是就把船扔在了k。
	如果j==k的时候就不需要绕圈子了。
*/

#include <iostream>
#include <algorithm>
using namespace std;
 
#define INF 1e8
#define MAX_V 256
#define MAX_R 1024
int dl[MAX_V][MAX_V];	//d[u][v]表示边e=(u,v)的权值，不存在的时候等于无穷大或者d[i][i] = 0
int ds[MAX_V][MAX_V];
int z[MAX_R];
int dp[MAX_R][MAX_V];	//dp[i][j] := 已经去了第i个镇子后，船停在第j个镇子里
int N;					//顶点数


int main()
{
 
	int M;
	while (cin >> N >> M , N || M)
	{

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i == j)
				{
					dl[i][j] = ds[i][j] = 0;
				}
				else
				{
					dl[i][j] = ds[i][j] = INF;
				}
			}
		}
 
		for (int i = 0; i < M; ++i)
		{
			int x, y, t;
			char s;
			cin >> x >> y >> t >> s;
			--x; --y;
			if (s == 'L')
			{
				dl[x][y] = min(dl[x][y], t);
				dl[y][x] = dl[x][y];
			}
			else
			{
				ds[x][y] = min(ds[x][y], t);
				ds[y][x] = ds[x][y];
			}
		}
		
		int R;
		cin >> R;
		for (int i = 0; i < R; ++i)
		{
			cin >> z[i];
			--z[i];
		}
 
		// warshall_floyd
		for (int k = 0; k < N; ++k)
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					dl[i][j] = min(dl[i][j], dl[i][k] + dl[k][j]);
					ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
				}
			}
		}
		
 
		// dp
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				dp[i][j] = INF;
			}
		}
		for (int i = 0; i < N; ++i)
		{
			// 去了首个镇子后，船放在第i个镇子里
						// 坐船去	 // 坐11路车回来
			dp[0][i] = ds[z[0]][i] + dl[i][z[0]];
		}
		for (int i = 1; i < R; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				for (int k = 0; k < N; ++k)
				{
					if (j != k)
					{
						//                          i-1站     + 从i-1站走旱路去j+ 从j走水路去k+从k走旱路去i
						dp[i][k] = min(dp[i][k], dp[i - 1][j] + dl[z[i - 1]][j] + ds[j][k] + dl[k][z[i]]);
					}
					else
					{
						// j == k                   i-1站     + 从i-1站走旱路去i
						dp[i][j] = min(dp[i][j], dp[i - 1][j] + dl[z[i - 1]][z[i]]);
					}
				}
			}
		}
 
		cout << *min_element(dp[R - 1], dp[R - 1] + N) << endl;
	}
 
	return 0;
}



/*
��ϰ�⣺Mr.Rito Post Office_AOJ 2200 
	�ȵ�������ֻ��ˮ·��·���������warshall_floyd����������������·��
	Ȼ���� dp[i][k] := �Ѿ�ȥ�˵�i�����Ӻ󣬴�ͣ�ڵ�k���������״̬�µ����·��
	Ȼ��ijk����ѭ������dp�����е��ƹ�ʽ˼·��
	���Ƶ�ik��ʱ�򣬶���һ���м�״̬j��ʾ�ȴ�i-1�ߺ�·��j��
	Ȼ���j��ˮ·ȥk������k�ߺ�·ȥi�����ǾͰѴ�������k��
	���j==k��ʱ��Ͳ���Ҫ��Ȧ���ˡ�
*/

#include <iostream>
#include <algorithm>
using namespace std;
 
#define INF 1e8
#define MAX_V 256
#define MAX_R 1024
int dl[MAX_V][MAX_V];	//d[u][v]��ʾ��e=(u,v)��Ȩֵ�������ڵ�ʱ�������������d[i][i] = 0
int ds[MAX_V][MAX_V];
int z[MAX_R];
int dp[MAX_R][MAX_V];	//dp[i][j] := �Ѿ�ȥ�˵�i�����Ӻ󣬴�ͣ�ڵ�j��������
int N;					//������


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
			// ȥ���׸����Ӻ󣬴����ڵ�i��������
						// ����ȥ	 // ��11·������
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
						//                          i-1վ     + ��i-1վ�ߺ�·ȥj+ ��j��ˮ·ȥk+��k�ߺ�·ȥi
						dp[i][k] = min(dp[i][k], dp[i - 1][j] + dl[z[i - 1]][j] + ds[j][k] + dl[k][z[i]]);
					}
					else
					{
						// j == k                   i-1վ     + ��i-1վ�ߺ�·ȥi
						dp[i][j] = min(dp[i][j], dp[i - 1][j] + dl[z[i - 1]][z[i]]);
					}
				}
			}
		}
 
		cout << *min_element(dp[R - 1], dp[R - 1] + N) << endl;
	}
 
	return 0;
}



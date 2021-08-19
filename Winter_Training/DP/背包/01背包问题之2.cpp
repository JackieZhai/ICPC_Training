/*
01背包问题之2： 
	附：
	之1的限制条件：1<=n<=100, 1<=wi,vi<=100, 1<=W<=10000;
	之2的限制条件：1<=n<=100, 1<=wi<=1000000, 1<=vi<=100, 1<=W<=1000000000;
	所以定义dp[i+1][j]为前i个物品中挑选价值总和为j时总重量的最小值(不存在为INF)。 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=107, MAX_V=107, INF=0x3f3f3f3f;//略大于1e9 

int n, W;
int w[MAX_N], v[MAX_N]; 
int dp[MAX_N][MAX_N*MAX_V];

void solve()
{
	fill(dp[0], dp[0]+MAX_N*MAX_V, INF);
	dp[0][0]=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<MAX_N*MAX_V; j++)
			if(j<v[i])
				dp[i+1][j]=dp[i][j];
			else
				dp[i+1][j]=min(dp[i][j], dp[i][j-v[i]]+w[i]);
	
	int res=0;
	for(int i=0; i<MAX_N*MAX_V; i++)
		if(dp[n][i]<=W)
			res=i;
	printf("%d\n", res);
}

int main()
{
	scanf("%d%d", &n, &W);
	for(int i=0; i<n; i++)
		scanf("%d%d", &w[i], &v[i]);
	
	solve();
	
	return 0;
}



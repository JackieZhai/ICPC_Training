/*
多重集组合数问题：
	有n种物品，第i种物品有ai个。不同种类的物品可以互相区分但相同种类的不行，
	从其中取出m个，有多少种取法？求方法数模M的值。 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[MAX_N];

int dp[MAX_N][MAX_M];

void solve()
{
	//一个都不取得方法总是只有一种 
	for(int i=0; i<=n; i++)
		dp[i][0]=1;
	for(int i=0; i<n; i++)
		for(int j=1; j<=m; j++)
			if(j-1-a[i+1]>=0)
			//在有取余的情况下，要避免减法运算的结果出现负数 
				dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i+1]]+M)%M;
			else
				dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%M;
}

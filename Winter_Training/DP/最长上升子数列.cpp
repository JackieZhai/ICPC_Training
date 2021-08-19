/*
最长上升子序列(LIS, Longest Increasing Subsequence)问题： 
	solve1()：定义dp[i]为以ai为末尾的最长上升子数列的长度，O(n^2)；
	solve2()：定义dp[i]为长度为i+1的上升子数列中末尾元素的最小值；
		由于知道这种dp[]除了INF之外是单调递增的，可以利用二分搜索得到更快的O(nlogn)。 
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1007, INF=0x3f3f3f3f;

int n;
int a[MAX_N];

int dp[MAX_N];

void solve1()
{
	int res=0;
	for(int i=0; i<n; i++)
	{
		dp[i]=1;
		for(int j=0; j<i; j++)
		{
			if(a[j]<a[i])
				dp[i]=max(dp[i], dp[j]+1);
		}
		res=max(res, dp[i]);
	}
	printf("%d\n", res);
}

void solve2()
{
	fill(dp, dp+n, INF); //INF 改为 -1 变为LDS 
	for(int i=0; i<n; i++)
	{
		*lower_bound(dp, dp+n, a[i]) = a[i]; //, greater<int>() 变为LDS; 改为upper变成最长不下降。 
	}
	printf("%d\n", lower_bound(dp, dp+n, INF)-dp); //, greater<int>(); INF 改为 -1 变为LDS 
}


int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	//solve1();
	solve2();
	
	return 0;
}



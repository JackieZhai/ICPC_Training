#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=50000, INF=0x3f3f3f3f;

int n;
int a[MAX_N];

int dp[MAX_N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	//LIS
	fill(dp, dp+n, INF); //INF 改为 -1 变为LDS 
	for(int i=0; i<n; i++)
	{
		*lower_bound(dp, dp+n, a[i]) = a[i]; //, greater<int>() 变为LDS; 改为upper变成最长不下降。 
	}
	printf("%d\n", lower_bound(dp, dp+n, INF)-dp); //, greater<int>(); INF 改为 -1 变为LDS 
	
	
	
	return 0;
}

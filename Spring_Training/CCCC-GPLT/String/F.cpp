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
	fill(dp, dp+n, INF); //INF ��Ϊ -1 ��ΪLDS 
	for(int i=0; i<n; i++)
	{
		*lower_bound(dp, dp+n, a[i]) = a[i]; //, greater<int>() ��ΪLDS; ��Ϊupper�������½��� 
	}
	printf("%d\n", lower_bound(dp, dp+n, INF)-dp); //, greater<int>(); INF ��Ϊ -1 ��ΪLDS 
	
	
	
	return 0;
}

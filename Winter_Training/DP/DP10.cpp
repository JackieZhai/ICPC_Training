/*
��ϰ�⣺Bridging signals_POJ 1631 
	����˫�α�����(DP9Ҳһ��)�����԰�һ���α�����/�������У�����һ���α�������/�½������С� 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f;
int p;
int dp[40007];
int a[40007]; 

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d",&p);
		for(int i=0; i<p; i++)
			scanf("%d", &a[i]);
		
//		�ᳬʱ��dp�ⷨ:
//		for(int i=0; i<p; i++)
//			dp[i]=1;
//		
//		for(int i=1;i<p; i++)
//		{
//			for(int j=0; j<i; j++)
//			{
//				if(a[j]<a[i])
//				{
//					dp[i]=max(dp[i], dp[j]+1);
//				}
//			}
//		}
//		int ans=0;
//		for(int i=0; i<p; i++)
//			if(ans<dp[i])
//				ans=dp[i];
//		printf("%d\n", ans);


//      LIS
		fill(dp, dp+p, INF); 
		for(int i=0; i<p; i++)
		{
			*lower_bound(dp, dp+p, a[i]) = a[i]; 
		}
		printf("%d\n", lower_bound(dp, dp+p, INF)-dp);
		
		
	}
	
	
	return 0;
}

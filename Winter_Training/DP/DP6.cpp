/*
��ϰ�⣺Coins_POJ 1742 
	dp���ƣ�
	dp[i]����i��ֵ���Բ�����ǡ����ɣ� 
	count[i]����ȡi��ֵʱ����Ӳ���õ������� 
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;
int a[107], c[107];
bool dp[100007]; 
int count[100007];

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}
		for(int i=0; i<n; i++)
		{
			scanf("%d", &c[i]);
		}
		
		fill(dp, dp+m+1, false);
		dp[0]=true;
		int ans=0;
		for(int i=0; i<n; i++)
		{
			memset(count, 0, sizeof(count));
			for(int num=a[i]; num<=m; num++)
			{
				if(dp[num]==false&&dp[num-a[i]]==true&&count[num-a[i]]+1<=c[i])
				{
					dp[num]=true;
					ans++;
					count[num]=count[num-a[i]]+1;
				}
			}	
		}
		
		printf("%d\n", ans);
		
	}
	
	
	return 0;
}

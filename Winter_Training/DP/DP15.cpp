/*
加练题：Cash Machine_POJ 1276
	与DP6类似， 
	dp[i]代表i的值可以不可以恰好组成； 
	count[i]代表取i的值时此种面值用的数量。
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int cash;
int n;
int a[17], c[17];
bool dp[100007]; 
int count[100007];


int main()
{
	while(scanf("%d%d", &cash, &n)!=EOF)
	{
		
		for(int i=0; i<n; i++)
			scanf("%d%d", &c[i], &a[i]);
			
		if(cash==0||n==0)
		{
			printf("0\n");
			continue;
		}
		
		fill(dp, dp+cash+1, false);
		dp[0]=true;
		for(int i=0; i<n; i++)
		{
			memset(count, 0, sizeof(count));
			for(int num=a[i]; num<=cash; num++)
			{
				if(dp[num]==false&&dp[num-a[i]]==true&&count[num-a[i]]+1<=c[i])
				{
					dp[num]=true;
					count[num]=count[num-a[i]]+1;
				}
			}
		}
		
		for(int i=cash; ; i--)
		{
			if(dp[i]==true)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	
	return 0;
}

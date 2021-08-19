/*
加练题：Dividing_POJ 1014
	类似于DP15、DP6。 
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int c[7];
bool dp[60007];
int count[60007];

int main()
{
	int kase=0;
	while(scanf("%d%d%d%d%d%d", &c[1], &c[2], &c[3], &c[4], &c[5], &c[6])!=EOF)
	{
		kase++;
		if(c[1]==0&&c[2]==0&&c[3]==0&&c[4]==0&&c[5]==0&&c[6]==0)
			break;
		printf("Collection #%d:\n", kase);
		
		int total=0;
		for(int i=1; i<=6; i++)
		{
			total+=i*c[i];
		}
		if(total%2==1)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		else
		{
			total/=2;
		}
		
		fill(dp, dp+total+1, false);
		dp[0]=true;
		for(int i=1; i<=6; i++)
		{
			memset(count, 0, sizeof(count));
			for(int num=i; num<=total; num++)
			{
				if(dp[num]==false&&dp[num-i]==true&&count[num-i]+1<=c[i])
				{
					dp[num]=true;
					count[num]=count[num-i]+1;
				}
			}
		}
		if(dp[total]==true)
		{
			printf("Can be divided.\n\n");
		}
		else
		{
			printf("Can't be divided.\n\n");
		}
	}
	
	
	return 0;
}

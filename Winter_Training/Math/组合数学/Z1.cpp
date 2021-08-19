/*
加练题：Joseph_POJ 1012
	经典的约瑟夫问题，找出递推式：
	dp[i]表示为第i轮杀掉谁， 
	dp[i]=(dp[i-1]+m-1)%(n-i+1).
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int J[14];
int dp[29];

int main()
{
	for(int k=1; k<14; k++)
	{
		int total=2*k;
		int m=1;
		for(int i=1; i<=k; i++)
		{
			dp[i]=(dp[i-1]+m-1)%(total-i+1);
			if(dp[i]<=k-1)
			{
				m++;
				i=0;
			}
		}
		J[k]=m;
	}
	
	int k;
	while(scanf("%d", &k)!=EOF)
	{
		if(k==0)
			break;
			
		printf("%d\n", J[k]);
	}
	
	return 0;
}

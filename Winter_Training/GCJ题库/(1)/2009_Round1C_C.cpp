/*
	dp[i][j]表示为ij开区间内的囚犯释放需要的最少金币 
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_Q=107, INF=0x3f3f3f3f;
int P, Q, A[MAX_Q];
int dp[MAX_Q][MAX_Q];

int main()
{
//	freopen("C-small-practice.in", "r", stdin);
//	freopen("C-small-practice.out", "w", stdout);
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++)
	{
		scanf("%d%d", &P, &Q);
		for(int i=1; i<=Q; i++)
			scanf("%d", &A[i]);
		
		A[0]=0;
		A[Q+1]=P+1;
		
		memset(dp, 0, sizeof(dp));
		for(int q=0; q<=Q; q++)
			dp[q][q+1]=0;
		
		for(int w=2; w<=Q+1; w++)
			for(int i=0; i+w<=Q+1; i++)
			{
				int j=i+w;
				int t=INF;
				for(int k=i+1; k<j; k++)
				{
					t=min(t, dp[i][k]+dp[k][j]);
				}
				
				dp[i][j]=t+A[j]-A[i]-2;
			}	
	
	
		printf("Case #%d: %d\n", kase, dp[0][Q+1]);	
	}
	
	
	return 0;	
}

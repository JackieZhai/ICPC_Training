/*
¡∑œ∞Ã‚£∫Cow Bowling_POJ 3176 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=357;
int dp[MAX_N][MAX_N];
int a[MAX_N][MAX_N];

int main()
{
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<=i; j++)
			scanf("%d", &a[i][j]);
	
	dp[0][0]=a[0][0];
	for(int i=1; i<N; i++)
		for(int j=0; j<=i; j++)
		{
			if(j==0)
				dp[i][j]=dp[i-1][j]+a[i][j];
			else if(j==i)
				dp[i][j]=dp[i-1][j-1]+a[i][j];
			else
				dp[i][j]=max(dp[i-1][j]+a[i][j], dp[i-1][j-1]+a[i][j]);
		}
	
	int ans=0;
	for(int i=0; i<N; i++)
		if(ans<dp[N-1][i])
			ans=dp[N-1][i];	
	
	printf("%d\n", ans);
	
	return 0;
}

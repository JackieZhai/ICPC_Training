/*
¡∑œ∞Ã‚£∫Apple Catching_POJ 2385
	dpµ›Õ∆£∫
	dp[T][W]°£ 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_T=1007, MAX_W=37;
int T, W;
int dp[MAX_T][MAX_W];
int a[MAX_T];

int main()
{
	scanf("%d%d", &T, &W);
	for(int i=1; i<=T; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
	}
	dp[1][0]=(a[1]==0);
	dp[1][1]=(a[1]==1);
	for(int i=2; i<=T; i++)
		dp[i][0]=dp[i-1][0]+(a[i]==0);
	for(int i=2; i<=T; i++)
	{
		for(int j=1; j<=i&&j<=W; j++)
		{
			dp[i][j]=max(dp[i-1][j]+(a[i]==j%2), dp[i-1][j-1]+(a[i]==j%2));
		}
	}
	printf("%d\n", dp[T][W]);
	
	return 0;
}
